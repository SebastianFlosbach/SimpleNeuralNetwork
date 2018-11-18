#include "gtest/gtest.h"

#include "Neuron.h"

TEST( myTestCase, myTest ) {
	network::Neuron neuron0 = network::Neuron();
	ASSERT_EQ( neuron0.Id(), 0 );
	network::Neuron neuron1 = network::Neuron();
	ASSERT_EQ( neuron1.Id(), 1 );
}


int main( int argc, char* argv[] ) {
	::testing::InitGoogleTest( &argc, argv );
	return RUN_ALL_TESTS();
}