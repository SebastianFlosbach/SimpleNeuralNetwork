#include "xml/XmlIO.h"

XmlIO::XmlIO( const char* path ) : path_( path ) {
}

XmlIO::XmlIO( const std::string& path ) : path_( path.c_str() ) {
}

void XmlIO::saveNetwork( const Network& network ) const {
	pugi::xml_document doc;

	auto networkNode = doc.append_child( "network" );

	for ( size_t l = 0; l < network.numberOfLayers(); l++ ) {
		auto layer = network.getLayer( l );
		auto xmlLayer = networkNode.append_child( "layer" );

		auto layerId = xmlLayer.append_attribute( "id" );
		layerId.set_value( layer->id() );

		for ( size_t n = 0; n < layer->size(); n++ ) {
			auto neuron = layer->getNeuron( n );
			auto xmlNeuron = xmlLayer.append_child( "neuron" );

			auto neuronId = xmlNeuron.append_attribute( "id" );
			neuronId.set_value( neuron->id() );

			auto neuronBias = xmlNeuron.append_attribute( "bias" );
			neuronBias.set_value( neuron->getBias() );

			for ( size_t c = 0; c < neuron->numberOfConnections(); c++ ) {
				auto& connection = neuron->getConnection( c );
				auto xmlConnection = xmlNeuron.append_child( "connection" );

				auto connectionId = xmlConnection.append_attribute( "targetId" );
				connectionId.set_value( connection.getTargetNeuron().id() );

				auto connectionWeight = xmlConnection.append_attribute( "weight" );
				connectionWeight.set_value( connection.getWeight() );
			}
		}
	}

	doc.save_file( path_ );
}

Network XmlIO::loadNetwork() const {
	throw std::runtime_error("[XmlIO::loadNetwork] not implemented");
}