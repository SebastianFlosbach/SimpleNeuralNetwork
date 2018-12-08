#include "Network.h"
#include "idxreader.h"

#include <iostream>
#include <cmath>

typedef unsigned char Uint8;

int main( int argc, char* argv[] ) {

	IdxReader<Uint8> reader("t10k-images.idx");
	reader.loadData();

	return 0;
}