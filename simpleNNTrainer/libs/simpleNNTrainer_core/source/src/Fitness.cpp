#include "Fitness.h"


float Fitness::totalDifference() const {
	float totalDifference = 0;

	for( size_t i = 0; i < difference_.size(); i++ ) {
		totalDifference += difference_[i];
	}

	return totalDifference;
}

Fitness& Fitness::operator+=( const Fitness& right ) {
	difference_ += right.difference_;
	return *this;
}

bool Fitness::operator>( const Fitness& right ) const {
	for( Eigen::Index i = 0; i < difference_.size(); i++ ) {
		if( difference_[i] > right.difference_[i] ) {
			return true;
		}
	}

	return false;
}

bool Fitness::operator<( const Fitness& right ) const {
	for( Eigen::Index i = 0; i < difference_.size(); i++ ) {
		if( difference_[i] >= right.difference_[i] ) {
			return false;
		}
	}

	return true;
}

bool Fitness::operator>=( const Fitness& right ) const {
	for( Eigen::Index i = 0; i < difference_.size(); i++ ) {
		if( difference_[i] >= right.difference_[i] ) {
			return true;
		}
	}

	return false;
}

bool Fitness::operator<=( const Fitness& right ) const {
	for( Eigen::Index i = 0; i < difference_.size(); i++ ) {
		if( difference_[i] > right.difference_[i] ) {
			return false;
		}
	}

	return true;
}
