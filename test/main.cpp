#include "gtest/gtest.h"

#include "Neuron.h"
#include "NeuronFactory.h"

TEST( network_test, creatingNeuron ) {
	network::Neuron n1 = network::Neuron( 0 );
	ASSERT_EQ( n1.Id(), 0 );
	network::Neuron n2 = network::Neuron( 0xff );
	ASSERT_EQ( n2.Id(), 0xff );
}

TEST( factory_test, creatingNeuron ) {
	factory::NeuronFactory nf = factory::NeuronFactory();
	network::Neuron* n1 = nf.createNeuron();
	ASSERT_EQ( n1->Id(), 0 );
	network::Neuron* n2 = nf.createNeuron();
	ASSERT_EQ( n2->Id(), 1 );

	delete n1;
	delete n2;
}


int main( int argc, char* argv[] ) {
	::testing::InitGoogleTest( &argc, argv );
	return RUN_ALL_TESTS();
}