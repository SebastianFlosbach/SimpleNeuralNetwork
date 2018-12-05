CMAKE_MINIMUM_REQUIRED(VERSION 3.8)

set(simpleNN_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include CACHE STRING "")

project(simpleNN)

file(GLOB simpleNN_SOURCE
	include/*.h
	src/*.h		src/*.cpp
	src/xml/*.h src/xml/*.cpp
)

include_directories(include)

add_library(${PROJECT_NAME} STATIC ${simpleNN_SOURCE})

target_link_libraries(${PROJECT_NAME} PRIVATE pugixml)