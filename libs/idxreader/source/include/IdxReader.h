#pragma once
#include <string>
#include <vector>

#include "IdxObject.h"

typedef unsigned char Uint8;

enum class IdxType {
	UBYTE,
	SBYTE,
	SHORT,
	INT,
	FLOAT,
	DOUBLE
};

class IdxReader {
	std::string path_;
	std::vector<int> dimensionSize_;

	void* buffer_;

	void loadData();

public:
	IdxReader( const std::string& path ) : path_( path ), buffer_( nullptr ){
		try {
			loadData();
		} catch ( ... ) {
			
		}
	}

	Uint32 size() const;

	template <typename T>
	const IdxObject<T> getIdxObject( const Uint32 index ) const;

};