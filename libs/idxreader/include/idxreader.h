#pragma once
#include <string>

#include "IdxObject.h"

enum class idxType {
	UBYTE,
	SBYTE,
	SHORT,
	INT,
	FLOAT,
	DOUBLE
};

template <class T>
class IdxReader {
	std::string path_;
	Uint32 objectCount_;

	void* buffer_;

public:
	IdxReader( const std::string& path ) : path_( path ), buffer_( nullptr ){
	}

	inline const Uint32 objectCount() const { return objectCount_; }

	void loadData();
	const IdxObject<T> getIdxObject( const Uint32 index ) const;

};