#pragma once
#include "Neuron.h"

#include <vector>

namespace network {

	class Layer;

	typedef std::unique_ptr<Layer> LayerPtr;

	class Layer {
		// Unique identifier of this layer inside its network
		Uint32 id_;

		// Array of neurons this layer holds
		std::vector<NeuronPtr> neurons_;

	public:
		Layer( Uint32 id ) : id_( id ) {
		}

		~Layer() = default;

		// Getter
		inline const Uint32 id() const { return id_; }
		const Uint32 size() const { return neurons_.size(); }

		const void addNeuron( float bias );
		NeuronPtr getNeuron( Uint32 id );
		void resetInput();
		void operateOutput();

	};
}