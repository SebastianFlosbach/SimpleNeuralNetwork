#include "Network.h"

namespace network {
	
	const Uint32 Network::inputSize() const {
		if ( layers_[0] == nullptr ) {
			throw std::runtime_error( "Network has no input layer" );
		}

		return layers_[0]->size();
	}

	bool Network::addLayer( LayerPtr& layer ) {
		auto it = std::find_if( layers_.begin(), layers_.end(), [&layer]( LayerPtr& current ) { return current->Id() == layer->Id(); } );

		if ( it != layers_.end() ) {
			return false;
		}

		layers_.push_back( std::move( layer ) );

		return true;
	}
}