#pragma once
#include "Neuron.h"

#include <memory>


	class Neuron;
	typedef std::shared_ptr<Neuron> NeuronPtr;
	typedef unsigned int Uint32;

	class Connection {
		float weight_;
		std::weak_ptr<Neuron> target_;

	public:
		Connection( float weight, NeuronPtr target ) : weight_( weight ), target_( std::weak_ptr<Neuron>( target ) ) {
		}

		const float getWeight() const { return weight_; }
		const Uint32 getTargetId() const;
		void operate( float output );
	};