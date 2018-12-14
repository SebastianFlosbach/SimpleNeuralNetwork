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
			
		}
	}
}

float EvolutionHandler::calculateFitness( std::vector<float> output, std::vector<float> desiredOutput ) const {

}
