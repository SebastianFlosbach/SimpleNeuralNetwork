#include "Network.h"

#include <algorithm>
#include <sstream>
#include <random>
#include <iostream>

#include "xml/XmlIO.h"


Network::Network( const Network& other ) {
	*this = other;
}

Network& Network::operator=( const Network& other ) {
	if( this == &other ) {
		return *this;
	}

	for ( size_t i = 0; i < other.numberOfLayers(); i++ ) {
		layers_.push_back( other.layers_[i].copy() );
	}

	return *this;
}

Network::Network( Network&& other ) {
	*this = std::move( other );
}

Network& Network::operator=( Network&& other ) {
	this->layers_ = std::move( other.layers_ );

	return *this;
}

Network Network::copyAndMutate( const float chance, const float range ) const {
	if ( chance < 0 || chance > 1 ) {
		std::ostringstream errorMsg;
		errorMsg << "[Network::copyAndMutate(const float, const float)]: chance has to be [0;1], is actually: " << chance;
		throw std::invalid_argument( errorMsg.str() );
	}

	Network mutatedNetwork = Network();
	Layer* previousNewLayer = nullptr;
	Layer* previousOldLayer = nullptr;

	return mutatedNetwork;
}

const Uint32 Network::inputSize() const {
	if ( layers_.size() < 1 ) {
		return 0;
	}

	return layers_[0].size();
}

const Uint32 Network::outputSize() const {
	if ( layers_.size() < 2 ) {
		return 0;
	}

	return layers_[layers_.size() - 1].size();
}

void Network::addLayer( const Uint32 count ) {
	for ( size_t i = 0; i < count; i++ ) {
		layers_.emplace_back( layers_.size() );
	}
}

Layer* Network::addLayer() {
	layers_.emplace_back( layers_.size() );
	return &layers_.back();
}

void Network::setInput( Uint32 id, float value ) {
	if ( input_.size() <= id ) {
		input_.resize( id + 1 );
	}

	input_[id] = value;
}

void Network::setInput( const std::vector<float>& input ) {
	input_ = input;
}

float Network::getOutput( const Uint32 neuronId ) const {
	return 0;
}

const std::vector<float> Network::getOutput() const {
	std::vector<float> output( outputSize() );

	for ( size_t i = 0; i < outputSize(); i++ ) {
		output[i] = getOutput( i );
	}

	return output;
}

Layer* Network::getLayer( const Uint32 layerId ) const {
	if ( layerId >= this->numberOfLayers() ) {
		return nullptr;
	}

	return (Layer*)&layers_[layerId];
}
