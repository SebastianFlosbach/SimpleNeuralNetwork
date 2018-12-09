#pragma once
#include <vector>

typedef unsigned int Uint32;

template <typename T>
struct IdxObject {
	IdxObject( std::vector<int> size, T* data ) : size_( size ), data_( data ) {
	}

	const Uint32 size() const {
		auto size = 1;
		for ( size_t i = 0; i < size_.size(); i++ ) {
			size *= size_[i];
		}
		return size;
	}

	const Uint32 numberOfDimensions() const {
		return size_.size();
	}

	const Uint32 sizeOfDimension( const Uint32 dimension ) const {
		return size_[dimension];
	}

	const T getData( const Uint32 index ) const {
		return data_[index];
	}

private:
	std::vector<int> size_;

	T* data_;
};