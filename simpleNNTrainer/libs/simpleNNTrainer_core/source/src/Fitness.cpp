#include "Fitness.h"


Fitness& Fitness::operator+=( const Fitness& right ) {
	difference_ += static_cast<const Fitness&>(right).difference_;
	return *this;
}

bool Fitness::operator>( const Fitness& right ) {
	for( Eigen::Index i = 0; i < difference_.size(); i++ ) {
		if( difference_[i] > static_cast<const Fitness&>(right).difference_[i] ) {
			return true;
		}
	}

	return false;
}

bool Fitness::operator<( const Fitness& right ) {
	for( Eigen::Index i = 0; i < difference_.size(); i++ ) {
		if( difference_[i] >= static_cast<const Fitness&>(right).difference_[i] ) {
			return false;
		}
	}

	return true;
}

bool Fitness::operator>=( const Fitness& right ) {
	for( Eigen::Index i = 0; i < difference_.size(); i++ ) {
		if( difference_[i] >= static_cast<const Fitness&>(right).difference_[i] ) {
			return true;
		}
	}

	return false;
}

bool Fitness::operator<=( const Fitness& right ) {
	for( Eigen::Index i = 0; i < difference_.size(); i++ ) {
		if( difference_[i] > static_cast<const Fitness&>(right).difference_[i] ) {
			return false;
		}
	}

	return true;
}
