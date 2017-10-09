# This file is part of Tempest-math project
# Author: Karol Kontny

# Usage (because CMake makes this more complicated than it should): 
# Windows: cmake ..\tempest-math -G "Visual Studio 15 2017 Win64" 

cmake_minimum_required(VERSION 3.8)

# The project version number.
set(VERSION_MAJOR   0   CACHE STRING "Project major version number.")
set(VERSION_MINOR   0   CACHE STRING "Project minor version number.")
set(VERSION_PATCH   1   CACHE STRING "Project patch version number.")

#Get build number
execute_process(COMMAND git rev-parse --short HEAD OUTPUT_VARIABLE VERSION_REVISION)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory (src)
if (BUILD_TESTS)
	message("Building tests")
	add_subdirectory (test)
endif(BUILD_TESTS)