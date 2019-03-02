#include "EvolutionHandler.h"

#include <atomic>
#include <mutex>
#include <iostream>
#include <string>

void EvolutionHandler::evolveNextGeneration( Uint32 generationSize, float chance, float range ) {
	Network currentBestNetwork;
	Fitness currentBestFitness( bestNetwork_.outputSize() );

	std::mutex mtxSync;

	std::vector<std::thread> threads( threadCount_ );

	auto generationThreadSize = generationSize / threadCount_;

	auto start = std::chrono::high_resolution_clock::now();

	for ( size_t t = 0; t < threadCount_; t++ ) {
		if ( t == threadCount_ - 1 ) {
			generationThreadSize = generationThreadSize + ( generationSize % threadCount_ );
		}

		threads[t] = std::thread( [this, &generationThreadSize, &chance, &range, &currentBestNetwork, &currentBestFitness, &mtxSync]() {
			for ( size_t i = 0; i < generationThreadSize; i++ ) {
				auto currentNetwork = bestNetwork_.copyAndMutate( chance, range );
				Fitness currentFitness( currentNetwork.outputSize(), 0.f );

				for ( size_t j = 0; j < testData_.size(); j++ ) {
					auto inputData = testData_.getInput( j );
					auto outputData = testData_.getOutput( j );

					currentNetwork.setInput( inputData );
					auto actualOutput = currentNetwork.getOutput();

					currentFitness += calculateFitness( actualOutput, outputData );
				}

				std::lock_guard<std::mutex> syncLock( mtxSync );
				if ( currentFitness < currentBestFitness ) {
					currentBestNetwork = std::move( currentNetwork );
					currentBestFitness = std::move( currentFitness );
				}
			}
		} );
	}

	for ( size_t t = 0; t < threadCount_; t++ ) {
		threads[t].join();
	}

	auto end = std::chrono::high_resolution_clock::now();

	std::cout << "Threads: " << threadCount_ << std::endl;
	std::cout << "Time: " << std::chrono::duration_cast<std::chrono::seconds>(end - start).count() << "s" << std::endl;

	if ( currentBestFitness < bestFitness_ ) {
		bestNetwork_ = std::move( currentBestNetwork );
		bestFitness_ = std::move( currentBestFitness );
		std::cout << "New best fitness: " << std::to_string( this->getFitness().getDifference() ) << std::endl;
	} else {
		std::cout << "No new best fitness, closest was: " << std::to_string( currentBestFitness.getDifference() ) << std::endl;
	}
}

Fitness EvolutionHandler::calculateFitness( const std::vector<float>& actualOutput, const std::vector<float>& desiredOutput ) const {
	if ( actualOutput.size() != desiredOutput.size() ) {
		throw std::invalid_argument( std::string( __FUNCTION__ ) + std::string( ": actualOutput and desiredOutput hava a different size" ) );
	}

	std::vector<float> diff( actualOutput.size() );

	for ( size_t i = 0; i < actualOutput.size(); i++ ) {
		diff[i] = abs( desiredOutput[i] - actualOutput[i] );
	}

	return Fitness( std::move( diff ) );
}
