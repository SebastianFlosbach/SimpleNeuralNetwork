#pragma once 
#include "Layer.h"

namespace network {

	class Network;

	typedef std::unique_ptr<Network> NetworkPtr;

	class Network {
		std::vector<LayerPtr> layers_;

		const Layer* getLayer( const Uint32 layerId );

	public:
		Network() = default;

		// Copy constructor
		Network( const Network& network );

		NetworkPtr copyAndMutate( const float chance, const float range ) const;

		const Uint32 inputSize() const;
		const Uint32 outputSize() const;
		const Uint32 size() const { return layers_.size(); }
		const Uint32 addLayer();
		const Uint32 addNeuronToLayer( const Uint32 layerId );
		void setNeuronBias( const Uint32 layerId, const Uint32 neuronId, float bias );
		void setInput( const Uint32 neuronId, float value );
		const float getOutput( const Uint32 neuronId ) const ;
		void connectAllLayers();
		void operate();
		void reset();

	};
}