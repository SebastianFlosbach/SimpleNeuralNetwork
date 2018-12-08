#include "idxreader.h"

#include <iostream>
#include <fstream>
#include <vector>

int byteToInt( char a, char b, char c, char d ) {
	int res = 0;
	res |= a;
	res = res << 8;
	res |= b;
	res = res << 8;
	res |= c;
	res = res << 8;
	res |= d;
	return res;
}

idxType magicNumberToIdxType( const char num ) {
	switch ( num ) {
		case 0x08:
			return idxType::UBYTE;
			break;
		case 0x09:
			return idxType::SBYTE;
			break;
		case 0x0B:
			return idxType::SHORT;
			break;
		case 0x0C:
			return idxType::INT;
			break;
		case 0x0D:
			return idxType::FLOAT;
			break;
		case 0x0E:
			return idxType::DOUBLE;
			break;
		default:
			break;
	}
}

template <class T>
const IdxObject<T> IdxReader<T>::getIdxObject( const Uint32 index ) const {
	throw std::runtime_error( "[IdxReader::loadBWImage] Not implemented" );
}

template <class T>
void IdxReader<T>::loadData() {
	std::ifstream inputStream;
	inputStream.open( path_, std::ios::in );

	// Read dimensions from magic number
	for( size_t i = 0; i < 3; i++ ){
		inputStream.get();
	}
	auto dimensions = inputStream.get();

	// Read size of each dimension
	std::vector<int> dimensionSize( dimensions );
	for ( size_t i = 0; i < dimensions; i++ ) {
		auto a = inputStream.get();
		auto b = inputStream.get();
		auto c = inputStream.get();
		auto d = inputStream.get();

		dimensionSize[i] = byteToInt( a, b, c, d );
	}
}