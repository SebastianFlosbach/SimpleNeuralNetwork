#include "Neuron.h"

#include <algorithm>
#include <math.h>

float sigmoid( float arg ) {
	return 1 / (1 + pow( 3, arg ));
}

namespace network {

	const float Neuron::getOutput() const {
		return sigmoid( currentInput_ + this->bias_ );
	}

	void Neuron::addConnection( float bias, NeuronPtr& target ) {
		connections_.emplace_back( bias );
		connections_.back().setTarget( target );
	}

	bool Neuron::removeConnection( Uint32 id ) {
		auto it = std::find_if( connections_.begin(), connections_.end(), [id]( Connection& current ) { return current.getTarget()->Id() == id; } );

		if ( it == connections_.end() ) {
			return false;
		}

		connections_.erase( it );
		return true;
	}

	void Neuron::resetInput() {
		currentInput_ = 0;
	}

	void Neuron::addToInput( float input ) {
		currentInput_ += input;
	}
}