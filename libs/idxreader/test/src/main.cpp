#include "gtest/gtest.h"
#include "IdxReader.h"

int main( int argc, char* argv[] ) {
	::testing::InitGoogleTest( &argc, argv );
	return RUN_ALL_TESTS();
}

TEST( idxreader_test, ReadFile_1_Dimension ) {
	IdxReader reader( "..\\data\\idxTest.idx" );

	reader.getIdxObject<Uint32>( 0 );
}