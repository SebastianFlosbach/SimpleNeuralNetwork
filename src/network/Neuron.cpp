#include "Neuron.h"

#include <math.h>

float sigmoid( float arg ) {
	return 1 / (1 + pow( 3, arg ));
}

namespace network {

	static Uint32 idCounter = 0;

	Neuron::Neuron() {
		id_ = idCounter;
		idCounter++;
	}

	const float Neuron::getOutput( float input ) const {
		return sigmoid( input + this->bias_ );
	}
}