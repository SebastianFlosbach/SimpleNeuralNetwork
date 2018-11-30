#include "Network.h"

#include <algorithm>

namespace network {
	
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

	void Network::addLayer() {
		layers_.emplace_back( layers_.size() );
	}

	void Network::setInput( Uint32 id, float value ) {

		if ( layers_.size() < 1 ) {
			throw std::runtime_error( "Network has no layer" );
		}

		layers_[0].setInput();
	}

	void Network::connectAllLayers() {

		if ( layers_.size() < 2 ) {
			throw std::runtime_error( "Network has fewer than two layers" );
		}

		for ( int i = 0; i < layers_.size() - 1; i++ ) {
			auto sourceLayer = layers_[i];
			auto targetLayer = layers_[i + 1];

			for ( int sourceNeuronId = 0; sourceNeuronId < sourceLayer.size(); sourceNeuronId++ ) {
				auto sourceNeuron = sourceLayer.getNeuron( sourceNeuronId );
				for ( int targetNeuronId = 0; targetNeuronId < targetLayer.size(); targetNeuronId++ ) {
					sourceNeuron->addConnection( 1.0f, targetLayer[targetNeuronId] );
				}
			}
		}
	}
}