#pragma once
#include "Neuron.h"

#include <memory>


class Neuron;
//typedef std::shared_ptr<Neuron> NeuronPtr;
typedef unsigned int Uint32;

class Connection {
	float weight_;
	Neuron& target_;

public:
	Connection( Neuron& target );
	Connection( Neuron& target, float weight );

	inline const float getWeight() const { return weight_; }
	const Neuron& getTargetNeuron() const;
};