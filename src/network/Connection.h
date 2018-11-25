#pragma once
#include "Neuron.h"

namespace network {

	struct Connection {
		Connection( float bias ) : bias_( bias ) {

		}

		void setBias( float bias );
		const float getBias() const { return bias_; }
		void setTarget( NeuronPtr& neuron );
		const Neuron* getTarget() const;

	private:
		float bias_;
		std::weak_ptr<Neuron> target_;

	};
}