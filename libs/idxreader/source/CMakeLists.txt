CMAKE_MINIMUM_REQUIRED(VERSION 3.8)

project("idxreader")

add_definitions( -DIDX_READER_EXPORTS )

file(GLOB_RECURSE "SOURCES"
	"include/*.h" "src/*.h" "src/*.cpp"
)

include_directories("include")

add_library(${PROJECT_NAME} SHARED ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC "include")
target_link_libraries(${PROJECT_NAME} PUBLIC idxreader_core )

install(TARGETS ${PROJECT_NAME}
		RUNTIME DESTINATION bin)
