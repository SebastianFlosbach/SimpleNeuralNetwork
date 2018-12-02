CMAKE_MINIMUM_REQUIRED(VERSION 3.8)

set(simpleNN_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include CACHE STRING "")

project(simpleNN)

file(GLOB simpleNN_SOURCE
	include/*.h
	src/network/*.h src/network/*.cpp
)

include_directories(include)

add_library(${PROJECT_NAME} STATIC ${simpleNN_SOURCE})