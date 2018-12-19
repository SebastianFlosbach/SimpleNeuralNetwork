#pragma once
#include <vector>

typedef unsigned int Uint32;


struct Fitness {
	Fitness() {
	}

	Fitness( std::vector<float>&& diff ) : fitness_( std::move( diff ) ){
	}

	Uint32 size() const { return fitness_.size(); }
	const std::vector<float>& fitness() const { return fitness_; }

private:
	std::vector<float> fitness_;
};

inline bool operator <( const Fitness& lhs, const Fitness& rhs ) {
	if ( lhs.size() != rhs.size() ) {
		throw std::invalid_argument( "size of lhs and rsh are not equal" );
	}

	for ( size_t i = 0; i < lhs.size(); i++ ) {
		if ( lhs.fitness()[i] >= rhs.fitness()[i] ) {
			return false;
		}
	}

	return true;
}
inline bool operator >( const Fitness& lhs, const Fitness& rhs ) { return operator <( rhs, lhs ); }
inline bool operator <=( const Fitness& lhs, const Fitness& rhs ) { return !operator >( lhs, rhs ); }
inline bool operator >=( const Fitness& lhs, const Fitness& rhs ) { return !operator <( lhs, rhs ); }