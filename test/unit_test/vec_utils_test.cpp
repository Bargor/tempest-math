// This file is part of Tempest-math project
// Author: Karol Kontny

#include "gtest/gtest.h"
#include "tstmath.h"

namespace tst {

    TEST(VecUtilsTest, allTrue) {
        vec<4, std::uint32_t> v(1, 2, 3, 4);
        bool res = all(v);
        EXPECT_TRUE(res);
    }

    TEST(VecUtilsTest, allFalse) {
        vec<4, std::uint32_t> v(1, 2, 3, 0);
        bool res = all(v);
        EXPECT_FALSE(res);
    }

    TEST(VecUtilsTest, anyTrue) {
        vec<4, std::uint32_t> v(0, 2, 0, 0);
        bool res = any(v);
        EXPECT_TRUE(res);
    }

    TEST(VecUtilsTest, anyFalse) {
        vec<4, std::uint32_t> v(0, 0, 0, 0);
        bool res = all(v);
        EXPECT_FALSE(res);
    }

    TEST(VecUtilsTest, not) {
        vec<4, std::uint32_t> v(0, 1, 0, 1);
        vec<4, std::uint32_t> res = not(v);
        EXPECT_TRUE(res.x);
        EXPECT_FALSE(res.y);
        EXPECT_TRUE(res.z);
        EXPECT_FALSE(res.w);
    }
}