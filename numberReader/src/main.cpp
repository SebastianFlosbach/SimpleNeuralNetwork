#include "Network.h"
#include "IdxReader.h"
#include "EvolutionHandler.h"
#include "xml/XmlIO.h"
#include "idx_to_test_data.h"

#include <iostream>
#include <cmath>

typedef unsigned char Uint8;

void printImage( IdxObject<Uint8>& image ) {
	for ( size_t h = 0; h < 28; h++ ) {
		auto row = image.getIdxObject( h );
		for ( size_t w = 0; w < 28; w++ ) {
			if ( row.getData( w ) > 128 ) {
				std::cout << "X";
			} else {
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}
}

int main( int argc, char* argv[] ) {

	IdxReader idxImages( "train-images.idx" );
	IdxReader idxLabels( "train-labels.idx" );

	auto net = std::make_unique<Network>();

	net->addLayer( 3 );
	net->addNeuronToLayer( 0, 28 * 28 );
	net->addNeuronToLayer( 1, 14 * 14 );
	net->addNeuronToLayer( 1, 7 * 7 );
	net->addNeuronToLayer( 2, 10 );
	net->connectAllLayers();
	
	auto imageData = idxImages.getIdxObject<Uint8>();
	auto labelData = idxLabels.getIdxObject<Uint8>();

	TestData tData = idx_to_test_data( imageData, labelData, net->inputSize(), net->outputSize(), 1000, 0 );	
	
	EvolutionHandler eHandler( std::move( net ) );
	eHandler.setThreadCount( 4 );

	eHandler.addTestData( std::move( tData ) );

	XmlIO xml = XmlIO( "read_0" );

	while ( eHandler.getFitness().getDifference() > 1 ) {
		eHandler.evolveNextGeneration( 6, 0.1, 0.6 );
		std::cout << "Fitness: " << std::to_string( eHandler.getFitness().getDifference() ) << std::endl;
		xml.saveNetwork( eHandler.getNetwork() );
	}


	Network bestNet = eHandler.getNetwork();

	IdxReader checkDataImages( "t10k-images.idx" );
	IdxReader checkDataLabels( "t10k-labels.idx" );

	return 0;
}