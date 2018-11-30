#pragma once 
#include "Layer.h"

namespace network {

	class Network {
		std::vector<LayerPtr> layers_;

	public:
		const Uint32 inputSize() const;
		const Uint32 outputSize() const;
		const Uint32 addLayer();
		const Uint32 addNeuronToLayer( Uint32 layerId );
		void setNeuronBias( Uint32 layerId, Uint32 neuronId, float bias );
		void setInput( Uint32 id, float value );
		void connectAllLayers();
		void operate();

	};
}