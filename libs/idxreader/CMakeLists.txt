CMAKE_MINIMUM_REQUIRED(VERSION 3.8)

project(idxreader)

include_directories("include")
include_directories("src")

file(GLOB "IDXREADER_SOURCE" 
	"src/*.h" "src/*.cpp")

add_library(${PROJECT_NAME} STATIC ${IDXREADER_SOURCE})