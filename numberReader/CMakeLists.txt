CMAKE_MINIMUM_REQUIRED(VERSION 3.8)

project(numberReader)

include_directories(${simpleNN_INCLUDE_DIR})
include_directories(${idxreader_INCLUDE_DIR})

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE simpleNN idxreader)