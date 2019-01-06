#include "idxreader.h"

#include <iostream>
#include <fstream>
#include <vector>

int byteToInt( Uint8 a, Uint8 b, Uint8 c, Uint8 d ) {
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

IdxType magicNumberToIdxType( const char num ) {
	switch ( num ) {
		case 0x08:
			return IdxType::UBYTE;
			break;
		case 0x09:
			return IdxType::SBYTE;
			break;
		case 0x0B:
			return IdxType::SHORT;
			break;
		case 0x0C:
			return IdxType::INT;
			break;
		case 0x0D:
			return IdxType::FLOAT;
			break;
		case 0x0E:
			return IdxType::DOUBLE;
			break;
		default:
			throw std::runtime_error( "Idx magic number type is unknown" );
			break;
	}
}

const IdxHeader readHeader( std::ifstream& inputStream ) {
	// Read type and dimensions from magic number
	char idxTypeNum;
	for ( size_t i = 0; i < 3; i++ ) {
		if ( !inputStream.read( &idxTypeNum, 1 ) ) {
			throw std::runtime_error( "Could not read file" );
		}
	}

	auto type = magicNumberToIdxType( idxTypeNum );
	auto dimensions = inputStream.get();

	// Read size of each dimension
	std::vector<Uint32> dimensionSize( dimensions );
	for ( size_t i = 0; i < dimensions; i++ ) {
		auto a = inputStream.get();
		auto b = inputStream.get();
		auto c = inputStream.get();
		auto d = inputStream.get();

		dimensionSize[i] = byteToInt( a, b, c, d );
	}

	auto sizeInBytes = 1;

	for ( auto dimSize : dimensionSize ) {
		sizeInBytes *= dimSize;
	}

	return { type, dimensions, dimensionSize, sizeInBytes };
}

const IdxType IdxReader::getType() const {
	std::ifstream inputStream( path_, std::ios::in | std::ios::binary );
	auto header = readHeader( inputStream );
	return header.type_;
}

template <>
const IdxObject<Uint8> IdxReader::getIdxObject() const {
	std::ifstream inputStream( path_, std::ios::in | std::ios::binary );
	auto header = readHeader( inputStream );

	Uint8* pData = (Uint8*)new Uint8[header.sizeInBytes_];

	char c;
	for ( size_t i = 0; i < header.sizeInBytes_; i++ ) {
		inputStream.read( &c, 1 );
		pData[i] = c;
	}
	
	return { header, pData };
}


