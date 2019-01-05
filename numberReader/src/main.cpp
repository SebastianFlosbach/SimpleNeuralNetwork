#include "Network.h"
#include "idxreader.h"
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

	//for ( size_t i = 0; i < idxImages.size(); i++ ) {
	//	auto idxImage = idxImages.getIdxObject<Uint8>( i );
	//	auto idxLabel = idxLabels.getIdxObject<Uint8>( i );
	//	
	//	std::vector<float> input( idxImage.size() );
	//	for ( size_t j = 0; j < idxImage.size(); j++ ) {
	//		input[i] = static_cast<float>( idxImage.getData( j ) );
	//	}

	//	std::vector<float> output( 10 );
	//	for ( size_t j = 0; j < 10; i++ ) {
	//		output[j] = 0;
	//	}
	//	output[idxLabel.getData( 0 )];

	//	TestDataPair tPair( std::move( input ), std::move( output ) );
	//	tData.addTestDataPair( std::move( tPair ) );
	//}
	
	return 0;
}