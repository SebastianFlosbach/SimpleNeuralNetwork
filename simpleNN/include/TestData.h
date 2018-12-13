#pragma once
#include <map>
#include <vector>

#include "TestDataPair.h"


typedef unsigned int Uint32;

struct TestData {
	TestData( Uint32 inputSize, Uint32 outputSize ) : inputSize_( inputSize ), outputSize_( outputSize ) {
	}
	
	inline Uint32 inputSize() const { return inputSize_; }
	inline Uint32 outputSize() const { return outputSize_; }
	inline Uint32 size() const { return data_.size(); }

	void addTestDataPair( TestDataPair&& dataPair ) {
		data_.push_back( std::move( dataPair ) );
	}

	const std::vector<float>& getInput( Uint32 index ) const {
		return data_[index].input();
	}

	const std::vector<float>& getOutput( Uint32 index ) const {
		return data_[index].output();
	}

private:
	Uint32 inputSize_;
	Uint32 outputSize_;

	std::vector<TestDataPair> data_;
};