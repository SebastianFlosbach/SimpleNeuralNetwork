#pragma once

#include <string>
#include <vector>

#include "IdxObject.h"

typedef unsigned char Uint8;

class IdxReader {
	std::string path_;

public:
	IdxReader( const std::string& path ) : path_( path ) {
	}

	const IdxType getType() const;

	template <typename T>
	const IdxObject<T> getIdxObject() const;

};
