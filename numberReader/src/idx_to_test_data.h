#pragma once

#include "TestData.h"
#include "IdxObject.h"

TestData idx_to_test_data( const IdxObject<Uint8>& imageData, const IdxObject<Uint8>& labelData, Uint32 inputSize, Uint32 outputSize, Uint32 limit ) {
	TestData tData( inputSize, outputSize );

	for ( size_t i = 0; i < imageData.size() && i < limit; i++ ) {
		std::vector<float> inputData( 28 * 28 );
		std::vector<float> outputData( 10 );

		auto label = labelData.getData( i );
		for ( size_t l = 0; l < 10; l++ ) {
			if ( l == label ) {
				outputData[l] = 1;
			} else {
				outputData[l] = 0;
			}
		}

		auto image = imageData.getIdxObject( 0 );
		for ( size_t h = 0; h < 28; h++ ) {
			auto row = image.getIdxObject( h );
			for ( size_t w = 0; w < 28; w++ ) {
				inputData[h * 28 + w] = row.getData( w );
			}
		}

		TestDataPair tdp( std::move( inputData ), std::move( outputData ) );
		tData.addTestDataPair( std::move( tdp ) );
	}

	return tData;
}