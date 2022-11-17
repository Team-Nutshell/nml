cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
set(NAME ntshm)
project(${NAME} VERSION 0.0.1 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(NTSHM_SOURCES
	src/vec2.cpp
	src/vec3.cpp
	src/vec4.cpp
)
set(NTSHM_HEADERS
	include/vec2.h
	include/vec3.h
	include/vec4.h
)

set(SOURCES ${NTSHM_SOURCES})
set(HEADERS ${NTSHM_HEADERS})

add_library(${PROJECT_NAME} ${SOURCES} ${HEADERS})