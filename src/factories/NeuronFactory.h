#pragma once
#include "../network/Neuron.h"

namespace factory {
	
	class NeuronFactory {
		Uint32 idCounter;

	public:
		NeuronFactory() {
			idCounter = 0;
		}

		network::NeuronPtr createNeuron() {
			return std::make_unique<network::Neuron>( idCounter++ );
		}
	};
}