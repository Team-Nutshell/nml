cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
set(NAME nml)
project(${NAME} VERSION 0.0.1 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(NML_SOURCES
	src/vec2.cpp
	src/vec3.cpp
	src/vec4.cpp
)
set(NML_HEADERS
	include/vec2.h
	include/vec3.h
	include/vec4.h
)

set(SOURCES ${NML_SOURCES})
set(HEADERS ${NML_HEADERS})

add_library(${PROJECT_NAME} ${SOURCES} ${HEADERS})