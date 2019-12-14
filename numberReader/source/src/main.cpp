#pragma once

#include <ctime>
#include <simpleNN.h>
#include <simpleNNTrainer.h>
#include <idxreader.h>
#include <iostream>

#include "DataPrinter.h"


uint32_t vectorToNumber( const Eigen::VectorXf& vec ) {
	uint32_t number = 0;
	float output = vec( 0 );

	for( Eigen::Index i = 1; i < vec.size(); i++ ) {
		if( vec( i ) > output ) {
			output = vec( i );
			number = i;
		}
	}

	return number;
}

Eigen::VectorXf numberToVector( uint32_t num ) {
	Eigen::VectorXf vec = Eigen::VectorXf::Zero( 10 );
	vec( num ) = 1.f;

	return vec;
}

int main() {
	srand( static_cast<unsigned int>(clock()) );

	uint32_t generationSize = 10;
	uint32_t maxGenerations = 100000;

	IdxReader* pImageReader = CreateIdxReader( "data\\train-images.idx" );
	IdxReader* pLabelReader = CreateIdxReader( "data\\train-labels.idx" );

	IdxObject<Uint8> images = pImageReader->getIdxObject<Uint8>();
	IdxObject<Uint8> labels = pLabelReader->getIdxObject<Uint8>();

	CSimpleNNTrainer* pTrainer = CreateSimpleNNTrainer( 1000, 0.1, 0.1 );

	IdxObject<Uint8> image = images.getIdxObject( 0 );

	SimpleNNData data = SimpleNNData();
	data.addLayer( image.size() * image.size() );
	data.addLayer( 4 );
	data.addLayer( 10 );

	auto nn = SimpleNN::Create( data );
	pTrainer->generateNextGeneration( *nn.get() );

	for( uint32_t g = 0; g < maxGenerations; g++ ) {
		for( uint32_t i = 0; i < 1/*images.size()*/; i++ ) {
			image = images.getIdxObject( i );

			Eigen::VectorXf pixelData = Eigen::VectorXf( image.size() * image.size() );

			for( uint32_t j = 0; j < pixelData.size(); j++ ) {
				pixelData( j ) = (float)image.getData( j ) / 255.f;
			}

			pTrainer->test( pixelData, numberToVector( labels.getData( i ) ) );
		}

		auto hitPercentage = pTrainer->getHitPercentage();

		std::cout << "Generation " << g << std::endl;
		std::cout << pTrainer->getGenerationFitness()[0].totalDifference() << std::endl;
		//for( size_t i = 0; i < pTrainer->getGenerationFitness().size(); i++ ) {
		//	std::cout << pTrainer->getGenerationFitness()[i].totalDifference() << std::endl;
		//}
		//std::cout << *std::max_element(hitPercentage.begin(), hitPercentage.end()) * 100.f << "%" << std::endl;

		//std::cin.get();
		pTrainer->generateNextGeneration();
	}

}
