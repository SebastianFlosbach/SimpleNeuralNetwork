#pragma once

#include <eigen/Dense>
#include <memory>


class ISimpleNN;

typedef std::unique_ptr<ISimpleNN> ISimpleNN_ptr;
typedef std::shared_ptr<ISimpleNN> ISimpleNN_sptr;

class ISimpleNN {
public:
	virtual Eigen::VectorXf getOutput(const Eigen::VectorXf& input) const = 0;
	virtual ISimpleNN_ptr copyAndMutate(float chance, float range) const = 0;

};
