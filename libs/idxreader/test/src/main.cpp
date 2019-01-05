#include "gtest/gtest.h"
#include "IdxReader.h"

int main( int argc, char* argv[] ) {
	::testing::InitGoogleTest( &argc, argv );
	return RUN_ALL_TESTS();
}

TEST( idxreader_test, ReadFile_1D_1 ) {
	IdxReader reader( "data\\idxTest_1D.idx" );
	ASSERT_EQ( reader.getType(), IdxType::UBYTE );

	IdxObject<Uint8> idxObject = reader.getIdxObject<Uint8>();
	ASSERT_EQ( idxObject.numberOfDimensions(), 1 );
	ASSERT_EQ( idxObject.getData( 0 ), 0xAA );
}

TEST( idxreader_test, ReadFile_2D_2x2 ) {
	IdxReader reader( "data\\idxTest_2D.idx" );
	ASSERT_EQ( reader.getType(), IdxType::UBYTE );

	IdxObject<Uint8> idxObject2D = reader.getIdxObject<Uint8>();
	ASSERT_EQ( idxObject2D.numberOfDimensions(), 2 );

	IdxObject<Uint8> idxObject1 = idxObject2D.
}

TEST( idxreader_test, ReadFile_3D_2x2x1 ) {
	IdxReader reader( "data\\idxTest_3D.idx" );
	ASSERT_EQ( reader.getType(), IdxType::UBYTE );

	IdxObject<Uint8> idxObject = reader.getIdxObject<Uint8>();
}