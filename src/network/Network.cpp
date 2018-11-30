#include "Network.h"

#include <algorithm>
#include <sstream>

namespace network {
	
	const Uint32 Network::inputSize() const {
		if ( layers_.size() < 1 ) {
			return 0;
		}

		return layers_[0]->size();
	}

	const Uint32 Network::outputSize() const {
		if ( layers_.size() < 2 ) {
			return 0;
		}

		return layers_[layers_.size() - 1]->size();
	}

	const Uint32 Network::addLayer() {
		layers_.emplace_back( new Layer( layers_.size() ) );
		return layers_.size() - 1;
	}

	void Network::setInput( Uint32 id, float value ) {

		if ( layers_.size() < 1 ) {
			return;
		}

		layers_[0]->setInput( id, value );
	}

	const Uint32 Network::addNeuronToLayer( Uint32 layerId ) {
		if ( layerId >= layers_.size() ) {
			std::ostringstream errorMsg;
			errorMsg << "Could not add neuron to layer " << layerId << ", because it does not exist";
			throw std::invalid_argument( errorMsg.str() );
		}

		return layers_[layerId]->addNeuron();
	}

	void Network::connectAllLayers() {

		if ( layers_.size() < 2 ) {
			throw std::runtime_error( "Network has fewer than two layers" );
		}

		for ( int i = 0; i < layers_.size() - 1; i++ ) {
			auto sourceLayer = layers_[i].get();
			auto targetLayer = layers_[i + 1].get();

			for ( int sourceNeuronId = 0; sourceNeuronId < sourceLayer->size(); sourceNeuronId++ ) {
				auto sourceNeuron = sourceLayer->getNeuron( sourceNeuronId );
				for ( int targetNeuronId = 0; targetNeuronId < targetLayer->size(); targetNeuronId++ ) {
					sourceNeuron->addConnection( 1.0f, targetLayer->getNeuron( targetNeuronId ) );
				}
			}
		}
	}

	void Network::setNeuronBias( Uint32 layerId, Uint32 neuronId, float bias ) {
		if ( layerId >= layers_.size() ) {
			std::ostringstream errorMsg;
			errorMsg << "Could not set bias in layer[" << layerId << "], neuron[" << neuronId << "] because this layer does not exist";
			throw std::invalid_argument( errorMsg.str() );
		}
		auto layer = layers_[layerId].get();

		if ( neuronId >= layer->size() ) {
			std::ostringstream errorMsg;
			errorMsg << "Could not set bias in layer[" << layerId << "], neuron[" << neuronId << "] because this neuron does not exist";
			throw std::invalid_argument( errorMsg.str() );
		}
		auto neuron = layer[neuronId].getNeuron( neuronId );

		neuron->setBias( bias );
	}

	void Network::operate() {
		for ( size_t i = 0; i < layers_.size(); i++ ) {
			layers_[i]->operateOutput();
		}
	}

}