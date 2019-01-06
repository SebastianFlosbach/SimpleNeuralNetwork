#pragma once
#include <vector>

typedef unsigned int Uint32;

enum class IdxType {
	UBYTE,
	SBYTE,
	SHORT,
	INT,
	FLOAT,
	DOUBLE
};

struct IdxHeader {
	IdxType type_;
	int dimensions_;
	std::vector<Uint32> sizeOfDimensions_;
	int sizeInBytes_;
};

template <typename T>
struct IdxObject {
	IdxObject( IdxHeader header, T* data ) : header_( header ), data_( data ), referenceCounter_( new Uint32( 0 ) ) {
		startIndex_ = 0;
		endIndex_ = header.sizeInBytes_;
	}

	~IdxObject() {
		if ( *referenceCounter_ <= 0 ) {
			delete[] data_;
		} else {
			*referenceCounter_--;
		}
	}

	Uint32 size() const {
		return header_.sizeInBytes_;
	}

	Uint32 numberOfDimensions() const {
		return header_.dimensions_;
	}

	Uint32 sizeOfDimension( const Uint32 dimension ) const {
		return header_.sizeOfDimensions_[dimension];
	}

	const T getData( const Uint32 index ) const {
		return data_[index];
	}

	const IdxObject<T> getIdxObject( Uint32 index ) const;

private:
	IdxObject( IdxHeader header, T* data, Uint32* referenceCounter, Uint32 startIndex, Uint32 endIndex ) : header_( header ), data_( data ), referenceCounter_( referenceCounter ), startIndex_( startIndex ), endIndex_( endIndex ) {
		if ( !referenceCounter ) {
			referenceCounter_ = new Uint32( 0 );
		} else {
			*referenceCounter_++;
		}
	}

	IdxHeader header_;
	T* data_;
	Uint32 startIndex_;
	Uint32 endIndex_;

	Uint32* referenceCounter_;
};