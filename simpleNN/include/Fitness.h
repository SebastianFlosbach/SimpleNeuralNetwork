#pragma once
#include <vector>

typedef unsigned int Uint32;

inline bool operator <( const Fitness& lhs, const Fitness& rhs ) {
	if ( lhs.size() != rhs.size() ) {
		throw std::invalid_argument( "size of lhs and rsh are not equal" );
	}

	for ( size_t i = 0; i < lhs.size(); i++ ) {
		if ( lhs.fitness_[i] >= rhs.fitness[i] ) {
			return false;
		}
	}

	return true;
}
inline bool operator >( const Fitness& lhs, const Fitness& rhs ) { return operator <( rhs, lhs ); }
inline bool operator <=( const Fitness& lhs, const Fitness& rhs ) { return !operator >( lhs, rhs ); }
inline bool operator >=( const Fitness& lhs, const Fitness& rhs ) { return !operator <( lhs, rhs ); }


struct Fitness {

	Uint32 size() const { return fitness_.size(); }

private:
	std::vector<float> fitness_;
};