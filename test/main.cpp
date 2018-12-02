#include "gtest/gtest.h"

#include "Network.h"


TEST( network_test, createNetwork_1Layer ) {
	network::Network testNetwork = network::Network();

	auto layerId = testNetwork.addLayer();
	ASSERT_EQ( layerId, 0 );
	auto neuronId = testNetwork.addNeuronToLayer( layerId );
	ASSERT_EQ( neuronId, 0 );
	testNetwork.setNeuronBias( layerId, neuronId, 1 );

	testNetwork.connectAllLayers();
	testNetwork.setInput( neuronId, 0 );

	testNetwork.operate();
	auto output = testNetwork.getOutput( neuronId );
}

TEST( network_test, network_creation ) {
	network::Network testNetwork = network::Network();
}

int main( int argc, char* argv[] ) {
	::testing::InitGoogleTest( &argc, argv );
	return RUN_ALL_TESTS();
}