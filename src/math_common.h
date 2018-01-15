// This file is part of Tempest-math project
// Author: Karol Kontny

#include <vec4.h>

namespace tst {

	template <typename T>
	vec<4, T> TST_CALL sqrt(const vec<4, T>& v) noexcept;

	template <typename T>
	vec<4, T> TST_CALL dot(const vec<4, T>& v) noexcept;

	template <typename T>
	vec<4, T> TST_CALL cross(const vec<4, T>& v) noexcept;

}

#include "math_common.inl"