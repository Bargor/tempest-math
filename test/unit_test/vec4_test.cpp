// This file is part of Tempest-math project
// Author: Karol Kontny

#include "gtest/gtest.h"
#include "tstmath.h"

namespace tst {

    TEST(Vec4Test, sizeOf) {
        EXPECT_EQ(sizeof(vec4), 16);
    }

    TEST(Vec4Test, constructionScalar) {
        vec4 v(1.0f);
        EXPECT_EQ(v.x, 1.0f);
        EXPECT_EQ(v.y, 1.0f);
        EXPECT_EQ(v.z, 1.0f);
        EXPECT_EQ(v.w, 1.0f);
    }

    TEST(Vec4Test, constructionScalar4) {
        vec4 v(1.0f, 2.0f, 3.0f, 4.0f);
        EXPECT_EQ(v.x, 1.0f);
        EXPECT_EQ(v.y, 2.0f);
        EXPECT_EQ(v.z, 3.0f);
        EXPECT_EQ(v.w, 4.0f);
    }

    TEST(Vec4Test, constructionVector) {
        vec4 v(1.0f, 2.0f, 3.0f, 4.0f);
        vec4 v2(v);
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }

}