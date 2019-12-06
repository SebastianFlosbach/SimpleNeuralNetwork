#pragma once

#include <eigen/Dense>


class Layer {
public:
	Layer() = default;
	Layer( const Eigen::MatrixXf connections, const Eigen::VectorXf bias );
	Layer(const Eigen::VectorXf bias);

	Eigen::VectorXf getOutput( const Eigen::VectorXf& input ) const;
	Layer copyAndMutate(float chance, float range) const;

	uint32_t getInputSize() const;
	uint32_t getOutputSize() const;

private:
	Eigen::MatrixXf connections_;
	Eigen::VectorXf bias_;

};
