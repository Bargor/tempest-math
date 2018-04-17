// This file is part of Tempest-math project
// Author: Karol Kontny

#include "vec4.h"

namespace tst {

namespace math {

    //square root

    template <typename T>
    vec<4, T> TST_CALL sqrt(const vec<4, T>& v) noexcept;

    template <typename T>
    T TST_CALL sqrt(const T v) noexcept;

    template <typename T>
    vec<4, T> TST_CALL sqrt_fast(const vec<4, T>& v) noexcept;

    template <typename T>
    T TST_CALL sqrt_fast(const T v) noexcept;

    //reciprocal sqrt

    template <typename T>
    constexpr vec<4, T> TST_CALL rsqrt(const vec<4, T>& v) noexcept;

    template <typename T>
    constexpr T TST_CALL rsqrt(const T v) noexcept;

    template <typename T>
    vec<4, T> TST_CALL rsqrt_fast(const vec<4, T>& v) noexcept;

    template <typename T>
    T TST_CALL rsqrt_fast(const T v) noexcept;

    //another

    template <typename T>
    float TST_CALL dot(const vec<4, T>& v1, const vec<4, T>& v2) noexcept;

    template <typename T>
    vec<4, T> TST_CALL cross(const vec<4, T>& v1, const vec<4, T>& v2) noexcept;

    template <typename T>
    constexpr float TST_CALL length(const vec<4, T>& v) noexcept;

    template <typename T>
    constexpr vec<4, T> TST_CALL normalize(const vec<4, T>& v) noexcept;

    template <typename T>
    constexpr T TST_CALL distance(const vec<4, T> v1, const vec<4, T> v2) noexcept;

    template <typename T>
    constexpr T TST_CALL abs(const T v) noexcept;

    template <typename T>
    vec<4, T> TST_CALL abs(const vec<4, T> v) noexcept;

    namespace internal {
        template<typename T>
        T TST_CALL horizontal_add(const vec<4, T> v) noexcept;

    }

}
}

#include "math_common.inl"