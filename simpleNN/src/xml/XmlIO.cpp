#include "XmlIO.h"

XmlIO::XmlIO( const char* path ) : path_( path ) {
}

XmlIO::XmlIO( const std::string& path ) : path_( path.c_str() ) {
}

void XmlIO::saveNetwork( const Network& network ) const {
	pugi::xml_document doc;

	auto networkNode = doc.append_child( "network" );

	for ( size_t l = 0; l < network.size(); l++ ) {
		auto xmlLayer = networkNode.append_child( "layer" );

		auto layerId = xmlLayer.append_attribute( "id" );
		layerId.set_value( l );
	}

	doc.save_file( path_ );
}

NetworkPtr XmlIO::loadNetwork() const {
	throw std::runtime_error("[XmlIO::loadNetwork] not implemented");
}