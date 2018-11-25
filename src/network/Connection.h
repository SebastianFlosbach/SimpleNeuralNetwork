#pragma once
#include <memory>

namespace network {

	class Neuron;
	typedef std::shared_ptr<Neuron> NeuronPtr;

	struct Connection {
		Connection( float bias = 0.f ) : bias_( bias ) {

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