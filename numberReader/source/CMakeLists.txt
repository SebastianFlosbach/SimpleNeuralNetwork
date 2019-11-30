CMAKE_MINIMUM_REQUIRED(VERSION 3.8)

project("NumberReader")

add_definitions( -DSIMPLE_NN_IMPORTS -DIDX_READER_IMPORTS )

file( GLOB "SOURCES" "include/*.h" "src/*.h" "src/*.cpp" )

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE simpleNN idxreader eigen gtest gtest_main)

install(TARGETS ${PROJECT_NAME}
		RUNTIME DESTINATION bin)
