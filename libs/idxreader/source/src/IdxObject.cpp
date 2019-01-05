#include "IdxObject.h"

template<typename T>
const IdxObject<T> IdxObject<T>::getIdxObject( Uint32 index ) const {
	if ( numberOfDimensions() <= 1 ) {
		throw std::runtime_error( "Tried to get IdxObject from 1 dimensional IdxObject" );
	}
}