#include "SimpleNNWriter.h"

#include <rapidjson/stringbuffer.h>
#include <rapidjson/prettywriter.h>
#include <fstream>


SimpleNNWriter::SimpleNNWriter( const std::string& path ) : path_( path ) {
}

bool SimpleNNWriter::write( const CSimpleNN& simpleNN ) const {
	rapidjson::Document doc = rapidjson::Document();

	doc.SetObject();
	rapidjson::Value layerArray( rapidjson::Type::kArrayType );

	for( size_t i = 0; i < simpleNN.layers_.size(); i++ ) {
		rapidjson::Value layerObject( rapidjson::Type::kObjectType );

		rapidjson::Value connectionMatrix( rapidjson::Type::kArrayType );

		auto& layer = simpleNN.layers_[i];
		for( Eigen::Index i = 0; i < layer.connections_.rows(); i++ ) {
			rapidjson::Value rowArray( rapidjson::Type::kArrayType );

			auto row = layer.connections_.row( i );
			for( Eigen::Index r = 0; r < row.size(); r++ ) {
				rowArray.PushBack( row( r ), doc.GetAllocator() );
			}

			connectionMatrix.PushBack( rowArray, doc.GetAllocator() );
		}

		layerObject.AddMember( "connections", connectionMatrix, doc.GetAllocator() );

		rapidjson::Value biasVector( rapidjson::Type::kArrayType );

		for( Eigen::Index i = 0; i < layer.bias_.size(); i++ ) {
			biasVector.PushBack( layer.bias_[i], doc.GetAllocator() );
		}

		layerObject.AddMember( "bias", biasVector, doc.GetAllocator() );

		layerArray.PushBack( layerObject, doc.GetAllocator() );
	}

	doc.AddMember( "layers", layerArray, doc.GetAllocator() );

	rapidjson::StringBuffer buffer;
	rapidjson::PrettyWriter<rapidjson::StringBuffer> writer( buffer );
	doc.Accept( writer );

	try {
		std::ofstream outFileStream( path_ );
		outFileStream << buffer.GetString();
	} catch( const std::exception& ) {
		return false;
	}

	return true;
}
