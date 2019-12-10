#include "CSimpleNN.h"


CSimpleNN::CSimpleNN( const std::vector<Layer>& layers ) : layers_( layers ) {
}

CSimpleNN::CSimpleNN( const std::vector<uint32_t>& layerNeuronCounts ) {
	layers_ = std::vector<Layer>( layerNeuronCounts.size() );

	for( size_t i = 0; i < layerNeuronCounts.size() - 1; i++ ) {
		Eigen::MatrixXf connectionMatrix = Eigen::MatrixXf::Random( layerNeuronCounts[i + 1], layerNeuronCounts[i] );
		Eigen::VectorXf biasVector = Eigen::VectorXf::Random( layerNeuronCounts[i] );
		layers_[i] = Layer( connectionMatrix, biasVector );
	}

	Eigen::MatrixXf connectionMatrix = Eigen::MatrixXf::Identity( layerNeuronCounts[layerNeuronCounts.size() - 1], layerNeuronCounts[layerNeuronCounts.size() - 1] );
	Eigen::VectorXf biasVector = Eigen::VectorXf::Random( layerNeuronCounts[layerNeuronCounts.size() - 1] );
	layers_[layerNeuronCounts.size() - 1] = Layer( connectionMatrix, biasVector );
}

CSimpleNN::CSimpleNN( const SimpleNNData& data ) {
	auto* layerData = data.getLayerNeuronCounts();
	layers_ = std::vector<Layer>( data.size() );

	for( size_t i = 0; i < data.size() - 1; i++ ) {
		Eigen::MatrixXf connectionMatrix = Eigen::MatrixXf::Random( layerData[i + 1], layerData[i] );
		Eigen::VectorXf biasVector = Eigen::VectorXf::Random( layerData[i] );
		layers_[i] = Layer( connectionMatrix, biasVector );
	}

	Eigen::MatrixXf connectionMatrix = Eigen::MatrixXf::Identity( layerData[data.size() - 1], layerData[data.size() - 1] );
	Eigen::VectorXf biasVector = Eigen::VectorXf::Random( layerData[data.size() - 1] );
	layers_[data.size() - 1] = Layer( connectionMatrix, biasVector );
}

Eigen::VectorXf CSimpleNN::getOutput( const Eigen::VectorXf& input ) const {
	Eigen::VectorXf output = input;

	for( auto& layer : layers_ ) {
		output = layer.getOutput( output );
	}

	return output;
}

CSimpleNN_ptr CSimpleNN::copyAndMutate(float chance, float range) const {
	std::vector<Layer> layers = std::vector<Layer>(layers_.size());

	for (size_t i = 0; i < layers_.size(); i++) {
		layers[i] = layers_[i].copyAndMutate(chance, range);
	}

	return CSimpleNN_ptr(new CSimpleNN(layers));
}

CSimpleNN_ptr CSimpleNN::copy() const {
	std::vector<Layer> layers = std::vector<Layer>( layers_.size() );

	for( size_t i = 0; i < layers_.size(); i++ ) {
		layers[i] = layers_[i];
	}

	return CSimpleNN_ptr( new CSimpleNN( layers ) );
}

uint32_t CSimpleNN::getOutputSize() const {
	return layers_.front().getInputSize();
}

uint32_t CSimpleNN::getInputSize() const {
	return layers_.back().getOutputSize();
}
