#include "Connection.h"

namespace network {

	void Connection::operate() {
		if ( auto target = target_.lock() ) {
			target->addToInput()
		}
	}
}