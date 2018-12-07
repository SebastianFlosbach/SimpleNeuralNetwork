#include "Network.h"

#include <iostream>
#include <cmath>

struct diff {
	float diff1;
	float diff2;
};

diff testNetwork( Network* network ) {
	float diff1 = 0;
	float diff2 = 0;

	network->reset();
	network->setInput( 0, 0 );
	network->setInput( 1, 0 );
	network->operate();
	diff1 += abs( 1 - network->getOutput( 0 ) );

	network->reset();
	network->setInput( 0, 1 );
	network->setInput( 1, 0 );
	network->operate();
	diff1 += abs( 1 - network->getOutput( 0 ) );

	network->reset();
	network->setInput( 0, 0 );
	network->setInput( 1, 1 );
	network->operate();
	diff1 += abs( 1 - network->getOutput( 0 ) );

	network->reset();
	network->setInput( 0, 1 );
	network->setInput( 1, 1 );
	network->operate();
	diff2 += abs( 0 - network->getOutput( 0 ) );

	return { diff1, diff2 };
}

int main( int argc, char* argv[] ) {

	diff bestDiff{ 1000, 1000 };
	NetworkPtr net = std::make_unique<Network>();

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

	net->connectAllLayers();

	while ( bestDiff.diff1 > 0.001 && bestDiff.diff2 > 0.001 ) {
		NetworkPtr next;
		bool tmp = false;

		for( size_t i = 0; i < 500; i++ ) {
			auto current = net->copyAndMutate( 0.2, 0.1 );
			auto currentDiff = testNetwork( current.get() );
			if( currentDiff.diff1 <= bestDiff.diff1 && currentDiff.diff2 <= bestDiff.diff2 ) {
				tmp = true;
				next = std::move( current );
				bestDiff = currentDiff;
			}
		}

		if( tmp ) {
			std::cout << bestDiff.diff1 << " | " << bestDiff.diff2 << std::endl;
			net = std::move( next );
		}
	}

	net->save( "and.xml" );
	
	return 0;
}