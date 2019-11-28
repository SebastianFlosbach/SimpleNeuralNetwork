#pragma once

#include <vector>


class SimpleNNData {
public:
	void addLayer( uint32_t neuronCount );
	const uint32* getLayerNeuronCounts() const;

private:
	std::vector<uint32_t> neuronLayerCount;


};
