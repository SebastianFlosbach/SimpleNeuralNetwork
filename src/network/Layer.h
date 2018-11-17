#pragma once
#include "Neuron.h"

#include <vector>

namespace network {

	class Layer {

		std::vector<Neuron> neurons_;

	public:
		Layer();

		bool addNeuron( Neuron&& neuron );
		bool removeNeuron( Uint32 id );
	};

}