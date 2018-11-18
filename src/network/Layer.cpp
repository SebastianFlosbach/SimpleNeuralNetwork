#include "Layer.h"

#include <algorithm>

namespace network {

	Layer::Layer() {

	}

	bool Layer::addNeuron( Neuron&& neuron ) {
		auto it = std::find_if( neurons_.begin(), neurons_.end(), [&neuron]( Neuron& current ) { return current.Id() == neuron.Id(); } );

		if ( it != neurons_.end() ) {
			return false;
		}

		neurons_.push_back( neuron );

		return true;
	}

	bool Layer::removeNeuron( Uint32 id ) {
		auto it = std::find_if( neurons_.begin(), neurons_.end(), [id]( Neuron& current ) { return current.Id() == id; } );

		if ( it == neurons_.end() ) {
			return false;
		}

		neurons_.erase( it );
		return true;
	}

}