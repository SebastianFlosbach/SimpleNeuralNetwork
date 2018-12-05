#include "Neuron.h"

#include <algorithm>
#include <math.h>


float sigmoid( float arg ) {
	return 1 / (1 + pow( 3, arg ));
}


const float Neuron::getOutput() const {
	return sigmoid( currentInput_ + this->bias_ );
}

void Neuron::addConnection( float bias, NeuronPtr& target ) {
	connections_.emplace_back( bias, target );
}

Connection* Neuron::getConnection( Uint32 targetId ) {
	for ( auto connection : connections_ ) {
		if ( targetId == connection.getTargetId() ) {
			return &connection;
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