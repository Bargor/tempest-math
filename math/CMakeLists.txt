include(../GatherSources.cmake)

add_library(math INTERFACE)

add_library(tst::math ALIAS math)

target_include_directories(math INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(math
	INTERFACE
		tstmath.h
		assert.h
		util.h
		config.h
		vec.h
		vec4.h
		vec4.inl
		math_common.h
		math_common.inl
		compare.h
		compare.inl
)

source_group("math" FILES ${TEMPEST_CODE})

target_link_libraries(math INTERFACE)