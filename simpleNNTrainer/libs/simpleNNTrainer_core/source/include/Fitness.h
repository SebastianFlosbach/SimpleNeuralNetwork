#pragma once

#include "IFitness.h"
#include <eigen/Dense>


class Fitness : public IFitness {
public:
	Fitness( const Eigen::VectorXf& difference ) noexcept : difference_( difference ) {
	}

	Fitness( const Eigen::VectorXf& value, const Eigen::VectorXf& expected ) {
		if( value.size() != expected.size() ) {
			throw std::invalid_argument("Size of vectors must be the same!");
		}

		difference_ = Eigen::VectorXf( value.size() );

		for( Eigen::Index i = 0; i < value.size(); i++ ) {
			difference_[i] = expected[i] - value[i];
		}
	}

	bool operator>( const IFitness& right ) override;
	bool operator<( const IFitness& right ) override;

	bool operator>=( const IFitness& right ) override;
	bool operator<=( const IFitness& right ) override;

private:
	Eigen::VectorXf difference_;

};
