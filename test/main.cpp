#include "gtest/gtest.h"

#include "Neuron.h"
#include "Layer.h"
#include "Network.h"


int main( int argc, char* argv[] ) {
	::testing::InitGoogleTest( &argc, argv );
	return RUN_ALL_TESTS();
}