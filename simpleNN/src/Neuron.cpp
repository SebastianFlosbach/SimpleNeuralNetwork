#include "Neuron.h"

#include "random_helper.h"

#include <algorithm>
#include <math.h>


float sigmoid( float arg ) {
	return 1 / (1 + pow( 3, arg ));
}


Neuron::Neuron( Uint32 id ) : id_( id ), bias_( getRandFloat( -1, 1 ) ) {
}

const float Neuron::getOutput() const {
	return sigmoid( currentInput_ + this->bias_ );
}

void Neuron::addConnection( NeuronPtr& target ) {
	connections_.emplace_back( target );
}

void Neuron::addConnection( NeuronPtr& target, float weight ) {
	connections_.emplace_back( target, weight );
}

Connection* Neuron::getConnection( Uint32 targetId ) {
	for ( size_t i = 0; i < size(); i++ ) {
		if ( targetId == connections_[i].getTargetId() ) {
			return &connections_[i];
		}
	}
	return nullptr;
}

void Neuron::resetInput() {
	currentInput_ = 0;
}

void Neuron::addToInput( float input ) {
	currentInput_ += input;
}

void Neuron::setInput( float input ) {
	currentInput_ = input;
}

void Neuron::operateConnection() {
	for ( auto connection : connections_ ) {
		connection.operate( getOutput() );
	}
}