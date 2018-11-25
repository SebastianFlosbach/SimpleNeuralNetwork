#include "Connection.h"

namespace network {

	void Connection::setBias( float bias ) {
		bias_ = bias;
	}

	void Connection::setTarget( NeuronPtr& neuron ) {
		target_ = neuron;
	}

	const Neuron* getTarget() const {
		if ( auto shared_target = target_.lock() ) {
			return shared_target.get();
		}

		return nullptr;
	}
}