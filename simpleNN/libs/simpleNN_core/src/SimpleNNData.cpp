#include "SimpleNNData.h"

#include <stdexcept>


void SimpleNNData::addLayer( uint32_t neuronCount ) {
	if (neuronCount < 1) {
		throw std::invalid_argument("A layer needs at least one neuron!");
	}

	neuronLayerCount.push_back(neuronCount);
}

const std::vector<uint32_t>& SimpleNNData::getLayerNeuronCounts() const {
	return neuronLayerCount;
}

size_t SimpleNNData::size() const {
	return neuronLayerCount.size();
}
