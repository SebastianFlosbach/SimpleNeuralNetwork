#include "random_helper.h"

float getRandFloat( float lower, float higher ) {
	auto percentage = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
	return lower + percentage * (higher - lower);
}