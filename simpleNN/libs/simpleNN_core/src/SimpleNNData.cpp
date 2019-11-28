#include "SimpleNNData.h"


SimpleNNData::addLayer( uint32_t neuronCount ) {
	neuronLayerCount.push_back(neuronCount);
}

const uint32_t* SimpleNNData::getLayerNeuronCounts() const {
	return neuronLayerCount.data();
}
