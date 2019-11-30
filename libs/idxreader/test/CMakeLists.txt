CMAKE_MINIMUM_REQUIRED(VERSION 3.8)

project("IdxReader_test")

add_definitions( -DIDX_READER_IMPORTS )

file(GLOB "SOURCES" "src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE idxreader gtest gtest_main)

configure_file( "data/idxTest_1D.idx" "${CMAKE_CURRENT_BINARY_DIR}/data/idxTest_1D.idx" COPYONLY )
configure_file( "data/idxTest_2D.idx" "${CMAKE_CURRENT_BINARY_DIR}/data/idxTest_2D.idx" COPYONLY )
configure_file( "data/idxTest_3D.idx" "${CMAKE_CURRENT_BINARY_DIR}/data/idxTest_3D.idx" COPYONLY )

install(TARGETS ${PROJECT_NAME}
		RUNTIME DESTINATION bin)

install(DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/data/" DESTINATION "bin/data/" )
