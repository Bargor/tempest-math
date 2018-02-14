// This file is part of Tempest-math project
// Author: Karol Kontny

#pragma once

#include "vec.h"

namespace tst {

    template<typename T>
    constexpr T TST_CALL epsilonEq(const T v1, const T v2, const T epsilon) noexcept;

    template<typename T, template<typename T> vec >
    constexpr vec<bool> TST_CALL epsilonEq(const vec<T> v1, const vec<T> v2, const T epsilon) noexcept;

    template<typename T>
    constexpr T TST_CALL epsilonNeq(const T v1, const T v2, const T epsilon) noexcept;

    template<typename T, template<typename T> vec >
    constexpr vec<bool> TST_CALL epsilonNeq(const vec<T> v1, const vec<T> v2, const T epsilon) noexcept;

}

#include "compare.inl"