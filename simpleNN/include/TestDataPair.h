#pragma once
#include <vector>


struct TestDataPair {
	TestDataPair( std::vector<float>&& input, std::vector<float>&& output ) : input_( std::move( input ) ), output_( std::move( output ) ) {
	}

	const std::vector<float>& input() const { return input_; }
	const std::vector<float>& output() const { return output_; }

private:
	std::vector<float> input_;
	std::vector<float> output_;
};