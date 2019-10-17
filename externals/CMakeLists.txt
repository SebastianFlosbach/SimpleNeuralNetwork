CMAKE_MINIMUM_REQUIRED(VERSION 3.8)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(eigen)
add_subdirectory(googletest)
add_subdirectory(pugixml)
