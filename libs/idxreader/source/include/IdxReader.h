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

enum class IdxState {
	Ready,
	Error
};

class IdxReader {
	std::string path_;
	std::vector<int> dimensionSize_;
	IdxState state_;

	void* buffer_;

	void loadData();

public:
	IdxReader( const std::string& path ) : path_( path ), buffer_( nullptr ), state_( IdxState::Ready ) {
		try {
			loadData();
		} catch ( ... ) {
			state_ = IdxState::Error;
		}
	}

	~IdxReader() {
		delete[] buffer_;
	}

	Uint32 sizeOfDimension( Uint32 dimension ) const;
	inline Uint32 dimensions() const { return dimensionSize_.size(); }
	inline IdxState state() const { return state_; }

	template <typename T>
	const IdxObject<T> getIdxObject( const Uint32 index ) const;

};