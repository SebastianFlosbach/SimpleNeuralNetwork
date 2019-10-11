#pragma once

#include <eigen/Dense>


class Layer {
public:
	Layer() = default;
	Layer( const Eigen::MatrixXf connections, const Eigen::VectorXf bias );

	Eigen::VectorXf getOutput( const Eigen::VectorXf& input ) const;

private:
	Eigen::MatrixXf connections_;
	Eigen::VectorXf bias_;

};