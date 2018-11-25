#include "Neuron.h"

#include <math.h>

float sigmoid( float arg ) {
	return 1 / (1 + pow( 3, arg ));
}

namespace network {

	const float Neuron::getOutput( float input ) const {
		return sigmoid( input + this->bias_ );
	}

	void Neuron::addConnection( float bias, NeuronPtr& target ) {
		connections_.emplace_back( bias );
		connections_.back().setTarget( target );
	}

	bool Neuron::removeConnection( Uint32 id ) {
		return false;
	}

	void Neuron::resetInput() {
		currentInput_ = 0;
	}

	void Neuron::addToInput( float input ) {
		currentInput_ += input;
	}
}