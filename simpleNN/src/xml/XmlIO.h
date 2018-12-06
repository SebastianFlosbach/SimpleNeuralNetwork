#pragma once
#include <pugixml.hpp>
#include <string>

class XmlIO {
	std::string path_;

	pugi::xml_document doc_;

public:
	XmlIO();

};