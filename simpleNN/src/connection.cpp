#include "Connection.h"

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