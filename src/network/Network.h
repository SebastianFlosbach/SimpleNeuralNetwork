#pragma once 
#include "Layer.h"

namespace network {

	class Network {
		std::vector<LayerPtr> layers_;

	public:
		const Uint32 inputSize() const;
		bool addLayer( LayerPtr& layer );

	};
}