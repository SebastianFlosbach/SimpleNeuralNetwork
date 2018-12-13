#include "EvolutionHandler.h"

void EvolutionHandler::evolveNextGeneration( Uint32 generationSize, float chance, float range ) {
	for ( size_t i = 0; i < generationSize; i++ ) {
		auto currentNetwork = bestNetwork_->copyAndMutate( chance, range );

		for ( size_t j = 0; j < testData_.size(); j++ ) {

		}
	}
}