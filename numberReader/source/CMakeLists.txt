CMAKE_MINIMUM_REQUIRED(VERSION 3.8)

project("NumberReader")

add_definitions( -DSIMPLE_NN_IMPORTS -DSIMPLE_NN_TRAINER_IMPORTS -DIDX_READER_IMPORTS )

file( GLOB "SOURCES" "include/*.h" "src/*.h" "src/*.cpp" )

include_directories("include")

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE simpleNN simpleNNTrainer idxreader eigen gtest gtest_main)

install(TARGETS ${PROJECT_NAME}
		RUNTIME DESTINATION bin)
