#pragma once
#include "Neuron.h"

#include <vector>

namespace network {

	class Layer {

		std::vector<NeuronPtr> neurons_;

	public:
		Layer();

		bool addNeuron( NeuronPtr& neuron );
		bool removeNeuron( Uint32 id );
	};

}