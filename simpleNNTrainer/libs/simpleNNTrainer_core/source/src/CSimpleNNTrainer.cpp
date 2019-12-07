#include "CSimpleNNTrainer.h"

#include "Fitness.h"


bool isHit( const Eigen::VectorXf& value, uint32_t expectedNumber ) {
	uint32_t valueIndex  = 0;

	for( Eigen::Index i = 1; i < value.size(); i++ ) {
		if( value( i ) > value( valueIndex ) ) {
			valueIndex = i;
		}
	}

	return valueIndex == expectedNumber;
}

uint32_t vectorToNumber( const Eigen::VectorXf& vec );

void CSimpleNNTrainer::generateNextGeneration() {
	std::vector<std::pair<CSimpleNN_sptr, Fitness>> generation = std::vector<std::pair<CSimpleNN_sptr, Fitness>>( generationSize_ );

	const CSimpleNN* bestNetwork = getCurrentBest();

	generation[0] = std::move( std::pair<CSimpleNN_sptr, Fitness>(
		std::move( bestNetwork->copy() ),
		std::move( Fitness( bestNetwork->getInputSize() ) )
		) );

	for( uint32_t i = 1; i < generationSize_; i++ ) {
		generation[i] = std::move(std::pair<CSimpleNN_sptr, Fitness>( 
			std::move(bestNetwork->copyAndMutate( chance_, range_ )), 
			std::move(Fitness(bestNetwork->getInputSize()))
		));
	}

	generation_ = generation;

	testCounter_ = 0;
	hitCounter_ = std::vector<uint32_t>(generationSize_);
}

void CSimpleNNTrainer::generateNextGeneration(const CSimpleNN& network) {
	std::vector<std::pair<CSimpleNN_sptr, Fitness>> generation = std::vector<std::pair<CSimpleNN_sptr, Fitness>>( generationSize_ );

	generation[0] = std::move( std::pair<CSimpleNN_sptr, Fitness>(
		std::move( network.copy() ),
		std::move( Fitness( network.getInputSize() ) )
		) );

	for( uint32_t i = 1; i < generationSize_; i++ ) {
		generation[i] = std::move(std::pair<CSimpleNN_sptr, Fitness>(
			std::move( network.copyAndMutate( chance_, range_ ) ),
			std::move( Fitness( network.getInputSize() ) )
		));
	}

	generation_ = generation;

	testCounter_ = 0;
	hitCounter_ = std::vector<uint32_t>( generationSize_ );
}

void CSimpleNNTrainer::test( const Eigen::VectorXf& input, const Eigen::VectorXf& expectedOutput ) {
	for( uint32_t i = 0; i < generationSize_; i++ ) {
		auto output = generation_[i].first->getOutput( input );
		Fitness currentFitness = Fitness( output, expectedOutput );
		generation_[i].second += currentFitness;

		if( isHit( output, vectorToNumber( expectedOutput ) ) ) {
			hitCounter_[i]++;
		}
	}

	testCounter_++;
}

const CSimpleNN* CSimpleNNTrainer::getCurrentBest() const {
	size_t bestIndex = 0;

	for( size_t i = 1; i < generation_.size(); i++ ) {
		if( generation_[i].second < generation_[bestIndex].second ) {
			bestIndex = i;
		}
	}

	return generation_[bestIndex].first.get();
}

std::vector<float> CSimpleNNTrainer::getHitPercentage() const {
	std::vector<float> hitPercentage = std::vector<float>( generationSize_ );

	for( size_t i = 0; i < generationSize_; i++ ) {
		hitPercentage[i] = (float)hitCounter_[i] / (float)testCounter_;
	}

	return hitPercentage;
}

std::vector<Fitness> CSimpleNNTrainer::getGenerationFitness() const {
	std::vector<Fitness> fitness = std::vector<Fitness>(generationSize_);

	for( size_t i = 0; i < generationSize_; i++ ) {
		fitness[i] = generation_[i].second;
	}

	return fitness;
}
