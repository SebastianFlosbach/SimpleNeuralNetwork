#pragma once

#include <string>
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include <iostream>

#include "CSimpleNN.h"


class SimpleNNWriter {
public:
	SimpleNNWriter( const std::string& path );

	bool write( const CSimpleNN& simpleNN ) const;

private:
	std::string path_;

};
