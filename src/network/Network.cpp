#include "Network.h"

#include <algorithm>

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

	bool Network::addLayer( LayerPtr& layer ) {
		auto it = std::find_if( layers_.begin(), layers_.end(), [&layer]( LayerPtr& current ) { return current->Id() == layer->Id(); } );

		if ( it != layers_.end() ) {
			return false;
		}

		layers_.push_back( std::move( layer ) );

		return true;
	}

	void Network::setInput( Uint32 id ) {

		if ( layers_.size() < 1 ) {
			throw std::runtime_error( "Network has no layer" );
		}

		auto inputLayer = layers_[0].get();
		
	}

	void Network::connectAllLayers() {

	}
}