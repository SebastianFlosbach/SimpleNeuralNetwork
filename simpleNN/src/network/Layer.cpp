#include "Layer.h"


namespace network {

	const Uint32 Layer::addNeuron() {
		neurons_.emplace_back( new Neuron( neurons_.size() ) );
		return neurons_.size() - 1;
	}

	NeuronPtr Layer::getNeuron( Uint32 id ) const {
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

	void Layer::setInput( Uint32 id, float input ) {
		if ( id >= neurons_.size() ) {
			return;
		}

		neurons_[id]->setInput( input );
	}
}