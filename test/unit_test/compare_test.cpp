// This file is part of Tempest-math project
// Author: Karol Kontny

#include "gtest/gtest.h"
#include "tstmath.h"


namespace tst {

    TEST(CompareTest, epsilonEqScalarTrue) {
        bool r = epsilonEq(1.000f, 1.0001f, 0.001f);
        EXPECT_TRUE(r);
    }

    TEST(CompareTest, epsilonEqScalarFalse) {
        bool r = epsilonEq(1.000f, 1.0001f, 0.00001f);
        EXPECT_FALSE(r);
    }

    TEST(CompareTest, epsilonEqVectorTrue) {
        vec<4, float> v1(1.0f, 2.0f, 3.0f, 4.0f);
        vec<4, float> v2(1.0001f, 2.0001f, 3.0001f, 4.0001f);
        auto res = epsilonEq(v1, v2, 0.001f);
        EXPECT_TRUE(res.x);
        EXPECT_TRUE(res.y);
        EXPECT_TRUE(res.z);
        EXPECT_TRUE(res.w);
    }

    TEST(CompareTest, epsilonEqVectorFalse) {
        vec<4, float> v1(1.0f, 2.0f, 3.0f, 4.0f);
        vec<4, float> v2(1.0001f, 2.001f, 3.01f, 4.0001f);
        auto res = epsilonEq(v1, v2, 0.001f);
        EXPECT_TRUE(res.x);
        EXPECT_TRUE(res.y);
        EXPECT_FALSE(res.z);
        EXPECT_TRUE(res.w);
    }

    TEST(CompareTest, epsilonNeqScalarTrue) {
        bool r = epsilonNeq(1.000f, 1.0001f, 0.00001f);
        EXPECT_TRUE(r);
    }

    TEST(CompareTest, epsilonNeqScalarFalse) {
        bool r = epsilonNeq(1.000f, 1.0001f, 0.001f);
        EXPECT_FALSE(r);
    }

    TEST(CompareTest, epsilonNeqVectorTrue) {
        vec<4, float> v1(1.0f, 2.0f, 3.0f, 4.0f);
        vec<4, float> v2(1.0001f, 2.0001f, 3.0001f, 4.0001f);
        auto res = epsilonNeq(v1, v2, 0.001f);
        EXPECT_FALSE(res.x);
        EXPECT_FALSE(res.y);
        EXPECT_FALSE(res.z);
        EXPECT_FALSE(res.w);
    }

    TEST(CompareTest, epsilonNeqVectorFalse) {
        vec<4, float> v1(1.0f, 2.0f, 3.0f, 4.0f);
        vec<4, float> v2(1.0001f, 2.001f, 3.01f, 4.0001f);
        auto res = epsilonNeq(v1, v2, 0.001f);
        EXPECT_FALSE(res.x);
        EXPECT_FALSE(res.y);
        EXPECT_TRUE(res.z);
        EXPECT_FALSE(res.w);
    }
}