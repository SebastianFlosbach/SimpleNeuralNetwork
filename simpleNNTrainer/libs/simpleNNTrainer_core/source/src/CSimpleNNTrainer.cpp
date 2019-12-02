#include "CSimpleNNTrainer.h"


void CSimpleNNTrainer::generateNextGeneration() {
	std::vector<ISimpleNN_ptr> generation = std::vector<ISimpleNN_ptr>( generationSize_ );


	for( uint32_t i = 1; i < generationSize_; i++ ) {
		generation[i] = generation[0]->copyAndMutate( chance_, range_ );
	}
}

void CSimpleNNTrainer::test( const Eigen::VectorXf& input, const Eigen::VectorXf& expectedOutput ) {

}

const ISimpleNN* CSimpleNNTrainer::getCurrentBest() const {
	ISimpleNN* best = generation_[0].first.get();

	for( size_t i = 1; i < generation_.size(); i++ ) {
		
	}
}
