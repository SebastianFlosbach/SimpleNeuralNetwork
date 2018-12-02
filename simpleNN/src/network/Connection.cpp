#include "Connection.h"

namespace network {

	void Connection::operate( float output ) {
		if ( auto target = target_.lock() ) {
			target->addToInput( output );
		}
	}
}