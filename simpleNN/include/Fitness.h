#pragma once
#include <vector>

inline bool operator <( const Fitness& lhs, const Fitness& rhs ) {
	
}
inline bool operator >( const Fitness& lhs, const Fitness& rhs ) { return operator <( rhs, lhs ); }
inline bool operator <=( const Fitness& lhs, const Fitness& rhs ) { return !operator >( lhs, rhs ); }
inline bool operator >=( const Fitness& lhs, const Fitness& rhs ) { return !operator <( lhs, rhs ); }


struct Fitness {

private:
	std::vector<float> fitness_;
};