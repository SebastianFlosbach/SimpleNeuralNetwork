#include "Layer.h"


namespace network {

	const void Layer::addNeuron( float bias ) {
		neurons_.emplace_back( Neuron( neurons_.size(), bias ) );
	}

	NeuronPtr Layer::getNeuron( Uint32 id ) {
		if ( id >= neurons_.size() ) {
			return nullptr;
		}

		return neurons_[id];
	}

	void Layer::resetInput() {
		for ( auto neuron : neurons_ ) {
			neuron->resetInput();
		}
	}

	void Layer::operateOutput() {
		for ( auto neuron : neurons_ ) {
			neuron->operateConnection();
		}
	}
}