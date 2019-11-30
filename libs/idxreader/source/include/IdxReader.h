#pragma once

#include "idxReader_exports.h"

#include "CIdxReader.h"


IDX_READER_EXPORTS IdxReader* createIdxReader(const std::string& path);
IDX_READER_EXPORTS void destroyIdxReader(IdxReader* idxReader);
