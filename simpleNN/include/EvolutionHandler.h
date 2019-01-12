#pragma once
#include "Network.h"
#include "TestData.h"
#include "Fitness.h"

typedef unsigned int Uint32;

class EvolutionHandler {
	NetworkPtr bestNetwork_;
	Fitness bestFitness_;
	TestData testData_;

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

	void evolveNextGeneration( Uint32 generationSize, float chance, float range );
};