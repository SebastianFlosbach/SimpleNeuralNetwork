#pragma once 
#include "Layer.h"
#include "Connection.h"

class Network;

typedef std::unique_ptr<Network> NetworkPtr;

class Network {
	std::vector<LayerPtr> layers_;

public:
	Network() = default;

	// Copy constructor
	Network( const Network& network );

	NetworkPtr copyAndMutate( const float chance, const float range ) const;

	const Uint32 inputSize() const;
	const Uint32 outputSize() const;
	inline const Uint32 size() const { return layers_.size(); }
	const Uint32 addLayer( const Uint32 count = 1 );
	const Uint32 addNeuronToLayer( const Uint32 layerId, const Uint32 count = 1 );
	void setNeuronBias( const Uint32 layerId, const Uint32 neuronId, float bias );
	void setInput( const Uint32 neuronId, float value );
	void setInput( const std::vector<float>& data );
	float getOutput( const Uint32 neuronId ) const;
	const std::vector<float> getOutput() const;
	void connectAllLayers();
	void operate();
	void reset();
	void setConnection( const Uint32 sourcelayerId, const Uint32 sourceNeuronId, const Uint32 targetLayerId, const Uint32 targetNeuronId, const float bias );
	const Connection* getConnection( const Uint32 sourcelayerId, const Uint32 sourceNeuronId, const Uint32 targetNeuronId ) const;
	const Layer* getLayer( const Uint32 layerId ) const;

	void save( const std::string& name ) const;

};