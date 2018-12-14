#include "Network.h"
#include "idxreader.h"
#include "EvolutionHandler.h"

#include <iostream>
#include <cmath>

typedef unsigned char Uint8;

int main( int argc, char* argv[] ) {

	IdxReader idxImages( "train-images.idx" );
	auto idxImage = idxImages.getIdxObject<Uint8>( 0 );

	IdxReader idxLabels( "train-labels.idx" );
	auto idxLabel = idxLabels.getIdxObject<Uint8>( 0 );

	auto net = std::make_unique<Network>();

	net->addLayer( 3 );
	net->addNeuronToLayer( 0, 28 * 28 );
	net->addNeuronToLayer( 1, 16 );
	net->addNeuronToLayer( 2, 10 );
	net->connectAllLayers();

	TestData tData( net->inputSize(), net->outputSize() );
	
	EvolutionHandler eHandler( std::move( net ) );
	
	return 0;
}