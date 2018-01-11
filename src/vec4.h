// This file is part of Tempest-math project
// Author: Karol Kontny

#pragma once

#include "vec.h"

namespace tst {

    template<typename T>
    class alignas(sizeof(typename simd_type<T>::type)) vec<4, T> {
    public:

        typedef T value_type;

        union 
        {
            T x, y, z, w;
            typename simd_type<T>::type simd_form;
        };

        static constexpr std::uint32_t TST_CALL length() { return 4; }



        TST_INLINE vec<4, T>& TST_CALL operator=(vec<4, T> const& v) = default;

        template<typename U>
        vec<4, T>& TST_CALL operator=(vec<4, U> const& v);
        template<typename U>
        vec<4, T>& TST_CALL operator+=(U scalar);
        template<typename U>
        vec<4, T>& TST_CALL operator+=(vec<4, U> const& v);

        template<typename U>
        vec<4, T>& TST_CALL operator-=(U scalar);
        template<typename U>
        vec<4, T>& TST_CALL operator-=(vec<4, U> const& v);

        template<typename U>
        vec<4, T>& TST_CALL operator*=(U scalar);
        template<typename U>
        vec<4, T>& TST_CALL operator*=(vec<4, U> const& v);

        template<typename U>
        vec<4, T>& TST_CALL operator/=(U scalar);
        template<typename U>
        vec<4, T>& TST_CALL operator/=(vec<4, U> const& v);
    };
}

#include "vec4.inl"