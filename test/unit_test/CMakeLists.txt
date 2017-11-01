# This file is part of Tempest-math project
# Author: Karol Kontny

project (Tempest-math CXX)

set(PROJECT_BINARY_DIR ${CMAKE_BINARY_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/exe)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/tests_libs)

include_directories(${INCLUDE_PATHS})
include_directories(${CMAKE_SOURCE_DIR}/lib/googletest/googlemock/include)
include_directories(${CMAKE_SOURCE_DIR}/lib/googletest/googletest/include)

add_subdirectory(${CMAKE_SOURCE_DIR}/lib/googletest ${LIBRARY_OUTPUT_PATH})

link_directories(${LIBRARY_OUTPUT_PATH})

include(${CMAKE_SOURCE_DIR}/GatherSources.cmake)

#Find test files
#TODO Make it better
file(GLOB_RECURSE TEST_CODE "*_test.cpp")

source_group("Tests" FILES ${TEST_CODE})

set(TEST_RUNNER test_runner.cpp)
set(TEST_SRCS ${TEST_RUNNER} ${TEST_CODE})

enable_testing()

add_executable (math_test ${TEST_SRCS} ${TEMPEST_CODE})
add_test(NAME unit_test COMMAND math_test)

target_compile_definitions(math_test PUBLIC "$<$<CONFIG:DEBUG>:${DEBUG_COMPILE_DEFINITIONS}>")
target_compile_definitions(math_test PUBLIC "$<$<CONFIG:RELEASE>:${RELEASE_COMPILE_DEFINITIONS}>")

target_compile_options(math_test PUBLIC "$<$<CONFIG:DEBUG>:${DEBUG_COMPILE_OPTIONS}>")
target_compile_options(math_test PUBLIC "$<$<CONFIG:RELEASE>:${RELEASE_COMPILE_OPTIONS}>")

if(UNIX)
	FIND_PACKAGE(Threads)
	target_link_libraries(math_test ${LIBRARY_OUTPUT_PATH}/libgmock.a)
	target_link_libraries(math_test ${CMAKE_THREAD_LIBS_INIT} -lstdc++fs)
endif(UNIX)
if(WIN32)
	target_link_libraries(math_test debug ${LIBRARY_OUTPUT_PATH}/Debug/gmock.lib
		optimized ${LIBRARY_OUTPUT_PATH}/Release/gmock.lib)
endif(WIN32)
