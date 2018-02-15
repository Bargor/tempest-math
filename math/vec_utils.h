// This file is part of Tempest-math project
// Author: Karol Kontny

#pragma once

#include "vec.h"

namespace tst {

    template<typename T, length_t L, template <length_t, typename> typename vec>
    bool TST_CALL any(const vec<L, T> v) noexcept;

    template<typename T, length_t L, template <length_t, typename> typename vec>
    bool TST_CALL all(const vec<L, T> v) noexcept;

    template<typename T, length_t L, template <length_t, typename> typename vec>
    vec<L, T> TST_CALL negate(const vec<L, T> v) noexcept;

}

#include "vec_utils.inl"