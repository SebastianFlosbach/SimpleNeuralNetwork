#pragma once

#include <memory>
#include <vector>

#include "Layer.h"
#include <SimpleNNData.h>


class CSimpleNN;

typedef std::unique_ptr<CSimpleNN> CSimpleNN_ptr;
typedef std::shared_ptr<CSimpleNN> CSimpleNN_sptr;


class CSimpleNN {
	friend class SimpleNNWriter;
public:
	CSimpleNN() = default;
	CSimpleNN( const std::vector<Layer>& layers );
	CSimpleNN( const std::vector<uint32_t>& layerNeuronCounts );
	CSimpleNN( const SimpleNNData& data );

	Eigen::VectorXf getOutput( const Eigen::VectorXf& input ) const;

	CSimpleNN_ptr copyAndMutate(float chance, float range) const;
	CSimpleNN_ptr copy() const;

	uint32_t getOutputSize() const;
	uint32_t getInputSize() const;

private:
	std::vector<Layer> layers_;

};
