#include "gtest/gtest.h"

#include <iostream>

#include <simpleNN.h>
#include <SimpleNNData.h>


TEST(simpleNN_test, CreateSimpleNNData) {
	SimpleNNData nnData = SimpleNNData();
	nnData.addLayer(2);
	nnData.addLayer(1);
	nnData.addLayer(4);
	nnData.addLayer(3);

	ASSERT_EQ( nnData.size(), 4);

	const std::vector<uint32_t>& layerData = nnData.getLayerNeuronCounts();

	ASSERT_EQ( layerData[0], 2);
	ASSERT_EQ( layerData[1], 1);
	ASSERT_EQ( layerData[2], 4);
	ASSERT_EQ( layerData[3], 3);
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

	CSimpleNN_ptr nn = SimpleNN::Create(layerData);
}

TEST(simpleNN_test, GetOutput) {
	SimpleNNData layerData = SimpleNNData();
	layerData.addLayer(2);
	layerData.addLayer(1);
	layerData.addLayer(4);
	layerData.addLayer(3);

	CSimpleNN_ptr nn = SimpleNN::Create(layerData);

	Eigen::VectorXf input = Eigen::VectorXf::Random(2);

	auto output = nn->getOutput(input);
}

TEST(simpleNN_test, Mutate) {
	SimpleNNData layerData = SimpleNNData();
	layerData.addLayer(2);
	layerData.addLayer(1);
	layerData.addLayer(4);
	layerData.addLayer(3);

	CSimpleNN_ptr nn = SimpleNN::Create(layerData);
	CSimpleNN_ptr mutatedNN = nn->copyAndMutate(0.5f, 1.f);
}

TEST( simpleNN_test, Writer ) {
	SimpleNNWriter writer = SimpleNNWriter("");
	SimpleNNData layerData = SimpleNNData();
	layerData.addLayer( 2 );
	layerData.addLayer( 1 );
	layerData.addLayer( 4 );
	layerData.addLayer( 3 );

	auto nn = SimpleNN::Create( layerData );

	writer.write( *nn.get() );
}
