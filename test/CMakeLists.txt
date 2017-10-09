# This file is part of Tempest-math project
# Author: Karol Kontny

add_subdirectory (unit_test)
if (BUILD_PERF_TESTS)
	message("Building tests")
	add_subdirectory (performance_test)
endif(BUILD_PERF_TESTS)
