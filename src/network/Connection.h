#pragma once
#include <memory>

namespace network {

	class Neuron;
	typedef std::shared_ptr<Neuron> NeuronPtr;

	class Connection {
		float bias_;
		std::weak_ptr<Neuron> target_;

	public:

		Connection( float bias, NeuronPtr target ) : bias_( bias ), target_( std::weak_ptr<Neuron>( target ) ) {
		}

		const float getBias() const { return bias_; }
		void operate();
	};
}