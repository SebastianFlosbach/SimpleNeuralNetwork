#include "Fitness.h"


bool Fitness::operator>( const IFitness& right ) {
	for( Eigen::Index i = 0; i < difference_.size(); i++ ) {
		if( difference_[i] > static_cast<const Fitness&>(right).difference_[i] ) {
			return true;
		}
	}

	return false;
}

bool Fitness::operator<( const IFitness& right ) {
	for( Eigen::Index i = 0; i < difference_.size(); i++ ) {
		if( difference_[i] >= static_cast<const Fitness&>(right).difference_[i] ) {
			return false;
		}
	}

	return true;
}

bool Fitness::operator>=( const IFitness& right ) {
	for( Eigen::Index i = 0; i < difference_.size(); i++ ) {
		if( difference_[i] >= static_cast<const Fitness&>(right).difference_[i] ) {
			return true;
		}
	}

	return false;
}

bool Fitness::operator<=( const IFitness& right ) {
	for( Eigen::Index i = 0; i < difference_.size(); i++ ) {
		if( difference_[i] > static_cast<const Fitness&>(right).difference_[i] ) {
			return false;
		}
	}

	return true;
}
