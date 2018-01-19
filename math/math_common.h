// This file is part of Tempest-math project
// Author: Karol Kontny

#include "vec4.h"

namespace tst {

    template <typename T>
    vec<4, T> TST_CALL sqrt(const vec<4, T>& v) noexcept;

    float TST_CALL sqrt(const float v) noexcept;

    template <typename T>
    vec<4, T> TST_CALL sqrt_fast(const vec<4, T>& v) noexcept;

    float TST_CALL sqrt_fast(const float v) noexcept;

    template <typename T>
    float TST_CALL dot(const vec<4, T>& v1, const vec<4, T>& v2) noexcept;

    template <typename T>
    vec<4, T> TST_CALL cross(const vec<4, T>& v1, const vec<4, T>& v2) noexcept;

}

#include "math_common.inl"