#include "Network.h"

#include <iostream>
#include <cmath>

int main( int argc, char* argv[] ) {

	float diff = 5;
	network::NetworkPtr net = std::make_unique<network::Network>();

	net->addLayer();
	net->addLayer();
	net->addLayer();

	net->addNeuronToLayer( 0 );
	net->addNeuronToLayer( 0 );

	net->addNeuronToLayer( 1 );
	net->addNeuronToLayer( 1 );
	net->addNeuronToLayer( 1 );
	net->addNeuronToLayer( 1 );

	net->addNeuronToLayer( 2 );

	while ( true ) {
		auto netCpy1 = net->copyAndMutate( 0.3, 0.2 );
		auto netCpy2 = net->copyAndMutate( 0.3, 0.2 );

		float diff1 = 0;
		float diff2 = 0;

		netCpy1->setInput( 0, 0 );
		netCpy1->setInput( 1, 0 );
		netCpy1->operate();
		diff1 += abs( 0 - netCpy1->getOutput( 0 ) );

		netCpy1->setInput( 0, 1 );
		netCpy1->setInput( 1, 0 );
		netCpy1->operate();
		diff1 += abs( 0 - netCpy1->getOutput( 0 ) );

		netCpy1->setInput( 0, 0 );
		netCpy1->setInput( 1, 1 );
		netCpy1->operate();
		diff1 += abs( 0 - netCpy1->getOutput( 0 ) );

		netCpy1->setInput( 0, 1 );
		netCpy1->setInput( 1, 1 );
		netCpy1->operate();
		diff1 += 4 * abs( 1 - netCpy1->getOutput( 0 ) );

		netCpy2->setInput( 0, 0 );
		netCpy2->setInput( 1, 0 );
		netCpy2->operate();
		diff2 += abs( 0 - netCpy2->getOutput( 0 ) );

		netCpy2->setInput( 0, 1 );
		netCpy2->setInput( 1, 0 );
		netCpy2->operate();
		diff2 += abs( 0 - netCpy2->getOutput( 0 ) );

		netCpy2->setInput( 0, 0 );
		netCpy2->setInput( 1, 1 );
		netCpy2->operate();
		diff2 += abs( 0 - netCpy2->getOutput( 0 ) );

		netCpy2->setInput( 0, 1 );
		netCpy2->setInput( 1, 1 );
		netCpy2->operate();
		diff2 += abs( 1 - netCpy2->getOutput( 0 ) );

		if ( diff <= diff1 && diff <= diff2 ) {
			std::cout << diff << std::endl;
		} else if ( diff1 <= diff2 ) {
			net = std::move( netCpy1 );
			std::cout << diff1 << std::endl;
		} else {
			net = std::move( netCpy2 );
			std::cout << diff2 << std::endl;
		}
	}
	
	return 0;
}