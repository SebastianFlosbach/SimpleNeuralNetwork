#include "gtest/gtest.h"

#include <iostream>

#include <simpleNN.h>
#include <Eigen/Dense>


TEST(simpleNN_test, Init) {
	Eigen::MatrixXf c1(2, 2);
	c1(0, 0) = 1;
	c1(0, 1) = 2;
	c1(1, 0) = 3;
	c1(1, 1) = 4;

	std::cout << c1 << std::endl;

	Eigen::VectorXf b1(2);
	b1(0) = 1;
	b1(1) = 2;

	Layer l1 = Layer(c1, b1);

	Eigen::VectorXf b2(2);
	b2(0) = 3;
	b2(1) = 4;

	Layer l2 = Layer(b2);

	std::vector<Layer> layers = std::vector<Layer>();
	layers.push_back(l1);
	layers.push_back(l2);

	auto net = SimpleNN::create(2, layers.data());

	Eigen::VectorXf input(2);
	input(0) = 1;
	input(1) = 2;

	auto output = net->getOutput(input);

	std::cout << output << std::endl;
}
