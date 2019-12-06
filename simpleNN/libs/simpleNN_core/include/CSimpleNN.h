#pragma once

#include <memory>
#include <vector>

#include "Layer.h"
#include "CSimpleNN.h"


class CSimpleNN;

typedef std::unique_ptr<CSimpleNN> CSimpleNN_ptr;
typedef std::shared_ptr<CSimpleNN> CSimpleNN_sptr;


class CSimpleNN {
public:
	CSimpleNN( std::vector<Layer> layers );

	Eigen::VectorXf getOutput( const Eigen::VectorXf& input ) const;
	CSimpleNN_ptr copyAndMutate(float chance, float range) const;

	uint32_t getOutputSize() const;
	uint32_t getInputSize() const;

private:
	std::vector<Layer> layers_;

};
