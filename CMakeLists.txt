cmake_minimum_required(VERSION 3.10)
set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z -Wall -Wextra -Werror")

project(ApertusTask VERSION 1.0.1 DESCRIPTION "Convert RAW12 to PPM")

include_directories(header)

set(LIB_SRC
	src/RawImage.cpp
	src/Debayer.cpp
	src/ProcessImage.cpp
	src/Ppm.cpp
	header/RawImage.hpp
	header/Debayer.hpp
	header/ProcessImage.hpp
	header/Ppm.hpp
	)
add_library(RawImage SHARED ${LIB_SRC})

add_executable(ApertusTask main.cpp)

target_link_libraries(ApertusTask PRIVATE RawImage)
