CMAKE_MINIMUM_REQUIRED(VERSION 3.8)

add_subdirectory("source")

install(DIRECTORY "data/" DESTINATION "bin/data/" )
