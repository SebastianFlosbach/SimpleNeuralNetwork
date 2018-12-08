#pragma once

typedef unsigned int Uint32;

template <typename T>
struct IdxObject {
	IdxObject( const Uint32 width, const Uint32 height, T&& data_ ) : width_( width ), height_( height ), data_( data ) {
	}

private:
	Uint32 width_;
	Uint32 height_;

	T* data_;
};