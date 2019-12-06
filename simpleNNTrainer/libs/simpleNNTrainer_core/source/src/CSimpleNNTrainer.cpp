#include "CSimpleNNTrainer.h"

#include "Fitness.h"


void CSimpleNNTrainer::generateNextGeneration() {
	std::vector<std::pair<CSimpleNN_ptr, Fitness>> generation = std::vector<std::pair<CSimpleNN_ptr, Fitness>>( generationSize_ );

	const CSimpleNN* bestNetwork = getCurrentBest();

	for( uint32_t i = 0; i < generationSize_; i++ ) {
		generation[i] = std::move(std::pair<CSimpleNN_ptr, Fitness>( 
			std::move(bestNetwork->copyAndMutate( chance_, range_ )), 
			std::move(Fitness(bestNetwork->getInputSize()))
		));
	}

	generation_ = generation;
}

void CSimpleNNTrainer::generateNextGeneration(const CSimpleNN& network) {
	std::vector<std::pair<CSimpleNN_ptr, Fitness>> generation = std::vector<std::pair<CSimpleNN_ptr, Fitness>>( generationSize_ );

	for( uint32_t i = 0; i < generationSize_; i++ ) {
		generation[i] = std::move(std::pair<CSimpleNN_ptr, Fitness>(
			std::move( network.copyAndMutate( chance_, range_ ) ),
			std::move( Fitness( network.getInputSize() ) )
		));
	}

	generation_ = generation;
}

void CSimpleNNTrainer::test( const Eigen::VectorXf& input, const Eigen::VectorXf& expectedOutput ) {
	for( uint32_t i = 0; i < generationSize_; i++ ) {
		auto output = generation_[i].first->getOutput( input );
		Fitness currentFitness = Fitness( output, expectedOutput );
		generation_[i].second += currentFitness;
	}
}

const CSimpleNN* CSimpleNNTrainer::getCurrentBest() const {
	size_t bestIndex = 0;

	for( size_t i = 1; i < generation_.size(); i++ ) {
		if( generation_[i].second <= generation_[bestIndex].second ) {
			bestIndex = i;
		}
	}

	return generation_[bestIndex].first.get();
}
