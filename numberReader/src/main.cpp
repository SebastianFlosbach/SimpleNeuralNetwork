#include "Network.h"
#include "IdxReader.h"
#include "EvolutionHandler.h"

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

	IdxReader idxImages( "t10k-images.idx" );
	IdxReader idxLabels( "t10k-labels.idx" );

	auto net = std::make_unique<Network>();

	net->addLayer( 3 );
	net->addNeuronToLayer( 0, 28 * 28 );
	net->addNeuronToLayer( 1, 16 );
	net->addNeuronToLayer( 2, 10 );
	net->connectAllLayers();

	TestData tData( net->inputSize(), net->outputSize() );
	
	EvolutionHandler eHandler( std::move( net ) );

	auto imageData = idxImages.getIdxObject<Uint8>();
	auto labelData = idxLabels.getIdxObject<Uint8>();

	std::vector<float> inputData( 28 * 28 );
	std::vector<float> outputData( 10 );
	
	auto label = labelData.getData( 0 );
	for ( size_t l = 0; l < 10; l++ ) {
		if ( l == label ) {
			outputData[l] = 1;
		} else {
			outputData[l] = 0;
		}
	}

	auto image = imageData.getIdxObject( i );
	for ( size_t h = 0; h < 28; h++ ) {
		auto row = image.getIdxObject( h );
		for ( size_t w = 0; w < 28; w++ ) {
			inputData[h * 28 + w] = row.getData( w );
		}
	}
	
	TestDataPair tdp( std::move( inputData ), std::move( outputData ) );
	tData.addTestDataPair( std::move( tdp ) );

	/*std::cout << std::to_string( label ) << std::endl;
	printImage( image );*/

	eHandler.addTestData( std::move( tData ) );
	eHandler.evolveNextGeneration( 100, 0.1, 0.5 );
	
	return 0;
}