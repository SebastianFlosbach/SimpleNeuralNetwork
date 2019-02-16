#include "EvolutionHandler.h"

void EvolutionHandler::evolveNextGeneration( Uint32 generationSize, float chance, float range ) {
	NetworkPtr currentBestNetwork;
	Fitness currentBestFitness( bestNetwork_->outputSize() );

	for ( size_t i = 0; i < generationSize; i++ ) {
		auto currentNetwork = bestNetwork_->copyAndMutate( chance, range );
		Fitness currentFitness( currentNetwork->outputSize(), 0.f );

		for ( size_t j = 0; j < testData_.size(); j++ ) {
			auto inputData = testData_.getInput( j );
			auto outputData = testData_.getOutput( j );

			currentNetwork->reset();
			currentNetwork->setInput( inputData );
			currentNetwork->operate();
			auto actualOutput = currentNetwork->getOutput();
			
			currentFitness += calculateFitness( actualOutput, outputData );
		}

		if ( currentFitness <= currentBestFitness ) {
			currentBestNetwork = std::move( currentNetwork );
			currentBestFitness = std::move( currentFitness );
		}
	}

	if ( currentBestFitness <= bestFitness_ ) {
		bestNetwork_ = std::move( currentBestNetwork );
		bestFitness_ = std::move( currentBestFitness );
	}
}

Fitness EvolutionHandler::calculateFitness( std::vector<float> actualOutput, std::vector<float> desiredOutput ) const {
	if ( actualOutput.size() != desiredOutput.size() ) {
		throw std::invalid_argument( std::string( __FUNCTION__ ) + std::string( ": actualOutput and desiredOutput hava a different size" ) );
	}

	std::vector<float> diff( actualOutput.size() );

	for ( size_t i = 0; i < actualOutput.size(); i++ ) {
		diff[i] = abs( desiredOutput[i] - actualOutput[i] );
	}

	return Fitness( std::move( diff ) );
}
