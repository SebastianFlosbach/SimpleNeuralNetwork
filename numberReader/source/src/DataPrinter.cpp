#include "DataPrinter.h"

#include <iostream>


void printAsciiPixel(uint8_t data) {
	if( data > 127 ) {
		std::cout << '0';
	}
	else {
		std::cout << ' ';
	}
}

void printData( const IdxObject<Uint8>& numberObject ) {
	if( numberObject.numberOfDimensions() != 2 ) {
		std::cout << __FUNCTION__ << ": Invalid number of dimensions! Must be 2, is " << numberObject.numberOfDimensions() << std::endl;
	}

	for( uint32_t i = 0; i < numberObject.size(); i++ ) {
		IdxObject<Uint8> row = numberObject.getIdxObject(i);
		for( uint32_t j = 0; j < row.size(); j++ ) {
			printAsciiPixel(row.getData(j));
		}
		std::cout << std::endl;
	}
		

}
