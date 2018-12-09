#include "Network.h"
#include "idxreader.h"

#include <iostream>
#include <cmath>

typedef unsigned char Uint8;

int main( int argc, char* argv[] ) {

	IdxReader reader("t10k-images.idx");
	auto idxObject = reader.getIdxObject<Uint8>( 0 );

	return 0;
}