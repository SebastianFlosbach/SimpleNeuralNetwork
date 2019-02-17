#pragma once
#include "Network.h"
#include "TestData.h"
#include "Fitness.h"

#include <thread>

typedef unsigned int Uint32;

class EvolutionHandler {
	NetworkPtr bestNetwork_;
	Fitness bestFitness_;
	TestData testData_;

	Uint32 threadCount_;

	Fitness calculateFitness( std::vector<float> input, std::vector<float> output ) const;

public:
	EvolutionHandler( NetworkPtr&& network ) : bestNetwork_( std::move( network ) ), testData_( bestNetwork_->inputSize(), bestNetwork_->outputSize() ), bestFitness_( bestNetwork_->outputSize() ) {
	}

	void addTestData( TestData&& testData ) {
		testData_ = std::move( testData );
	}

	Fitness& getFitness() {
		return bestFitness_;
	}

	Network& getNetwork() {
		return *bestNetwork_.get();
	}

	inline void setThreadCount( Uint32 threadCount ) {
		threadCount_ = threadCount;
	}

	void evolveNextGeneration( Uint32 generationSize, float chance, float range );
};