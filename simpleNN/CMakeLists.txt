CMAKE_MINIMUM_REQUIRED(VERSION 3.8)

project(simpleNN)

file(GLOB_RECURSE "SOURCES"
	"include/*.h" "src/*.h" "src/*.cpp"
)

include_directories(include)

add_library(${PROJECT_NAME} SHARED ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC "include")
target_link_libraries(${PROJECT_NAME} PUBLIC pugixml eigen)