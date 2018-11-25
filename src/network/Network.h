#pragma once 
#include "Layer.h"

namespace network {

	class Network {
		std::vector<LayerPtr> layers_;

	public:
		const Uint32 inputSize() const;
		const Uint32 outputSize() const;
		bool addLayer( LayerPtr& layer );
		void setInput( Uint32 id );
		void connectAllLayers();

	};
}