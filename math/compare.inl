// This file is part of Tempest-math project
// Author: Karol Kontny


namespace tst {

    template<typename T>
    constexpr T TST_CALL epsilonEq(const T v1, const T v2, const T epsilon) noexcept {
        return abs(v1 - v2) < epsilon;
    }

    template<>
    constexpr vec<4, bool> TST_CALL epsilonEq(const vec<4, float> v1, const vec<4, float> v2, const float epsilon) noexcept {
        return abs(v1 - v2) < 
    }

    template<typename T>
    constexpr T TST_CALL epsilonNeq(const T v1, const T v2, const T epsilon) noexcept {
        return abs(v1 - v2) >= epsilon;
    }

    template<typename T, template<typename T> vec >
    constexpr vec<bool> TST_CALL epsilonNeq(const vec<T> v1, const vec<T> v2, const T epsilon) noexcept {

    }

}