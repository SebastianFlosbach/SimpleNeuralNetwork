#include "Layer.h"

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
