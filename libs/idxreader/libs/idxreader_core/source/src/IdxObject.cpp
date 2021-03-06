#include "IdxObject.h"

#include <stdexcept>


template <typename T>
const IdxObject<T> IdxObject<T>::getIdxObject( Uint32 index ) const {
	if ( numberOfDimensions() <= 1 ) {
		throw std::runtime_error( "Tried to get IdxObject from 1 dimensional IdxObject" );
	}

	std::vector<Uint32> dimensions( header_.sizeOfDimensions_.size() - 1 );
	for ( size_t i = 0; i < dimensions.size(); i++ ) {
		dimensions[i] = header_.sizeOfDimensions_[i + 1];
	}

	auto sizeInBytes = dimensions[0];
	for ( size_t i = 1; i < dimensions.size(); i++ ) {
		sizeInBytes *= dimensions[i];
	}

	IdxHeader header{
		header_.type_,
		dimensions.size(),
		dimensions,
		sizeInBytes
	};

	Uint32 startIndex = startIndex_ + sizeInBytes * index;
	Uint32 endIndex = startIndex + sizeInBytes - 1;

	return { header, data_, referenceCounter_, startIndex, endIndex };
}

template const IdxObject<Uint8> IdxObject<Uint8>::getIdxObject( Uint32 index ) const;