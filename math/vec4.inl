// This file is part of Tempest-math project
// Author: Karol Kontny

namespace tst {
namespace math {

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
    TST_FUNC_SPEC vec<4, T>::vec(typename simd_type<T>::type simd)
        : simd_form(simd)
    {}

    template <typename T>
    TST_FUNC_SPEC vec<4, T>::vec(vec<4, T> const &v, T _w)
        : simd_form(v.simd_form)
    {
        w = _w;
    }

    template<typename T>
    TST_INLINE T& TST_CALL vec<4, T>::operator[](length_t i) noexcept {
        assert(i >= 0 && i <= length());
        return data[i];
    }

    template<typename T>
    constexpr T const & vec<4, T>::operator[](length_t i) const noexcept {
        assert(i >= 0 && i <= length());
        return data[i];
    }


    // conversion operators

#if !TST_COMPILER & TST_COMPILER_VC //This code crashes MSVS 2015 & 2017, works on gcc

    template<typename T>
    constexpr vec<4, T>::operator bool() const noexcept {
        return x | y | z | w;
    }
#endif


    template<>
    constexpr vec<4, float>::operator bool() const noexcept {
        return x != 0.0f && y != 0.0f && z != 0.0f && w != 0.0f;
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
    TST_INLINE bool TST_CALL operator==(vec<4, float> const& v1, vec<4, float> const& v2) noexcept {
        vec<4, float> res(_mm_cmpeq_ps(v1.simd_form, v2.simd_form));
        return res.x != 0.0f && res.y != 0.0f && res.z != 0.0f && res.w != 0.0f;
    }

    template<>
    TST_INLINE bool TST_CALL operator!=(vec<4, float> const& v1, vec<4, float> const& v2) noexcept {
        vec<4, float> res (_mm_cmpneq_ps(v1.simd_form, v2.simd_form));
        return res.x != 0.0f || res.y != 0.0f || res.z != 0.0f || res.w != 0.0f;
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

    //comparison operators

    template<>
    TST_INLINE vec<4, std::uint32_t> TST_CALL operator<(vec<4, float> const& v1, vec<4, float> const& v2) noexcept {
        auto res = _mm_cmplt_ps(v1.simd_form, v2.simd_form);
        vec<4, std::uint32_t>::simd* res_ptr = reinterpret_cast<vec<4, std::uint32_t>::simd*>(&res);
        return vec<4, std::uint32_t>(*res_ptr);
    }

    template<>
    TST_INLINE vec<4, std::uint32_t> TST_CALL operator<=(vec<4, float> const& v1, vec<4, float> const& v2) noexcept {
        auto res = _mm_cmple_ps(v1.simd_form, v2.simd_form);
        vec<4, std::uint32_t>::simd* res_ptr = reinterpret_cast<vec<4, std::uint32_t>::simd*>(&res);
        return vec<4, std::uint32_t>(*res_ptr);
    }

    template<>
    TST_INLINE vec<4, std::uint32_t> TST_CALL operator>(vec<4, float> const& v1, vec<4, float> const& v2) noexcept {
        auto res = _mm_cmpgt_ps(v1.simd_form, v2.simd_form);
        vec<4, std::uint32_t>::simd* res_ptr = reinterpret_cast<vec<4, std::uint32_t>::simd*>(&res);
        return vec<4, std::uint32_t>(*res_ptr);
    }

    template<>
    TST_INLINE vec<4, std::uint32_t> TST_CALL operator>=(vec<4, float> const& v1, vec<4, float> const& v2) noexcept {
        auto res = _mm_cmpge_ps(v1.simd_form, v2.simd_form);
        vec<4, std::uint32_t>::simd* res_ptr = reinterpret_cast<vec<4, std::uint32_t>::simd*>(&res);
        return vec<4, std::uint32_t>(*res_ptr);
    }
} //namespace math
} //namespace tst