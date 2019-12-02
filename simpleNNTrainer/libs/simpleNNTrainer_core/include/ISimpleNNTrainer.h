#pragma once

#include <memory>
#include <vector>

#include <ISimpleNN.h>


class ISimpleNNTrainer {
public:
	ISimpleNNTrainer() = default;

	ISimpleNNTrainer( const ISimpleNNTrainer& other ) = delete;
	ISimpleNNTrainer& operator=( const ISimpleNNTrainer& other ) = delete;

	ISimpleNNTrainer( ISimpleNNTrainer&& other ) = default;
	ISimpleNNTrainer& operator=( ISimpleNNTrainer&& other ) = default;

	virtual void generateNextGeneration() = 0;
	virtual void test( const Eigen::VectorXf& input, const Eigen::VectorXf& expectedOutput ) = 0;

	virtual const ISimpleNN* getCurrentBest() const = 0;

};
