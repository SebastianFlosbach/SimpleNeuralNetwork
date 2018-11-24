#pragma once
#include "Neuron.h"

#include <vector>

namespace network {

	class Layer;

	typedef std::unique_ptr<Layer> LayerPtr;

	class Layer {
		Uint32 id_;
		std::vector<NeuronPtr> neurons_;

	public:
		Layer( Uint32 id ) : id_( id ) {

		}

		const Uint32 Id() const { return id_; }
		const bool addNeuron( NeuronPtr& neuron );
		const bool removeNeuron( Uint32 id );
		const Uint32 size() const { return neurons_.size(); }

	};

}