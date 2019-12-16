#pragma once

#include <memory>
#include <vector>
#include <CSimpleNN.h>
#include "spdlog/sinks/basic_file_sink.h"

#include "Fitness.h"


class CSimpleNNTrainer {
public:
	CSimpleNNTrainer( uint32_t generationSize, float chance, float range ) : generationSize_( generationSize ), chance_( chance ), range_( range ), hitCounter_( std::vector<uint32_t>( generationSize)) {}

	CSimpleNNTrainer( const CSimpleNNTrainer& other ) = delete;
	CSimpleNNTrainer& operator=( const CSimpleNNTrainer& other ) = delete;

	CSimpleNNTrainer( CSimpleNNTrainer&& other ) = default;
	CSimpleNNTrainer& operator=( CSimpleNNTrainer&& other ) = default;

	void generateNextGeneration();
	void generateNextGeneration( const CSimpleNN& network );
	void test( const Eigen::VectorXf& input, const Eigen::VectorXf& expectedOutput );

	const CSimpleNN* getCurrentBest() const;
	const Fitness& getCurrentBestFitness() const;

	std::vector<float> getHitPercentage() const;
	std::vector<Fitness> getGenerationFitness() const;

private:
	std::vector<std::pair<CSimpleNN_sptr, Fitness>> generation_;
	uint32_t generationSize_;

	float chance_;
	float range_;

	uint32_t testCounter_ = 0;
	std::vector<uint32_t> hitCounter_;

};
