#include "SimpleNNFactory.h"

#include "CSimpleNN.h"


ISimpleNN_ptr SimpleNNFactory::createSimpleNN(const SimpleNNData& data) {
	auto* layerData = data.getLayerNeuronCounts();
	std::vector<Layer> layers = std::vector<Layer>(data.size());

	for (size_t i = 0; i < data.size() - 1; i++) {
		Eigen::MatrixXf connectionMatrix = Eigen::MatrixXf::Random(layerData[i + 1], layerData[i]);
		Eigen::VectorXf biasVector = Eigen::VectorXf::Random(layerData[i]);
		layers[i] = Layer( connectionMatrix, biasVector );
	}

	Eigen::MatrixXf connectionMatrix = Eigen::MatrixXf::Identity(layerData[data.size() - 1], layerData[data.size() - 1]);
	Eigen::VectorXf biasVector = Eigen::VectorXf::Random(layerData[data.size() - 1]);
	layers[data.size() - 1] = Layer(connectionMatrix, biasVector);

	return ISimpleNN_ptr(new CSimpleNN(layers));
}
