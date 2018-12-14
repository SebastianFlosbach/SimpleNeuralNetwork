#include "EvolutionHandler.h"

void EvolutionHandler::evolveNextGeneration( Uint32 generationSize, float chance, float range ) {
	for ( size_t i = 0; i < generationSize; i++ ) {
		auto currentNetwork = bestNetwork_->copyAndMutate( chance, range );

		for ( size_t j = 0; j < testData_.size(); j++ ) {
			auto inputData = testData_.getInput( i );
			auto outputData = testData_.getOutput( i );

			currentNetwork->reset();
			currentNetwork->setInput( inputData );
			currentNetwork->operate();
			auto actualOutput = currentNetwork->getOutput();
			
			auto currentFitness = calculateFitness( actualOutput, outputData );

			if ( currentFitness < bestFitness_ ) {
				bestNetwork_ = std::move( currentNetwork );
				bestFitness_ = std::move( currentFitness );
			}
		}
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
