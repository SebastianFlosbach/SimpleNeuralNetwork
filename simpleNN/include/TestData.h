#pragma once
#include <map>
#include <vector>


typedef unsigned int Uint32;
typedef std::pair<std::vector<float>, std::vector<float>> TestDataPair ;

struct TestData {
	TestData( Uint32 inputSize, Uint32 outputSize ) : inputSize_( inputSize ), outputSize_( outputSize ) {
	}

	inline Uint32 inputSize() const { return inputSize_; }
	inline Uint32 outputSize() const { return outputSize_; }
	inline Uint32 size() const { return data_.size(); }

	void addTestDataPair( TestDataPair& data ) {
		data_.insert( std::move( data ) );
	}

	TestDataPair& getTestDataPair( Uint32 index ) {
		return data_[index];
	}

private:
	Uint32 inputSize_;
	Uint32 outputSize_;

	std::map<std::vector<float>, std::vector<float>> data_;
};