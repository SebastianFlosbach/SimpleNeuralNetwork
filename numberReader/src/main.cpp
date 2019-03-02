#include "Network.h"
#include "IdxReader.h"
#include "EvolutionHandler.h"
#include "xml/XmlIO.h"
#include "idx_to_test_data.h"

#include <iostream>
#include <cmath>

typedef unsigned char Uint8;

void printImage( IdxObject<Uint8>& image ) {
	for ( size_t h = 0; h < 28; h++ ) {
		auto row = image.getIdxObject( h );
		for ( size_t w = 0; w < 28; w++ ) {
			if ( row.getData( w ) > 128 ) {
				std::cout << "X";
			} else {
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}
}

int main( int argc, char* argv[] ) {

	return 0;
}