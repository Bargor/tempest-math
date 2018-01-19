// This file is part of Tempest-math project
// Author: Karol Kontny

#include "gtest/gtest.h"
#include "tstmath.h"

namespace tst {

    TEST(MathCommonTest, sqrtVector) {
        vec4 v(1.0f, 4.0f, 9.0f, 16.0f);
        v = sqrt(v);
        EXPECT_EQ(v.x, 1.0f);
        EXPECT_EQ(v.y, 2.0f);
        EXPECT_EQ(v.z, 3.0f);
        EXPECT_EQ(v.w, 4.0f);
    }

    TEST(MathCommonTest, sqrtFastVector) {
        vec4 v(1.0f, 4.0f, 9.0f, 16.0f);
        v = sqrt_fast(v);
        EXPECT_TRUE(1.0f - v.x < 0.001f );
        EXPECT_TRUE(2.0f - v.y < 0.001f);
        EXPECT_TRUE(3.0f - v.z < 0.001f);
        EXPECT_TRUE(4.0f - v.w < 0.001f);
    }

    TEST(MathCommonTest, sqrtScalar) {
        float v = 4.0f;
        v = sqrt(v);
        EXPECT_EQ(v, 2.0f);
    }

    TEST(MathCommonTest, sqrtFastScalar) {
        float v = 4.0f;
        v = sqrt_fast(v);
        EXPECT_TRUE(2.0f - v < 0.001f);
    }

    TEST(MathCommonTest, dotVector) {
        vec4 v1(1.0f, 4.0f, 9.0f, 16.0f);
        vec4 v2(2.0f, 3.0f, 4.0f, 5.0f);
        float v = dot(v1, v2);
        EXPECT_EQ(v, 130.0f);
    }

    TEST(MathCommonTest, crossVector3) {
        vec4 v1(1.0f, 2.0f, 3.0f, 0.0f);
        vec4 v2(4.0f, 5.0f, 6.0f, 0.0f);
        vec4 v = cross(v1, v2);
        EXPECT_EQ(v.x, -3.0f);
        EXPECT_EQ(v.y, 6.0f);
        EXPECT_EQ(v.z, -3.0f);
        EXPECT_EQ(v.w, 0.0f);
    }

    TEST(MathCommonTest, crossVector4) {
        vec4 v1(1.0f, 2.0f, 3.0f, 4.0f);
        vec4 v2(5.0f, 6.0f, 7.0f, 8.0f);
        vec4 v = cross(v1, v2);
        EXPECT_EQ(v.x, -4.0f);
        EXPECT_EQ(v.y, 8.0f);
        EXPECT_EQ(v.z, -4.0f);
        EXPECT_EQ(v.w, 0.0f);
    }

    TEST(MathCommonTest, vectorLength) {
        vec4 v(1.0f, 2.0f, 3.0f, 4.0f);
        float f = length(v);
        EXPECT_EQ(f, sqrt(30.0f));
    }

    TEST(MathCommonTest, vectorNormalize) {
        vec4 v(4.0f, 4.0f, 4.0f, 8.0f);
        vec4 res = normalize(v);
        EXPECT_EQ(res.x, 1.0f / sqrt(7.0f));
        EXPECT_EQ(res.y, 1.0f / sqrt(7.0f));
        EXPECT_EQ(res.z, 1.0f / sqrt(7.0f));
        EXPECT_EQ(res.w, 2.0f / sqrt(7.0f));
    }
}
