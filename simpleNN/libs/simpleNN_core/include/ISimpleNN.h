#pragma once

#include <eigen/Dense>
#include <memory>


class ISimpleNN {
public:
	virtual Eigen::VectorXf getOutput(const Eigen::VectorXf& input) = 0;

};


typedef std::unique_ptr<ISimpleNN> ISimpleNN_ptr;
typedef std::shared_ptr<ISimpleNN> ISimpleNN_sptr;
