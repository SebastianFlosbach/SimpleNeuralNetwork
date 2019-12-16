#pragma once

#include <eigen/Dense>


class Fitness {
public:
	Fitness() noexcept : difference_(Eigen::VectorXf::Zero(0)) {
	}

	Fitness(uint32_t size) noexcept : difference_(Eigen::VectorXf::Zero(size)) {
	}

	Fitness( uint32_t size, float initializer ) noexcept : difference_( Eigen::VectorXf::Zero( size ) ) {
		for( Eigen::Index i = 0; i < size; i++ ) {
			difference_( i ) = initializer;
		}
	}

	Fitness( const Eigen::VectorXf& difference ) noexcept : difference_( difference ) {
	}

	Fitness( const Eigen::VectorXf& value, const Eigen::VectorXf& expected ) {
		if( value.size() != expected.size() ) {
			throw std::invalid_argument("Size of vectors must be the same!");
		}

		difference_ = Eigen::VectorXf( value.size() );

		for( Eigen::Index i = 0; i < value.size(); i++ ) {
				difference_[i] = (value[i] - expected[i]) * (value[i] - expected[i]);
		}
	}

	float totalDifference() const;

	Fitness& operator+=( const Fitness& right );

	bool operator>( const Fitness& right ) const;
	bool operator<( const Fitness& right ) const;

	bool operator>=( const Fitness& right ) const;
	bool operator<=( const Fitness& right ) const;

private:
	Eigen::VectorXf difference_;

};
