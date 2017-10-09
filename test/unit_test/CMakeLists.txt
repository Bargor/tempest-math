# This file is part of Tempest-math project
# Author: Karol Kontny

project (Tempest-math)

set(PROJECT_BINARY_DIR ${BINARY_DIR}/test_bin)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/tests)
set(TEST_LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/tests_libs)

include_directories(${INCLUDE_PATHS})
include_directories(${CMAKE_SOURCE_DIR}/libs/googletest/googlemock/include/gmock)

add_subdirectory(${CMAKE_SOURCE_DIR}/libs/googletest ${LIBRARY_OUTPUT_PATH})

link_directories(${LIBRARY_OUTPUT_PATH})

#Find test files
#TODO Make it better
file(GLOB_RECURSE TEST_CODE "*_test.cpp")

source_group("Tests" FILES ${TEST_CODE})

set(TEST_RUNNER TestRunner.cpp)
set(TEST_SRCS ${TEST_RUNNER} ${TEST_CODE})

add_executable (math_test ${TEST_SRCS})

add_dependencies(math_test gmock)

if(UNIX)
	target_link_libraries(math_test ${TEST_LIBRARY_OUTPUT_PATH}/libgmock.a)
	target_link_libraries (math_test ${CMAKE_THREAD_LIBS_INIT} -lstdc++fs)
endif(UNIX)
if(WIN32)
	target_link_libraries(tempest_test debug ${TEST_OUTPUT_PATH}/Debug/gmock.lib
		optimized ${TEST_OUTPUT_PATH}/Release/gmock.lib)
endif(WIN32)