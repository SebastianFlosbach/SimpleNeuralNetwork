#pragma once

#include <ctime>
#include <simpleNN.h>
#include <idxreader.h>
#include <iostream>

#include "DataPrinter.h"


uint32_t vectorToNumber(const Eigen::VectorXf& vec ) {
	uint32_t number = 0;
	float output = vec(0);

	for (Eigen::Index i = 1; i < vec.size(); i++) {
		if (vec(i) > output) {
			output = vec(i);
			number = i;
		}
	}

	return number;
}

int main() {
	srand( static_cast<unsigned int>(clock()) );

	IdxReader* pImageReader = CreateIdxReader("data\\train-images.idx");
	IdxReader* pLabelReader = CreateIdxReader("data\\train-labels.idx");

	IdxObject<Uint8> images = pImageReader->getIdxObject<Uint8>();
	IdxObject<Uint8> labels = pLabelReader->getIdxObject<Uint8>();

	SimpleNNFactory* pFactory = CreateSimpleNNFactory();

	IdxObject<Uint8> image = images.getIdxObject(0);

	SimpleNNData data = SimpleNNData();
	data.addLayer(image.size() * image.size());
	data.addLayer(4);
	data.addLayer(10);

	auto nn = pFactory->createSimpleNN(data);

	for (uint32_t i = 0; i < images.size(); i++) {
		image = images.getIdxObject(i);

		Eigen::VectorXf pixelData = Eigen::VectorXf(image.size() * image.size());

		for (uint32_t j = 0; j < pixelData.size(); j++) {
			pixelData(j) = (float)image.getData(j);
		}

		auto output = nn->getOutput(pixelData);
		std::cout << vectorToNumber(output) << " : " << (int)labels.getData(i) << std::endl;

		std::cin.get();
	}

}
