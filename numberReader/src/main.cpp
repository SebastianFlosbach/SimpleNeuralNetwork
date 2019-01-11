#include "Network.h"
#include "IdxReader.h"
#include "EvolutionHandler.h"

#include <iostream>
#include <cmath>

typedef unsigned char Uint8;

int main( int argc, char* argv[] ) {

	IdxReader idxImages( "train-images.idx" );
	IdxReader idxLabels( "train-labels.idx" );

	auto net = std::make_unique<Network>();

	net->addLayer( 3 );
	net->addNeuronToLayer( 0, 28 * 28 );
	net->addNeuronToLayer( 1, 16 );
	net->addNeuronToLayer( 2, 10 );
	net->connectAllLayers();

	TestData tData( net->inputSize(), net->outputSize() );
	
	EvolutionHandler eHandler( std::move( net ) );

	TestData tData( 28 * 28, 10 );
	
	return 0;
}