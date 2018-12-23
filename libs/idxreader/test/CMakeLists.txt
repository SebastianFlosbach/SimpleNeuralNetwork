CMAKE_MINIMUM_REQUIRED(VERSION 3.8)

project("IdxReader_test")

include_directories(${idxreader_INCLUDE_DIR})
message( STATUS ${idxreader_INCLUDE_DIR} )

file(GLOB "IDXREADER_TEST_SOURCE"
	"src/main.cpp")

add_executable(${PROJECT_NAME} ${IDXREADER_TEST_SOURCE})

target_link_libraries(${PROJECT_NAME} PRIVATE idxreader gtest gtest_main)

configure_file( "data/idxTest.idx" "${CMAKE_CURRENT_BINARY_DIR}/data/idxTest.idx" COPYONLY )