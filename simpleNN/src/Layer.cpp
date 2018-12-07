#include "Layer.h"


const Uint32 Layer::addNeuron( const Uint32 count ) {
	const auto returnValue = this->size();

	for ( size_t i = 0; i < count; i++ ) {
		neurons_.emplace_back( new Neuron( neurons_.size() ) );
	}

	return returnValue;
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
