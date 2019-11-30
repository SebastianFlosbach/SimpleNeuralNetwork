CMAKE_MINIMUM_REQUIRED(VERSION 3.8)

project("SimpleNN_test")

add_definitions( -DSIMPLE_NN_IMPORTS )

file( GLOB "SOURCES" "*.h" "*.cpp" )

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE simpleNN eigen gtest gtest_main)

install(TARGETS ${PROJECT_NAME}
		RUNTIME DESTINATION bin)
