#include "Neuron.h"

#include "random_helper.h"

#include <algorithm>
#include <math.h>


float sigmoid( float arg ) {
	return 1.0f / ( 1.0f + (float)pow( 3, arg ));
}


Neuron::Neuron( Uint32 id ) : Neuron( id, 0 ) {
}

Neuron::Neuron( Uint32 id, float bias ) : id_( id ), bias_( bias ) {
}

Neuron::Neuron( Neuron&& other ) {
	*this = std::move( other );
}

Neuron& Neuron::operator=( Neuron&& other ) noexcept {
	Neuron neuron = Neuron( other.id_ );

	for ( size_t i = 0; other.numberOfConnections(); i++ ) {
		neuron.connections_.emplace_back( std::move( other.connections_[i] ) );
	}

	return neuron;
}

void Neuron::addConnection( Neuron& target, float weight ) {
	connections_.emplace_back( target, weight );
}

Connection& Neuron::getConnection( Uint32 targetId ) {
	if ( targetId >= numberOfConnections() ) {
		throw std::invalid_argument( "" );
	}

	return connections_[targetId];
}

Neuron Neuron::copy() const {
	return Neuron( id_, bias_ );
}
