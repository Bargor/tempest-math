// This file is part of Tempest-math project
// Author: Karol Kontny

namespace tst {


    template<>
    template<>
    TST_INLINE vec<4, float>& TST_CALL vec<4, float>::operator+=(float scalar) {
        simd_form = _mm_add_ps(simd_form, _mm_set1_ps(scalar));
        return *this;
    }

    template<>
    template<>
    TST_INLINE vec<4, float>& TST_CALL vec<4,float>::operator+=(vec<4, float> const& v) {
        simd_form = _mm_add_ps(simd_form, v.simd_form);
        return *this;
    }

    template<>
    template<>
    TST_INLINE vec<4, float>& TST_CALL vec<4, float>::operator-=(float scalar) {
        simd_form = _mm_sub_ps(simd_form, _mm_set1_ps(scalar));
        return *this;
    }

    template<>
    template<>
    TST_INLINE vec<4, float>& TST_CALL vec<4, float>::operator-=(vec<4, float> const& v) {
        simd_form = _mm_sub_ps(simd_form, v.simd_form);
        return *this;
    }

    template<>
    template<>
    TST_INLINE vec<4, float>& TST_CALL vec<4, float>::operator*=(float scalar) {
        simd_form = _mm_mul_ps(simd_form, _mm_set1_ps(scalar));
        return *this;
    }

    template<>
    template<>
    TST_INLINE vec<4, float>& TST_CALL vec<4, float>::operator*=(vec<4, float> const& v) {
        simd_form = _mm_mul_ps(simd_form, v.simd_form);
        return *this;
    }

    template<>
    template<>
    TST_INLINE vec<4, float>& TST_CALL vec<4, float>::operator/=(float scalar) {
        simd_form = _mm_div_ps(simd_form, _mm_set1_ps(scalar));
        return *this;
    }

    template<>
    template<>
    TST_INLINE vec<4, float>& TST_CALL vec<4, float>::operator/=(vec<4, float> const& v) {
        simd_form = _mm_div_ps(simd_form, v.simd_form);
        return *this;
    }
}