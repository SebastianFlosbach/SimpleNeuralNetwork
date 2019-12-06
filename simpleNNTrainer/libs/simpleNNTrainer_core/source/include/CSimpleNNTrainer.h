#pragma once

#include <memory>
#include <vector>
#include <CSimpleNN.h>

#include "Fitness.h"


class CSimpleNNTrainer {
public:
	CSimpleNNTrainer( uint32_t generationSize, float chance, float range ) : generationSize_( generationSize ), chance_( chance ), range_( range ) {
	}

	CSimpleNNTrainer( const CSimpleNNTrainer& other ) = delete;
	CSimpleNNTrainer& operator=( const CSimpleNNTrainer& other ) = delete;

	CSimpleNNTrainer( CSimpleNNTrainer&& other ) = default;
	CSimpleNNTrainer& operator=( CSimpleNNTrainer&& other ) = default;

	void generateNextGeneration();
	void generateNextGeneration( const CSimpleNN& network );
	void test(const Eigen::VectorXf& input, const Eigen::VectorXf& expectedOutput);

	const CSimpleNN* getCurrentBest() const;

private:
	std::vector<std::pair<CSimpleNN_ptr, Fitness>> generation_;
	uint32_t generationSize_;

	float chance_;
	float range_;

};
