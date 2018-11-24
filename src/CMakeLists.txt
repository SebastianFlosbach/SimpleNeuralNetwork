CMAKE_MINIMUM_REQUIRED(VERSION 3.8)

project(simpleNN)

file(GLOB simpleNN_SOURCE 
	network/*.h network/*.cpp
	factory/*.h factory/*.cpp
)

add_library(${PROJECT_NAME} STATIC ${simpleNN_SOURCE})