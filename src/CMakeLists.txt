CMAKE_MINIMUM_REQUIRED(VERSION 3.8)

project(simpleNN)

set(simpleNN_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/network CACHE STRING "simpleNN_PATH")

file(GLOB simpleNN_SOURCE network/*.h network/*.cpp)

add_library(${PROJECT_NAME} STATIC ${simpleNN_SOURCE})