CMAKE_MINIMUM_REQUIRED(VERSION 3.8)

project("idxreader_core")

file(GLOB_RECURSE "SOURCES"
	"include/*.h" "src/*.h" "src/*.cpp"
)

include_directories(include)

add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC "include")
