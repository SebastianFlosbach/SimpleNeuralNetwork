#include "idxreader.h"


IdxReader* CreateIdxReader(const std::string& path) {
	return new IdxReader(path);
}

void DestroyIdxReader(IdxReader* idxReader) {
	if (idxReader == nullptr) {
		return;
	}

	delete idxReader;
}
