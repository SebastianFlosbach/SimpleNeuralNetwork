#pragma once

#include <memory>
#include <vector>

#include <eigen/Dense>
#include "Layer.h"


class CSimpleNN {
public:
	CSimpleNN( std::vector<Layer> layers );

	Eigen::VectorXf getOutput( const Eigen::VectorXf& input );

private:
	std::vector<Layer> layers_;

};


typedef std::unique_ptr<CSimpleNN> CSimpleNN_ptr;
typedef std::shared_ptr<CSimpleNN> CSimpleNN_sptr;
