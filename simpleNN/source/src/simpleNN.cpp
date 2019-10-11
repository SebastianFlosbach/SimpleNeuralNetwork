#include "simpleNN.h"

#include <cstdarg>

#include "Layer.h"


CSimpleNN_ptr create( uint32_t argn, const Layer layer... ) {
	std::vector<Layer> layerVector( argn );

	va_list args;
	va_start( args, layer );

	for( uint32_t i = 0; i < argn; i++ ) {
		layerVector.push_back( va_arg( args, Layer ) );
	}

	va_end( args );

	return std::make_unique<CSimpleNN>( layerVector );
}
