# This file is part of Tempest-math project
# Author: Karol Kontny

# Usage (because CMake makes this more complicated than it should): 
# Windows: cmake ..\tempest-math -G "Visual Studio 15 2017 Win64" -DBUILD_TESTS=ON 

cmake_minimum_required(VERSION 3.13)

project (Tempest-math CXX)

# The project version number.
set(VERSION_MAJOR   0   CACHE STRING "Project major version number.")
set(VERSION_MINOR   0   CACHE STRING "Project minor version number.")
set(VERSION_PATCH   1   CACHE STRING "Project patch version number.")

#Get build number
execute_process(COMMAND git -C ${CMAKE_CURRENT_SOURCE_DIR} rev-parse --short HEAD OUTPUT_VARIABLE VERSION_REVISION)

message(${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}:${VERSION_REVISION})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_PERF_TESTS "Builds unit and performance tests." OFF)

set(COMPILE_DEFINITIONS ${ARCH})

set(DEBUG_COMPILE_DEFINITIONS ${COMPILE_DEFINITIONS})
set(RELEASE_COMPILE_DEFINITIONS ${COMPILE_DEFINITIONS})

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
	set(TST_COMPILE_OPTIONS /W3 /MP /WX /std:c++latest /experimental:module)
	set(DEBUG_COMPILE_OPTIONS ${TST_COMPILE_OPTIONS} /MTd)
	set(RELEASE_COMPILE_OPTIONS ${TST_COMPILE_OPTIONS} /MT)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	set(TST_COMPILE_OPTIONS -Wall -Werror -W)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
	set(TST_COMPILE_OPTIONS -Wall -Werror -W)
endif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")

add_subdirectory(math)
if(BUILD_TESTS)
	include(CTest)
	add_subdirectory(test)
endif(BUILD_TESTS)

