#include "gtest/gtest.h"

#include <simpleNN.h>
#include <Eigen/Dense>


TEST( simpleNN_test, Init ) {
	Eigen::VectorXf b1();

	b1( 1 ) = 0;

	std::vector<Layer> layers = std::vector<Layer>();

	auto net = create( 1, layers.data() );
}
