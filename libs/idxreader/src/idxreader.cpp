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

struct IdxHeader {
	IdxType type_;
	int dimensions_;
	std::vector<int> size_;
	int sizeInBytes_;
};

template <>
const IdxObject<Uint8> IdxReader::getIdxObject( const Uint32 index ) {
	if ( !buffer_ ) {
		loadData();
	}

	if ( index >= dimensionSize_[0] ) {
		throw std::invalid_argument( "[IdxReader::loadBWImage] index out of bounds" );
	}

	Uint8* data;
	auto dataSize = 1;
	std::vector<int> dimensions;

	for ( size_t i = 1; i < dimensionSize_.size(); i++ ) {
		dataSize *= dimensionSize_[i];
		dimensions.push_back( dimensionSize_[i] );
	}

	data = (Uint8*)malloc( dataSize );

	memcpy( data, (Uint8*)buffer_ + (index * dataSize), dataSize );

	IdxObject<Uint8> idxObject( dimensions, std::move( data ) );
	return idxObject;
}

const IdxHeader readHeader( std::ifstream& inputStream ) {
	// Read type and dimensions from magic number
	for ( size_t i = 0; i < 2; i++ ) {
		inputStream.get();
	}
	auto type = magicNumberToIdxType( inputStream.get() );
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

	auto sizeInBytes = 0;

	for ( auto dimSize : dimensionSize ) {
		sizeInBytes += dimSize;
	}

	return { type, dimensions, dimensionSize, sizeInBytes };
}

void IdxReader::loadData() {
	std::ifstream inputStream;
	inputStream.open( path_, std::ios::in );

	IdxHeader header = readHeader( inputStream );
	dimensionSize_ = header.size_;

	switch ( header.type_ ) {
		case IdxType::UBYTE:
			buffer_ = new Uint8[header.sizeInBytes_];
			for ( size_t i = 0; i < header.sizeInBytes_; i++ ) {
				*( (Uint8*)buffer_ + i ) = inputStream.get();
			}
			break;
		case IdxType::SBYTE:
			break;
		case IdxType::SHORT:
			break;
		case IdxType::INT:
			break;
		case IdxType::FLOAT:
			break;
		case IdxType::DOUBLE:
			break;
		default:
			break;
	}
}