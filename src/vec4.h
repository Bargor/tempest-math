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
            T data[4];
        };

        static constexpr std::uint32_t TST_CALL length() noexcept { return 4; }

        // constructors
        constexpr vec() = default;
        constexpr vec(vec<4, T> const& v) = default;

        explicit vec(T scalar);
        vec(T x, T y, T z, T w);

        TST_INLINE vec<4, T>& TST_CALL operator=(vec<4, T> const& v) = default;

        // unary operators

        // binary operators

        template<typename U>
        vec<4, T>& TST_CALL operator=(vec<4, U> const& v) noexcept;
        template<typename U>
        vec<4, T>& TST_CALL operator+=(U scalar) noexcept;
        template<typename U>
        vec<4, T>& TST_CALL operator+=(vec<4, U> const& v) noexcept;

        template<typename U>
        vec<4, T>& TST_CALL operator-=(U scalar) noexcept;
        template<typename U>
        vec<4, T>& TST_CALL operator-=(vec<4, U> const& v) noexcept;

        template<typename U>
        vec<4, T>& TST_CALL operator*=(U scalar) noexcept;
        template<typename U>
        vec<4, T>& TST_CALL operator*=(vec<4, U> const& v) noexcept;

        template<typename U>
        vec<4, T>& TST_CALL operator/=(U scalar) noexcept;
        template<typename U>
        vec<4, T>& TST_CALL operator/=(vec<4, U> const& v) noexcept;

    };

    //boolean operators

    template<typename T>
    constexpr bool TST_CALL operator==(vec<4, T> const& v1, vec<4, T> const& v2) noexcept;
    template<typename T>
    constexpr bool TST_CALL operator!=(vec<4, T> const& v1, vec<4, T> const& v2) noexcept;

    //unary operators

    template<typename T>
    constexpr vec<4, T> TST_CALL operator+(vec<4, T> const& v) noexcept;
    template<typename T>
    constexpr vec<4, T> TST_CALL operator-(vec<4, T> const& v) noexcept;

    //binary operators

    template<typename T>
    constexpr vec<4, T> TST_CALL operator+(vec<4, T> const& v, T scalar) noexcept;
    template<typename T>
    constexpr vec<4, T> TST_CALL operator+(T scalar, vec<4, T> const& v) noexcept;
    template<typename T>
    constexpr vec<4, T> TST_CALL operator+(vec<4, T> const& v1, vec<4, T> const& v2) noexcept;
    
    template<typename T>
    constexpr vec<4, T> TST_CALL operator-(vec<4, T> const& v, T scalar) noexcept;
    template<typename T>
    constexpr vec<4, T> TST_CALL operator-(T scalar, vec<4, T> const& v) noexcept;
    template<typename T>
    constexpr vec<4, T> TST_CALL operator-(vec<4, T> const& v1, vec<4, T> const& v2) noexcept;

    template<typename T>
    constexpr vec<4, T> TST_CALL operator*(vec<4, T> const& v, T scalar) noexcept;
    template<typename T>
    constexpr vec<4, T> TST_CALL operator*(T scalar, vec<4, T> const& v) noexcept;
    template<typename T>
    constexpr vec<4, T> TST_CALL operator*(vec<4, T> const& v1, vec<4, T> const& v2) noexcept;

    template<typename T>
    constexpr vec<4, T> TST_CALL operator/(vec<4, T> const& v, T scalar) noexcept;
    template<typename T>
    constexpr vec<4, T> TST_CALL operator/(T scalar, vec<4, T> const& v) noexcept;
    template<typename T>
    constexpr vec<4, T> TST_CALL operator/(vec<4, T> const& v1, vec<4, T> const& v2) noexcept;
    
}

#include "vec4.inl"