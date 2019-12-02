CMAKE_MINIMUM_REQUIRED(VERSION 3.8)

project("SimpleNNTrainer_test")

add_definitions( -DSIMPLE_NN_TRAINER_IMPORTS )

file( GLOB "SOURCES" "*.h" "*.cpp" )

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE simpleNNTrainer_core eigen gtest gtest_main)

install(TARGETS ${PROJECT_NAME}
		RUNTIME DESTINATION bin)
