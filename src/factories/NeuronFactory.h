#pragma once
#include "../network/Neuron.h"

namespace factory {
	
	class NeuronFactory {
		Uint32 idCounter;

	public:
		NeuronFactory() {
			idCounter = 0;
		}

		network::Neuron* createNeuron() {
			return new network::Neuron( idCounter++ );
		}
	};
}