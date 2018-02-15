// This file is part of Tempest-math project
// Author: Karol Kontny

namespace tst {

    template<typename T, length_t L, template <length_t, typename> typename vec>
    TST_INLINE bool TST_CALL any(const vec<L, T> v) noexcept {
        bool res = false;
        for (length_t i = 0; i < v.length(); i++) {
            res = res || v[i];
        }
        return res;
    }

    template<typename T, length_t L, template <length_t, typename> typename vec>
    TST_INLINE bool TST_CALL all(const vec<L, T> v) noexcept {
        bool res = true;
        for (length_t i = 0; i < v.length(); i++) {
            res = res && v[i];
        }
        return res;
    }

    template<typename T, length_t L, template <length_t, typename> typename vec>
    TST_INLINE vec<L, T> TST_CALL not(const vec<L, T> v) noexcept {
        vec<L, T> res;
        for (length_t i = 0; i < v.length(); i++) {
            res[i] = !v[i];
        }
        return res;
    }

}