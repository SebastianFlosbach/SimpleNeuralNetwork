#include "Connection.h"
#include "random_helper.h"

Connection::Connection( NeuronPtr target ) : weight_( getRandFloat( -1, 1 ) ), target_( std::weak_ptr<Neuron>( target ) ) {
}

const Uint32 Connection::getTargetId() const {
	if( auto target = target_.lock() ) {
		return target->id();
	}
	throw std::runtime_error( "[Connection::getTargetId()] Could not get target id because target no longer exists" );
}

void Connection::operate( float output ) {
	if ( auto target = target_.lock() ) {
		target->addToInput( output * weight_ );
	}
}