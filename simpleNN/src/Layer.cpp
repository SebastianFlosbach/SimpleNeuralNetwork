#include "Layer.h"


Layer::Layer( Layer&& other ) {
	*this = std::move( other );
}

Layer& Layer::operator=( Layer&& other ) {
	Layer layer = Layer( other.id_ );

	for ( size_t i = 0; i < other.size(); i++ ) {
		layer.neurons_.emplace_back( std::move( other.neurons_[i] ) );
	}

	return layer;
}

const void Layer::addNeuron( const Uint32 count ) {
	for ( size_t i = 0; i < count; i++ ) {
		neurons_.emplace_back( neurons_.size() );
	}
}

Neuron* Layer::addNeuron() {
	neurons_.emplace_back( neurons_.size() );
	return &neurons_.back();
}

Neuron* Layer::getNeuron( Uint32 id ) const {
	if ( id >= neurons_.size() ) {
		throw std::invalid_argument( "Layer::getNeuron( Uint32 ): Invalid id" );
	}

	return &neurons_[id];
}

Layer Layer::copy() const {
	Layer layer = Layer( id_ );

	for ( auto& neuron : neurons_ ) {
		layer.addNeuron()->setBias( neuron.getBias() );
	}

	return layer;
}
