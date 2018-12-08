#pragma once

typedef unsigned char Uint8;
typedef unsigned int Uint32;

struct BWImage {
	BWImage( const Uint32 width, const Uint32 height ) : width_( width ), height_( height ) {
		data_ = new Uint8[width_ * height_];
	}

	~BWImage() {
		delete[] data_;
	}

	inline const Uint32 width() const { return width_; }
	inline const Uint32 height() const { return height_; }
	inline const Uint8 pixelValue( const Uint32 x, const Uint32 y ) const;
	
private:
	Uint32 width_;
	Uint32 height_;
	Uint8* data_;

};