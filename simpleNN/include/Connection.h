#pragma once
#include "Neuron.h"

#include <memory>


	class Neuron;
	typedef std::shared_ptr<Neuron> NeuronPtr;
	typedef unsigned int Uint32;

	class Connection {
		float bias_;
		std::weak_ptr<Neuron> target_;

	public:
		Connection( float bias, NeuronPtr target ) : bias_( bias ), target_( std::weak_ptr<Neuron>( target ) ) {
		}

		const float getBias() const { return bias_; }
		const Uint32 getTargetId() const;
		void operate( float output );
	};