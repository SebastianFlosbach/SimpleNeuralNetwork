CMAKE_MINIMUM_REQUIRED(VERSION 3.8)

project(srcTest)

include_directories(${gtest_SOURCE_DIR}/include ${COMMON_INCLUDES})
include_directories(${simpleNN_INCLUDE_DIR})

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE simpleNN gtest gtest_main)