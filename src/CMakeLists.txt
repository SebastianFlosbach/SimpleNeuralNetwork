CMAKE_MINIMUM_REQUIRED(VERSION 3.8)

project(simpleNN)

file( GLOB simpleNN_SOURCE *.cpp *.h 
							network/*.cpp network/*.h)

add_library(${PROJECT_NAME} SHARED ${simpleNN_SOURCE})