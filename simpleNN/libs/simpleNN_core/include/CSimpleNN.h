#pragma once

#include <memory>
#include <vector>

#include "Layer.h"
#include "ISimpleNN.h"


class CSimpleNN : public ISimpleNN {
public:
	CSimpleNN( std::vector<Layer> layers );

	Eigen::VectorXf getOutput( const Eigen::VectorXf& input ) const override;
	ISimpleNN_ptr copyAndMutate(float chance, float range) const override;

private:
	std::vector<Layer> layers_;

};


typedef std::unique_ptr<CSimpleNN> CSimpleNN_ptr;
typedef std::shared_ptr<CSimpleNN> CSimpleNN_sptr;
