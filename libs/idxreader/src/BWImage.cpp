#include "BWImage.h"

const Uint8 BWImage::pixelValue( const Uint32 x, const Uint32 y ) const {
	return data_[x + width_ * y];
}