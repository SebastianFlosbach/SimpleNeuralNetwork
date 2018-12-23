#include "gtest/gtest.h"
#include "IdxReader.h"

int main( int argc, char* argv[] ) {
	::testing::InitGoogleTest( &argc, argv );
	return RUN_ALL_TESTS();
}

TEST( idxreader_test, ReadFile_1_Dimension ) {
	IdxReader reader( "data\\idxTest.idx" );
	ASSERT_EQ( reader.state(), IdxState::Ready );
	ASSERT_EQ( reader.dimensions(), 1 );
	ASSERT_EQ( reader.sizeOfDimension( 0 ), 1 );

	IdxObject<Uint8> idxObject = reader.getIdxObject<Uint8>( 0 );
	ASSERT_EQ( idxObject.getData( 0 ), 0xAA );
}