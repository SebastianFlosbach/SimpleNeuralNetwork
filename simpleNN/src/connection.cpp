#include "Connection.h"

Connection::Connection( Neuron& target ) : target_( target ) {
}

Connection::Connection( Neuron& target, float weight ) : target_( target ), weight_( weight ) {
}

const Neuron& Connection::getTargetNeuron() const {
	return target_;
}
