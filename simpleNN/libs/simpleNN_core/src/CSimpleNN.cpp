#include "CSimpleNN.h"

CSimpleNN::CSimpleNN( std::vector<Layer> layers ) : layers_( layers ) {
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
