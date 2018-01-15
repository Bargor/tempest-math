// This file is part of Tempest-math project
// Author: Karol Kontny

namespace tst {


    // constructors

    template<typename T>
	TST_FUNC_SPEC vec<4, T>::vec(T scalar)
        : x(scalar), y(scalar), z(scalar), w(scalar)
    {}

    template <typename T>
	TST_FUNC_SPEC vec<4, T>::vec(T _x, T _y, T _z, T _w)
        : x(_x), y(_y), z(_z), w(_w)
    {}

	template <typename T>
	TST_FUNC_SPEC vec<4, T>::vec(typename simd simd)
		: simd_form(simd)
	{}

	// conversion operators

	template<typename T>
	constexpr vec<4, T>::operator bool() const noexcept {
		return x | y | z | w;
	}

    // binary operators

    template<>
    template<>
    TST_INLINE vec<4, float>& TST_CALL vec<4, float>::operator+=(float scalar) noexcept {
        simd_form = _mm_add_ps(simd_form, _mm_set1_ps(scalar));
        return *this;
    }

    template<>
    template<>
    TST_INLINE vec<4, float>& TST_CALL vec<4, float>::operator+=(vec<4, float> const& v) noexcept {
        simd_form = _mm_add_ps(simd_form, v.simd_form);
        return *this;
    }

    template<>
    template<>
    TST_INLINE vec<4, float>& TST_CALL vec<4, float>::operator-=(float scalar) noexcept {
        simd_form = _mm_sub_ps(simd_form, _mm_set1_ps(scalar));
        return *this;
    }

    template<>
    template<>
    TST_INLINE vec<4, float>& TST_CALL vec<4, float>::operator-=(vec<4, float> const& v) noexcept {
        simd_form = _mm_sub_ps(simd_form, v.simd_form);
        return *this;
    }

    template<>
    template<>
    TST_INLINE vec<4, float>& TST_CALL vec<4, float>::operator*=(float scalar) noexcept {
        simd_form = _mm_mul_ps(simd_form, _mm_set1_ps(scalar));
        return *this;
    }

    template<>
    template<>
    TST_INLINE vec<4, float>& TST_CALL vec<4, float>::operator*=(vec<4, float> const& v) noexcept {
        simd_form = _mm_mul_ps(simd_form, v.simd_form);
        return *this;
    }

    template<>
    template<>
    TST_INLINE vec<4, float>& TST_CALL vec<4, float>::operator/=(float scalar) noexcept {
        simd_form = _mm_div_ps(simd_form, _mm_set1_ps(scalar));
        return *this;
    }

    template<>
    template<>
    TST_INLINE vec<4, float>& TST_CALL vec<4, float>::operator/=(vec<4, float> const& v) noexcept {
        simd_form = _mm_div_ps(simd_form, v.simd_form);
        return *this;
    }

    //boolean operators

    template<>
    constexpr bool TST_CALL operator==(vec<4, float> const& v1, vec<4, float> const& v2) noexcept {
        return vec<4, float> (_mm_cmpeq_ps(v1.simd_form, v2.simd_form));
    }

    template<>
    constexpr bool TST_CALL operator!=(vec<4, float> const& v1, vec<4, float> const& v2) noexcept {
        return _mm_cmpneq_ps(v1.simd_form, v2.simd_form);
    }

    //unary operators

    template<typename T>
    constexpr vec<4, T> TST_CALL operator+(vec<4, T> const& v) noexcept {
        return v;
    }

    template<typename T>
    constexpr vec<4, T> TST_CALL operator-(vec<4, T> const& v) noexcept {
        return vec<4, T>(0) -= v;
    }

    //binary operators

    template<typename T>
    constexpr vec<4, T> TST_CALL operator+(vec<4, T> const& v, T scalar) noexcept {
        return vec<4, T>(v) += scalar;
    }

    template<typename T>
    constexpr vec<4, T> TST_CALL operator+(T scalar, vec<4, T> const& v) noexcept {
        return vec<4, T>(v) += scalar;
    }

    template<typename T>
    constexpr vec<4, T> TST_CALL operator+(vec<4, T> const& v1, vec<4, T> const& v2) noexcept {
        return vec<4, T>(v1) += v2;
    }

    template<typename T>
    constexpr vec<4, T> TST_CALL operator-(vec<4, T> const& v, T scalar) noexcept {
        return vec<4, T>(v) -= scalar;
    }

    template<typename T>
    constexpr vec<4, T> TST_CALL operator-(T scalar, vec<4, T> const& v) noexcept {
        return vec<4, T>(v) -= scalar;
    }

    template<typename T>
    constexpr vec<4, T> TST_CALL operator-(vec<4, T> const& v1, vec<4, T> const& v2) noexcept {
        return vec<4, T>(v1) -= v2;
    }

    template<typename T>
    constexpr vec<4, T> TST_CALL operator*(vec<4, T> const& v, T scalar) noexcept {
        return vec<4, T>(v) *= scalar;
    }

    template<typename T>
    constexpr vec<4, T> TST_CALL operator*(T scalar, vec<4, T> const& v) noexcept {
        return vec<4, T>(v) *= scalar;
    }

    template<typename T>
    constexpr vec<4, T> TST_CALL operator*(vec<4, T> const& v1, vec<4, T> const& v2) noexcept {
        return vec<4, T>(v1) *= v2;
    }

    template<typename T>
    constexpr vec<4, T> TST_CALL operator/(vec<4, T> const& v, T scalar) noexcept {
        return vec<4, T>(v) /= scalar;
    }

    template<typename T>
    constexpr vec<4, T> TST_CALL operator/(T scalar, vec<4, T> const& v) noexcept {
        return vec<4, T>(v) /= scalar;
    }

    template<typename T>
    constexpr vec<4, T> TST_CALL operator/(vec<4, T> const& v1, vec<4, T> const& v2) noexcept {
        return vec<4, T>(v1) /= v2;
    }
}