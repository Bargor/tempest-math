// This file is part of Tempest-math project
// Author: Karol Kontny

namespace tst {

    template <>
    TST_INLINE vec<4, float> TST_CALL sqrt(const vec<4, float>& v) noexcept { //sqrt version
        return vec<4, float>(_mm_sqrt_ps(v.simd_form));
    }

    TST_INLINE float TST_CALL sqrt(const float v) noexcept {
        return _mm_cvtss_f32(_mm_sqrt_ss(_mm_set_ss(v)));
    }

#if 0

    template <>
    TST_INLINE vec<4, float> TST_CALL sqrt(const vec<4, float>& v) noexcept { //alternative version needs to be benchmarked
        float approx(_mm_cvtss_f32(_mm_rsqrt_ps(v.simd_form)));
        float sqr = approx * approx * v;
        return approx * 0.5f * (3.0f - sqr);
    }

    template <>
    TST_INLINE vec<4, float> TST_CALL sqrt(const float v) noexcept { //alternative version needs to be benchmarked
        vec<4, float> approx(_mm_rsqrt_ss(v));
        vec<4, float> sqr = approx * approx * v;
        return approx * vec<4, float>(0.5f) * (vec<4, float>(3.0f) - sqr);
    }
#endif

    template <>
    TST_INLINE vec<4, float> TST_CALL sqrt_fast(const vec<4, float>& v) noexcept { //fast approximate version
        return vec<4, float>(_mm_rsqrt_ps(v.simd_form)) * v;
    }

    TST_INLINE float TST_CALL sqrt_fast(const float v) noexcept {
        return _mm_cvtss_f32(_mm_rsqrt_ss(_mm_set_ss(v))) * v;
    }

#if TST_ARCH & TST_SSE41_BIT
    template <>
    TST_INLINE float TST_CALL dot(const vec<4, float>& v1, const vec<4, float>& v2) noexcept {
        _mm_dp_ps(v1.simd_form, v2.simd_form, 0xFF);
    }

#elif TST_ARCH & TST_SSE3_BIT

    template <>
    TST_INLINE float TST_CALL dot(const vec<4, float>& v1, const vec<4, float>& v2) noexcept {
        vec<4, float> res = v1 * v2;
        vec<4, float> shuf = _mm_movehdup_ps(res.simd_form);        // broadcast elements 3,1 to 2,0
        vec<4, float> sums = _mm_add_ps(res.simd_form, shuf.simd_form);
        shuf = _mm_movehl_ps(shuf.simd_form, sums.simd_form); // high half -> low half
        sums = _mm_add_ss(sums.simd_form, shuf.simd_form);
        return _mm_cvtss_f32(sums.simd_form);
    }
#else
    template <>
    TST_INLINE float TST_CALL dot(const vec<4, float>& v1, const vec<4, float>& v2) noexcept {
        vec<4, float> res = v1 * v2;
        vec<4, float> shuf(_mm_shuffle_ps(res.simd_form, res.simd_form, _MM_SHUFFLE(2, 3, 0, 1)));  // [ C D | A B ]
        vec<4, float> sums(_mm_add_ps(res.simd_form, shuf.simd_form));      // sums = [ D+C C+D | B+A A+B ]
        shuf = _mm_movehl_ps(shuf.simd_form, sums.simd_form);      //  [   C   D | D+C C+D ]  // let the compiler avoid a mov by reusing shuf
        sums = _mm_add_ss(sums.simd_form, shuf.simd_form);
        return _mm_cvtss_f32(sums.simd_form);
    }
#endif
    template <>
    TST_INLINE vec<4, float> TST_CALL cross(const vec<4, float>& v1, const vec<4, float>& v2) noexcept {

    }

}