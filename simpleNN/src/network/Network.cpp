#include "Network.h"

#include <algorithm>
#include <sstream>
#include <random>

namespace network {

	Network::Network( const Network& network ) {
		for ( size_t i = 0; i < network.size(); i++ ) {
			auto layerId = addLayer();
			auto layer = getLayer( layerId );

			for ( size_t j = 0; j < layer->size(); j++ ) {
				auto neuronId = addNeuronToLayer( layerId );
				auto neuron = layer->getNeuron( neuronId );

				setNeuronBias( layerId, neuronId, neuron->getBias() );
			}
		}

		connectAllLayers();
	}

	NetworkPtr Network::copyAndMutate( const float chance, const float range ) const {
		if ( chance < 0 || chance > 1 ) {
			std::ostringstream errorMsg;
			errorMsg << "[Network::copyAndMutate(const float, const float)]: chance has to be [0;1], is actually: " << chance;
			throw std::invalid_argument( errorMsg.str() );
		}

		NetworkPtr mutatedNetwork = std::make_unique<Network>();

		for ( size_t i = 0; i < this->size(); i++ ) {
			auto layerId = mutatedNetwork->addLayer();
			auto layer = mutatedNetwork->getLayer( layerId );

			for ( size_t j = 0; j < layer->size(); j++ ) {
				auto neuronId = mutatedNetwork->addNeuronToLayer( layerId );
				auto neuron = layer->getNeuron( neuronId );

				auto bias = neuron->getBias();

				auto mutateChance = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
				auto scaling = -1 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (1 - (-1))));

				if ( mutateChance <= chance ) {
					bias *= (scaling * range);
				}

				mutatedNetwork->setNeuronBias( layerId, neuronId, bias );
			}
		}

		mutatedNetwork->connectAllLayers();

		return mutatedNetwork;
	}

	const Layer* Network::getLayer( const Uint32 layerId ) {
		if ( layerId >= layers_.size() ) {
			return nullptr;
		}

		return layers_[layerId].get();
	}

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

	const Uint32 Network::addNeuronToLayer( const Uint32 layerId ) {
		if ( layerId >= layers_.size() ) {
			std::ostringstream errorMsg;
			errorMsg << "Could not add neuron to layer " << layerId << ", because it does not exist";
			throw std::invalid_argument( errorMsg.str() );
		}

		return layers_[layerId]->addNeuron();
	}

	void Network::connectAllLayers() {

		if ( layers_.size() == 0 ) {
			throw std::runtime_error( "Network has no layers" );
		}

		if ( layers_.size() == 1 ) {
			return;
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

	void Network::setNeuronBias( const Uint32 layerId, const Uint32 neuronId, float bias ) {
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
		reset();
		for ( size_t i = 0; i < layers_.size(); i++ ) {
			layers_[i]->operateOutput();
		}
	}

	void Network::reset() {
		for ( size_t i = 0; i < layers_.size(); i++ ) {
			layers_[i]->resetInput();
		}
	}

	const float Network::getOutput( const Uint32 neuronId ) const {
		if ( layers_.size() == 0 ) {
			throw std::runtime_error( "[Network::getOutput(const Uint32)] Network has no layer" );
		}

		auto outputLayer = layers_.back().get();

		if ( neuronId >= outputLayer->size() ) {
			std::ostringstream errorMsg;
			errorMsg << "Could not get output from layer[" << outputLayer->id() << "], neuron[" << neuronId << "] because this neuron does not exist";
			throw std::invalid_argument( errorMsg.str() );
		}

		auto outputNeuron = outputLayer->getNeuron( neuronId );

		return outputNeuron->getOutput();
	}

}