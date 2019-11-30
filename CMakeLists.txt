CMAKE_MINIMUM_REQUIRED(VERSION 3.8)

option(EIGEN_LEAVE_TEST_IN_ALL_TARGET "" OFF)

add_subdirectory("externals")
add_subdirectory("libs")
add_subdirectory("numberReader")
add_subdirectory("simpleNN")
add_subdirectory("test")
