#pragma once

#include <eigen/Dense>


class Fitness {
public:
	Fitness(uint32_t size) noexcept : difference_(Eigen::VectorXf::Zero(size)) {
	}

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

	Fitness& operator+=( const Fitness& right );

	bool operator>( const Fitness& right );
	bool operator<( const Fitness& right );

	bool operator>=( const Fitness& right );
	bool operator<=( const Fitness& right );

private:
	Eigen::VectorXf difference_;

};
