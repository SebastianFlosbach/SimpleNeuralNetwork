#pragma once
#include <vector>

typedef unsigned int Uint32;

template <typename T>
struct IdxObject {
	IdxObject( std::vector<int> size, T* data ) : size_( size ), data_( data ) {
	}

private:
	std::vector<int> size_;

	T* data_;
};