#include "gtest/gtest.h"

#include "Neuron.h"
#include "Layer.h"
#include "NeuronFactory.h"
#include "LayerFactory.h"
#include "Network.h"

TEST( network_test, creatingNeuron ) {
	auto n1 = network::Neuron( 0 );
	ASSERT_EQ( n1.Id(), 0 );
	auto n2 = network::Neuron( 0xff );
	ASSERT_EQ( n2.Id(), 0xff );
}

TEST( network_test, connectingNeurons ) {
	auto neuronFactory = factory::NeuronFactory();
	auto n1 = neuronFactory.createNeuron();
	auto n2 = neuronFactory.createNeuron();

	n1->addConnection( 1, n2 );
	ASSERT_EQ( n1->getConnections()[0].getTarget()->Id(), n2->Id() );
}

TEST( network_test, layer ) {
	auto n1 = std::make_shared<network::Neuron>( 1 );
	auto l1 = network::Layer( 0 );
	ASSERT_EQ( l1.size(), 0 );

	auto id1 = n1->Id();

	l1.addNeuron( n1 );
	ASSERT_EQ( n1, nullptr );
	ASSERT_EQ( l1.size(), 1 );

	auto returnCode = l1.removeNeuron( id1 );
	ASSERT_EQ( returnCode, true );
	ASSERT_EQ( l1.size(), 0 );
}

TEST( network_test, network ) {
	auto nw1 = network::Network();
}

TEST( factory_test, creatingNeuron ) {
	auto nf = factory::NeuronFactory();
	auto n1 = nf.createNeuron();
	ASSERT_EQ( n1->Id(), 0 );
	auto n2 = nf.createNeuron();
	ASSERT_EQ( n2->Id(), 1 );
}

TEST( factory_test, creatingLayer ) {
	auto lf = factory::LayerFactory();
}


int main( int argc, char* argv[] ) {
	::testing::InitGoogleTest( &argc, argv );
	return RUN_ALL_TESTS();
}