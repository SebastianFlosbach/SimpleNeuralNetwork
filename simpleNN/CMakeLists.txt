CMAKE_MINIMUM_REQUIRED(VERSION 3.8)

#set(simpleNN_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include CACHE STRING "")

project(simpleNN)

file(GLOB "SOURCE"
	src/*.h		src/*.cpp
	src/xml/*.h src/xml/*.cpp
)

include_directories(include)

add_library(${PROJECT_NAME} STATIC ${SOURCE})

target_include_directories(${PROJECT_NAME} PUBLIC "include")
target_link_libraries(${PROJECT_NAME} PUBLIC pugixml)