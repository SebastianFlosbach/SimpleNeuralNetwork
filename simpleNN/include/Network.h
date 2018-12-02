#pragma once 
#include "Layer.h"

namespace network {

	class Network {
		std::vector<LayerPtr> layers_;

	public:
		const Uint32 inputSize() const;
		const Uint32 outputSize() const;
		const Uint32 addLayer();
		const Uint32 addNeuronToLayer( const Uint32 layerId );
		void setNeuronBias( const Uint32 layerId, const Uint32 neuronId, float bias );
		void setInput( const Uint32 neuronId, float value );
		const float getOutput( const Uint32 neuronId ) const ;
		void connectAllLayers();
		void operate();

	};
}