CMAKE_MINIMUM_REQUIRED(VERSION 3.8)

set(idxreader_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include CACHE STRING "")

project(idxreader)

include_directories("include")

file(GLOB "IDXREADER_SOURCE"
	"include/*.h"
	"src/*.h" "src/*.cpp")

add_library(${PROJECT_NAME} STATIC ${IDXREADER_SOURCE})