// This file is part of Tempest-math project
// Author: Karol Kontny


namespace tst {

    template<typename T>
    TST_INLINE bool TST_CALL epsilonEq(const T v1, const T v2, const T epsilon) noexcept {
        return std::abs(v1 - v2) < epsilon;
    }

    template<>
    TST_INLINE vec<4, std::uint32_t> TST_CALL epsilonEq(const vec<4, float> v1, const vec<4, float> v2, const float epsilon) noexcept {
        return abs(v1 - v2) < vec<4, float>(_mm_set1_ps(epsilon));
    }

    template<typename T>
    TST_INLINE bool TST_CALL epsilonNeq(const T v1, const T v2, const T epsilon) noexcept {
        return std::abs(v1 - v2) >= epsilon;
    }

    template<>
    TST_INLINE vec<4, std::uint32_t> TST_CALL epsilonNeq(const vec<4, float> v1, const vec<4, float> v2, const float epsilon) noexcept {
        return abs(v1 - v2) >= vec<4, float>(_mm_set1_ps(epsilon));
    }

}