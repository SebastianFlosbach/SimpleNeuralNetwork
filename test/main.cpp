#include "gtest/gtest.h"

TEST( myTestCase, myTest ) {
	int arg = 0;
	ASSERT_EQ( arg, 0 );
}


int main( int argc, char* argv[] ) {
	::testing::InitGoogleTest( &argc, argv );
	return RUN_ALL_TESTS();
}