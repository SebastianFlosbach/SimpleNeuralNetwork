#include "gtest/gtest.h"

#include <iostream>

#include <simpleNN.h>


TEST(simpleNN_test, Init) {
	SimpleNNFactory* pFactory = CreateSimpleNNFactory();

	
	DestroySimpleNNFactory(pFactory);
}
