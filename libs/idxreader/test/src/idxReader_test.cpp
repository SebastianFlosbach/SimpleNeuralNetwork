#include "gtest/gtest.h"

#include "IdxReader.h"


TEST( idxreader_test, ReadFile_1D_1 ) {
	IdxReader* pReader = CreateIdxReader( "data\\idxTest_1D.idx" );
	ASSERT_EQ( pReader->getType(), IdxType::UBYTE );

	IdxObject<Uint8> idxObject = pReader->getIdxObject<Uint8>();
	ASSERT_EQ( idxObject.numberOfDimensions(), 1 );
	ASSERT_EQ( idxObject.getData( 0 ), 0xAA );

	DestroyIdxReader(pReader);
}

TEST( idxreader_test, ReadFile_2D_2x2 ) {
	IdxReader* pReader = CreateIdxReader( "data\\idxTest_2D.idx" );
	ASSERT_EQ(pReader->getType(), IdxType::UBYTE );

	IdxObject<Uint8> idxObject2D = pReader->getIdxObject<Uint8>();
	ASSERT_EQ( idxObject2D.numberOfDimensions(), 2 );

	IdxObject<Uint8> idxObject1 = idxObject2D.getIdxObject( 0 );
	ASSERT_EQ( idxObject1.numberOfDimensions(), 1 );
	ASSERT_EQ( idxObject1.getData( 0 ), 0xAA );
	ASSERT_EQ( idxObject1.getData( 1 ), 0xBB );

	IdxObject<Uint8> idxObject2 = idxObject2D.getIdxObject( 1 );
	ASSERT_EQ( idxObject2.numberOfDimensions(), 1 );
	ASSERT_EQ( idxObject2.getData( 0 ), 0xAB );
	ASSERT_EQ( idxObject2.getData( 1 ), 0xBA );

	DestroyIdxReader(pReader);
}

TEST( idxreader_test, ReadFile_3D_2x2x1 ) {
	IdxReader* pReader = CreateIdxReader( "data\\idxTest_3D.idx" );
	ASSERT_EQ(pReader->getType(), IdxType::UBYTE );

	IdxObject<Uint8> idxObject3D = pReader->getIdxObject<Uint8>();

	DestroyIdxReader(pReader);
}
