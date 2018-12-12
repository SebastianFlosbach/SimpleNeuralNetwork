#pragma once
#include "Network.h"

typedef unsigned int Uint32;

class EvolutionHandler {
	NetworkPtr bestNetwork_;


public:
	EvolutionHandler( NetworkPtr& network ) : bestNetwork_( std::move( network ) ) {
	}

	void addTestData();
	void evolveNextGeneration( Uint32 generationSize );
};