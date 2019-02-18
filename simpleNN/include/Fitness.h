#pragma once
#include <vector>

typedef unsigned int Uint32;


struct Fitness {
	Fitness() {
	}

	Fitness( Uint32 size ) {
		fitness_ = std::vector<float>( size );
		for ( size_t i = 0; i < size; i++ ) {
			fitness_[i] = std::numeric_limits<float>::max();
		}
	}

	Fitness( Uint32 size, float initializer ) {
		fitness_ = std::vector<float>( size );
		for ( size_t i = 0; i < size; i++ ) {
			fitness_[i] = initializer;
		}
	}

	Fitness( std::vector<float>&& diff ) : fitness_( std::move( diff ) ){
	}

	Uint32 size() const { return fitness_.size(); }
	const std::vector<float>& fitness() const { return fitness_; }
	
	float getDifference() {
		float ret = 0;
		for ( size_t i = 0; i < fitness_.size(); i++ ) {
			ret += fitness_[i];
		}
		return ret;
	}

	inline Fitness& operator +=( const Fitness& rhs ) {
		if ( this->size() != rhs.size() ) {
			throw std::invalid_argument( "size of lhs and rsh are not equal" );
		}

		for ( size_t i = 0; i < this->size(); i++ ) {
			this->fitness_[i] += rhs.fitness()[i];
		}

		return *this;
	}

private:
	std::vector<float> fitness_;
};

inline bool operator <( const Fitness& lhs, const Fitness& rhs ) {
	if ( lhs.size() != rhs.size() ) {
		throw std::invalid_argument( "size of lhs and rsh are not equal" );
	}

	for ( size_t i = 0; i < lhs.size(); i++ ) {
		if ( lhs.fitness()[i] > rhs.fitness()[i] ) {
			return false;
		}
	}

	return true;
}
inline bool operator >( const Fitness& lhs, const Fitness& rhs ) { return operator <( rhs, lhs ); }
inline bool operator <=( const Fitness& lhs, const Fitness& rhs ) { return !operator >( lhs, rhs ); }
inline bool operator >=( const Fitness& lhs, const Fitness& rhs ) { return !operator <( lhs, rhs ); }

inline Fitness operator +( const Fitness& lhs, const Fitness& rhs ) {
	if ( lhs.size() != rhs.size() ) {
		throw std::invalid_argument( "size of lhs and rsh are not equal" );
	}

	std::vector<float> diff( lhs.size() );
	for ( size_t i = 0; i < diff.size(); i++ ) {
		diff[i] = lhs.fitness()[i] + rhs.fitness()[i];
	}

	return Fitness( std::move( diff ) );
}