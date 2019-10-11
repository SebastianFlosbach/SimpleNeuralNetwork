#include "CSimpleNN.h"

CSimpleNN::CSimpleNN( std::vector<Layer> layers ) : layers_( layers ) {
}

Eigen::VectorXf CSimpleNN::getOutput( const Eigen::VectorXf& input ) {
	Eigen::VectorXf output = input;

	for( auto& layer : layers_ ) {
		output = layer.getOutput( output );
	}

	return output;
}
