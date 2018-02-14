// This file is part of Tempest-math project
// Author: Karol Kontny

#pragma once

#include "vec.h"

namespace tst {

    template<typename T>
    bool TST_CALL epsilonEq(const T v1, const T v2, const T epsilon) noexcept;

    template<typename T, length_t L, template <length_t, typename T> typename vec>
    vec<L, std::uint32_t> TST_CALL epsilonEq(const vec<L, T> v1, const vec<L, T> v2, const T epsilon) noexcept;

    template<typename T>
    bool TST_CALL epsilonNeq(const T v1, const T v2, const T epsilon) noexcept;

    template<typename T, length_t L, template <length_t, typename T> typename vec>
    vec<L, std::uint32_t> TST_CALL epsilonNeq(const vec<L, T> v1, const vec<L, T> v2, const T epsilon) noexcept;

}

#include "compare.inl"