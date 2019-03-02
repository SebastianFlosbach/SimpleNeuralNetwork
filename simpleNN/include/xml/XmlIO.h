#pragma once
#include <pugixml.hpp>
#include <string>

#include "Network.h"

class XmlIO {
	const char* path_;

public:
	XmlIO( const char* path );
	XmlIO( const std::string& path );

	void saveNetwork( const Network& network ) const;
	Network loadNetwork() const;
};