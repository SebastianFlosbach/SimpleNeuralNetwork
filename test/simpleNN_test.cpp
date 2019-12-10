#include "gtest/gtest.h"

#include <iostream>

#include <simpleNN.h>
#include <SimpleNNData.h>


TEST(simpleNN_test, CreateSimpleNNData) {
	SimpleNNData layerData = SimpleNNData();
	layerData.addLayer(2);
	layerData.addLayer(1);
	layerData.addLayer(4);
	layerData.addLayer(3);

	ASSERT_EQ(layerData.size(), 4);

	auto* pLayerData = layerData.getLayerNeuronCounts();

	ASSERT_EQ(pLayerData[0], 2);
	ASSERT_EQ(pLayerData[1], 1);
	ASSERT_EQ(pLayerData[2], 4);
	ASSERT_EQ(pLayerData[3], 3);
}

TEST(simpleNN_test, Negative_CreateSimpleNNData) {
	SimpleNNData layerData = SimpleNNData();
	EXPECT_THROW(layerData.addLayer(0), std::invalid_argument);
}

TEST(simpleNN_test, CreateSimpleNN) {
	SimpleNNData layerData = SimpleNNData();
	layerData.addLayer(2);
	layerData.addLayer(1);
	layerData.addLayer(4);
	layerData.addLayer(3);

	CSimpleNN_ptr nn = SimpleNN::CreateSimpleNN(layerData);
}

TEST(simpleNN_test, GetOutput) {
	SimpleNNData layerData = SimpleNNData();
	layerData.addLayer(2);
	layerData.addLayer(1);
	layerData.addLayer(4);
	layerData.addLayer(3);

	CSimpleNN_ptr nn = SimpleNN::CreateSimpleNN(layerData);

	Eigen::VectorXf input = Eigen::VectorXf::Random(2);

	auto output = nn->getOutput(input);
}

TEST(simpleNN_test, Mutate) {
	SimpleNNData layerData = SimpleNNData();
	layerData.addLayer(2);
	layerData.addLayer(1);
	layerData.addLayer(4);
	layerData.addLayer(3);

	CSimpleNN_ptr nn = SimpleNN::CreateSimpleNN(layerData);
	CSimpleNN_ptr mutatedNN = nn->copyAndMutate(0.5f, 1.f);
}
