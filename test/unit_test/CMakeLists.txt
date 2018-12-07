# This file is part of Tempest-math project
# Author: Karol Kontny

enable_testing()

set(PROJECT_BINARY_DIR ${CMAKE_BINARY_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/exe)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/tests_libs)

add_subdirectory(${CMAKE_SOURCE_DIR}/lib/googletest ${LIBRARY_OUTPUT_PATH})

#Find test files
#TODO Make it better
file(GLOB_RECURSE TEST_CODE "*_test.cpp")

set(TEST_RUNNER test_runner.cpp)
set(TEST_SRCS ${TEST_RUNNER} ${TEST_CODE})

source_group("Tests" FILES ${TEST_SRCS})

add_executable (math_test ${TEST_SRCS})
add_test(NAME unit_test COMMAND math_test)

target_compile_definitions(math_test PUBLIC "$<$<CONFIG:DEBUG>:${DEBUG_COMPILE_DEFINITIONS}>")
target_compile_definitions(math_test PUBLIC "$<$<CONFIG:RELEASE>:${RELEASE_COMPILE_DEFINITIONS}>")

target_compile_options(math_test PUBLIC "$<$<CONFIG:DEBUG>:${DEBUG_COMPILE_OPTIONS}>")
target_compile_options(math_test PUBLIC "$<$<CONFIG:RELEASE>:${RELEASE_COMPILE_OPTIONS}>")

target_link_libraries(math_test gmock tst::math)

if(UNIX)
	find_package(Threads)
	target_link_libraries(math_test gtest ${CMAKE_THREAD_LIBS_INIT})
endif(UNIX)

