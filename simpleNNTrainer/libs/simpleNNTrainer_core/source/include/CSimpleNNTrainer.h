#pragma once

#include "ISimpleNNTrainer.h"

#include <memory>
#include <map>

#include "IFitness.h"


class CSimpleNNTrainer : public ISimpleNNTrainer {
public:
	CSimpleNNTrainer( uint32_t generationSize, float chance, float range ) : generationSize_( generationSize ), chance_( chance ), range_( range ) {
	}

	CSimpleNNTrainer( const CSimpleNNTrainer& other ) = delete;
	CSimpleNNTrainer& operator=( const CSimpleNNTrainer& other ) = delete;

	CSimpleNNTrainer( CSimpleNNTrainer&& other ) = default;
	CSimpleNNTrainer& operator=( CSimpleNNTrainer&& other ) = default;

	void generateNextGeneration() override;
	void test(const Eigen::VectorXf& input, const Eigen::VectorXf& expectedOutput) override;

	const ISimpleNN* getCurrentBest() const override;

private:
	std::map<ISimpleNN_ptr, IFitness> generation_;
	uint32_t generationSize_;

	float chance_;
	float range_;

};
