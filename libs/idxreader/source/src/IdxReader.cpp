#include "idxreader.h"


IdxReader* createIdxReader(const std::string& path) {
	return new IdxReader(path);
}

void destroyIdxReader(IdxReader* idxReader) {
	if (idxReader == nullptr) {
		return;
	}

	delete idxReader;
}
