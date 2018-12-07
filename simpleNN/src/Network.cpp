#include "Network.h"

#include <algorithm>
#include <sstream>
#include <random>

#include "xml/XmlIO.h"


Network::Network( const Network& network ) {
	for ( size_t i = 0; i < network.size(); i++ ) {
		auto layerId = addLayer();
		auto oldLayer = this->getLayer( layerId );
		auto newLayer = getLayer( layerId );

		for ( size_t j = 0; j < oldLayer->size(); j++ ) {
			auto neuronId = addNeuronToLayer( layerId );
			auto oldNeuron = oldLayer->getNeuron( neuronId );
			auto newNeuron = newLayer->getNeuron( neuronId );

			newNeuron->setBias( oldNeuron->getBias() );
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
	Layer* previousNewLayer = nullptr;
	Layer* previousOldLayer = nullptr;

	for ( size_t i = 0; i < this->size(); i++ ) {
		auto layerId = mutatedNetwork->addLayer();
		auto oldLayer = this->getLayer( layerId );
		auto newLayer = mutatedNetwork->getLayer( layerId );

		for ( size_t j = 0; j < oldLayer->size(); j++ ) {
			auto neuronId = mutatedNetwork->addNeuronToLayer( layerId );
			auto oldNeuron = oldLayer->getNeuron( neuronId );
			auto newNeuron = newLayer->getNeuron( neuronId );

			auto bias = oldNeuron->getBias();

			auto mutateChance = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
			auto scaling = -1 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (1 - (-1))));

			if ( mutateChance <= chance ) {
				bias += (scaling * range);
			}

			newNeuron->setBias( bias );
		}

		if ( previousOldLayer && previousNewLayer ) {
			for ( size_t j = 0; j < previousOldLayer->size(); j++ ) {
				auto oldNeuron = previousOldLayer->getNeuron( j );
				auto newNeuron = previousNewLayer->getNeuron( j );

				for ( size_t c = 0; c < newLayer->size(); c++ ) {
					auto oldConnection = oldNeuron->getConnection( c );

					auto weight = oldConnection->getWeight();

					auto mutateChance = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
					auto scaling = -1 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (1 - (-1))));

					if ( mutateChance <= chance ) {
						weight += (scaling * range);
					}

					auto targetNeuron = newLayer->getNeuron( c );
					newNeuron->addConnection( weight, targetNeuron );
				}
			}
		}

		previousOldLayer = (Layer*)oldLayer;
		previousNewLayer = (Layer*)newLayer;
	}

	return mutatedNetwork;
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

	for ( size_t i = 0; i < layers_.size() - 1; i++ ) {
		auto sourceLayer = layers_[i].get();
		auto targetLayer = layers_[i + 1].get();

		for ( size_t sourceNeuronId = 0; sourceNeuronId < sourceLayer->size(); sourceNeuronId++ ) {
			auto sourceNeuron = sourceLayer->getNeuron( sourceNeuronId );
			for ( size_t targetNeuronId = 0; targetNeuronId < targetLayer->size(); targetNeuronId++ ) {
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

void Network::setConnection( const Uint32 sourceLayerId, const Uint32 sourceNeuronId, const Uint32 targetLayerId, const Uint32 targetNeuronId, const float bias ) {

}

const Connection* Network::getConnection( const Uint32 sourceLayerId, const Uint32 sourceNeuronId, const Uint32 targetNeuronId ) const {
	if ( sourceLayerId >= this->size() ) {
		throw std::invalid_argument( "[Network::getConnection]: Invalid layer id" );
	}

	auto sourceLayer = this->getLayer( sourceLayerId );

	if ( sourceNeuronId >= sourceLayer->size() ) {
		throw std::invalid_argument( "[Network::getConnection]: Invalid source neuron id" );
	}

	auto sourceNeuron = sourceLayer->getNeuron( sourceNeuronId );

	return sourceNeuron->getConnection( targetNeuronId );
}

const Layer* Network::getLayer( const Uint32 layerId ) const {
	if ( layerId >= this->size() ) {
		return nullptr;
	}

	return layers_[layerId].get();
}

void Network::save( const std::string& name ) const {
	XmlIO writer = XmlIO( name );

	writer.saveNetwork( *this );
}