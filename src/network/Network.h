#pragma once 
#include "Layer.h"

namespace network {

	class Network {
		std::vector<LayerPtr> layers_;

	public:
		const Uint32 inputSize() const;
		const Uint32 outputSize() const;
		void addLayer();
		void addNeuronToLayer( float bias );
		void setInput( Uint32 id, float value );
		void connectAllLayers();

	};
}