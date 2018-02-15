# This file is part of Tempest-math project
# Author: Karol Kontny

set(TEMPEST_CODE ${TEMPEST_CODE} ${CMAKE_SOURCE_DIR}/math/tstmath.h)
set(TEMPEST_CODE ${TEMPEST_CODE} ${CMAKE_SOURCE_DIR}/math/assert.h)
set(TEMPEST_CODE ${TEMPEST_CODE} ${CMAKE_SOURCE_DIR}/math/util.h)
set(TEMPEST_CODE ${TEMPEST_CODE} ${CMAKE_SOURCE_DIR}/math/config.h)
set(TEMPEST_CODE ${TEMPEST_CODE} ${CMAKE_SOURCE_DIR}/math/vec.h)
set(TEMPEST_CODE ${TEMPEST_CODE} ${CMAKE_SOURCE_DIR}/math/vec4.h)
set(TEMPEST_CODE ${TEMPEST_CODE} ${CMAKE_SOURCE_DIR}/math/vec4.inl)
set(TEMPEST_CODE ${TEMPEST_CODE} ${CMAKE_SOURCE_DIR}/math/math_common.h)
set(TEMPEST_CODE ${TEMPEST_CODE} ${CMAKE_SOURCE_DIR}/math/math_common.inl)
set(TEMPEST_CODE ${TEMPEST_CODE} ${CMAKE_SOURCE_DIR}/math/compare.h)
set(TEMPEST_CODE ${TEMPEST_CODE} ${CMAKE_SOURCE_DIR}/math/compare.inl)

source_group(TREE ${CMAKE_SOURCE_DIR}/math FILES ${TEMPEST_CODE})

set(TEMPEST_CODE ${TEMPEST_CODE} PARENT_SCOPE)