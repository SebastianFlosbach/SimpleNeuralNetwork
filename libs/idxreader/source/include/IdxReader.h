#pragma once

#include "idxReader_exports.h"

#include "CIdxReader.h"


IDX_READER_EXPORTS IdxReader* CreateIdxReader(const std::string& path);
IDX_READER_EXPORTS void DestroyIdxReader(IdxReader* idxReader);
