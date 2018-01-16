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

    template <>
    TST_INLINE vec<4, float> TST_CALL dot(const vec<4, float>& v) noexcept {

    }

    template <>
    TST_INLINE vec<4, float> TST_CALL cross(const vec<4, float>& v) noexcept {

    }
}