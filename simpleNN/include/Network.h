#pragma once 
#include "Layer.h"
#include "Connection.h"
#include <Eigen/Dense>

class Network;

class Network {
	mutable std::vector<Layer> layers_;
	std::vector<float> input_;
	Eigen::MatrixXd matrix_;

public:
	Network() = default;

	// Copy constructor
	Network( const Network& other );
	Network& operator=( const Network& other );

	// Move constructor
	Network( Network&& other );
	Network& operator=( Network&& other );

	Network copyAndMutate( const float chance, const float range ) const;

	const Uint32 inputSize() const;
	const Uint32 outputSize() const;
	inline const Uint32 numberOfLayers() const { return layers_.size(); }

	void addLayer( const Uint32 count );
	Layer* addLayer();
	Layer* getLayer( const Uint32 layerId ) const;

	void setInput( const Uint32 neuronId, float value );
	void setInput( const std::vector<float>& input );

	float getOutput( const Uint32 neuronId ) const;
	const std::vector<float> getOutput() const;
};