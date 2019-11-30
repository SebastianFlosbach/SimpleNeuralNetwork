#include "Layer.h"

#include <cstdlib>
#include <ctime>
#include <math.h>


Eigen::VectorXf sigmoid(const Eigen::VectorXf& input);

Layer::Layer(Eigen::MatrixXf connections, Eigen::VectorXf bias) : connections_(connections), bias_(bias) {
}

Layer::Layer(const Eigen::VectorXf bias) {
	bias_ = bias;
	connections_ = Eigen::MatrixXf(bias.size(), bias.size());
	connections_.setIdentity();
}

Eigen::VectorXf Layer::getOutput(const Eigen::VectorXf& input) const
{
	return static_cast<Eigen::VectorXf>(connections_ * sigmoid(input + bias_));
}

Eigen::VectorXf sigmoid(const Eigen::VectorXf& input) {
	Eigen::VectorXf result(input.size());

	for (Eigen::Index i = 0; i < input.size(); i++) {
		result(i) = 1 / (1 + powf(2.f, input(i)));
	}

	return result;
}

float randomFloat() {
	return float(rand()) / float(RAND_MAX);
}

float randomFloat(float min, float max) {
	return (max - min) * (float(rand()) / float(RAND_MAX)) + min;
}

Layer Layer::copyAndMutate(float chance, float range) const {
	Eigen::VectorXf bias = bias_;
	Eigen::MatrixXf connections = connections_;

	srand(static_cast<unsigned int>(clock()));

	for (Eigen::Index i = 0; i < bias.size(); i++) {
		if (randomFloat() <= chance) {
			bias(i) += randomFloat(-range, range);
		}
	}

	for (Eigen::Index x = 0; x < connections.cols(); x++) {
		for (Eigen::Index y = 0; y < connections.rows(); y++) {
			if (randomFloat() <= chance) {
				connections(y, x) += randomFloat(-range, range);
			}
		}
	}

	return Layer(connections, bias);
}
