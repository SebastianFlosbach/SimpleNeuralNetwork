#pragma once

#include <vector>


class SimpleNNData {
public:
	void addLayer( uint32_t neuronCount );
	const uint32_t* getLayerNeuronCounts() const;
	size_t size() const;

private:
	std::vector<uint32_t> neuronLayerCount;


};
