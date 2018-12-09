#include "Network.h"
#include "idxreader.h"

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

	for ( size_t i = 0; i < idxImage.size(); i++ ) {
		net->setInput( i, idxImage.getData( i ) );
	}
	net->operate();

	std::cout << "Input: " << idxLabel.getData( 0 ) << std::endl << std::endl;

	std::cout << "Output 0: " << net->getOutput( 0 ) << std::endl;
	std::cout << "Output 1: " << net->getOutput( 1 ) << std::endl;
	std::cout << "Output 2: " << net->getOutput( 2 ) << std::endl;
	std::cout << "Output 3: " << net->getOutput( 3 ) << std::endl;
	std::cout << "Output 4: " << net->getOutput( 4 ) << std::endl;
	std::cout << "Output 5: " << net->getOutput( 5 ) << std::endl;
	std::cout << "Output 6: " << net->getOutput( 6 ) << std::endl;
	std::cout << "Output 7: " << net->getOutput( 7 ) << std::endl;
	std::cout << "Output 8: " << net->getOutput( 8 ) << std::endl;
	std::cout << "Output 9: " << net->getOutput( 9 ) << std::endl;

	return 0;
}