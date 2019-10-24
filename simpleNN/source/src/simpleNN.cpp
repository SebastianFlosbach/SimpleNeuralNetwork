#include "simpleNN.h"

#include <cstdarg>

#include "Layer.h"


SIMPLE_NN_EXPORTS CSimpleNN_ptr create( uint32_t argn, const Layer* layer ) {
	std::vector<Layer> layerVector( argn );

	for( uint32_t i = 0; i < argn; i++ ) {
		layerVector[i] = layer[i];
	}

	return std::make_unique<CSimpleNN>( layerVector );
}
