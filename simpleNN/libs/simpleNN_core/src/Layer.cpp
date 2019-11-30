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
	return float(rand()) / (float(RAND_MAX) + 1.f);
}

Layer Layer::copyAndMutate(float chance, float range) const {
	Eigen::VectorXf bias = bias_;

	// Initialize vector with values between -1 and 1
	Eigen::VectorXf biasMutation = Eigen::VectorXf::Random(bias.size());

	srand(static_cast<unsigned int>(clock()));

	// Because not every value should be mutated, we get a random number for each entry and only keep the entry if the random number is below the given chance. Otherwise its set to zero
	for (size_t i = 0; i < bias.size(); i++) {
		if (randomFloat() > chance) {
			biasMutation(i) = 0;
		}
	}

	// Scale every entry to be in the given range
	biasMutation *= Eigen::VectorXf(biasMutation.size()).setConstant(range);

	// Apply the mutation to our bias
	bias += biasMutation;
}
