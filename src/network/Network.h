#pragma once 
#include "Layer.h"

namespace network {

	class Network {
		std::vector<Layer> layers_;

	public:
		const Uint32 inputSize() const;
		const Uint32 outputSize() const;
		void addLayer();
		void setInput( Uint32 id, float value );
		void connectAllLayers();

	};
}