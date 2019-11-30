#include "gtest/gtest.h"

#include <iostream>

#include <simpleNN.h>
#include <SimpleNNData.h>


TEST(simpleNN_test, Init) {
	SimpleNNFactory* pFactory = CreateSimpleNNFactory();

	ASSERT_NE(pFactory, nullptr);

	DestroySimpleNNFactory(pFactory);
}

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
	SimpleNNFactory* pFactory = CreateSimpleNNFactory();

	SimpleNNData layerData = SimpleNNData();
	layerData.addLayer(2);
	layerData.addLayer(1);
	layerData.addLayer(4);
	layerData.addLayer(3);

	ISimpleNN_ptr nn = pFactory->createSimpleNN(layerData);

	DestroySimpleNNFactory(pFactory);
}

TEST(simpleNN_test, GetOutput) {
	SimpleNNFactory* pFactory = CreateSimpleNNFactory();

	SimpleNNData layerData = SimpleNNData();
	layerData.addLayer(2);
	layerData.addLayer(1);
	layerData.addLayer(4);
	layerData.addLayer(3);

	ISimpleNN_ptr nn = pFactory->createSimpleNN(layerData);

	Eigen::VectorXf input = Eigen::VectorXf::Random(2);

	auto output = nn->getOutput(input);

	DestroySimpleNNFactory(pFactory);
}

TEST(simpleNN_test, Mutate) {
	SimpleNNFactory* pFactory = CreateSimpleNNFactory();

	SimpleNNData layerData = SimpleNNData();
	layerData.addLayer(2);
	layerData.addLayer(1);
	layerData.addLayer(4);
	layerData.addLayer(3);

	ISimpleNN_ptr nn = pFactory->createSimpleNN(layerData);
	ISimpleNN_ptr mutatedNN = nn->copyAndMutate(0.5f, 1.f);

	DestroySimpleNNFactory(pFactory);
}
