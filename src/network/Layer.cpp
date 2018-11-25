#include "Layer.h"

#include <algorithm>

namespace network {

	const bool Layer::addNeuron( NeuronPtr& neuron ) {
		auto it = std::find_if( neurons_.begin(), neurons_.end(), [&neuron]( NeuronPtr& current ) { return current->Id() == neuron->Id(); } );

		if ( it != neurons_.end() ) {
			return false;
		}

		neurons_.push_back( std::move(neuron) );

		return true;
	}

	const bool Layer::removeNeuron( Uint32 id ) {
		auto it = std::find_if( neurons_.begin(), neurons_.end(), [id]( NeuronPtr& current ) { return current->Id() == id; } );

		if ( it == neurons_.end() ) {
			return false;
		}

		neurons_.erase( it );
		return true;
	}

	void Layer::setInput( Uint32 id, float value ) {

	}
}