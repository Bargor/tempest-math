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

	TEST(Vec4Test, length) {
		vec4 v(1.0f, 2.0f, 3.0f, 4.0f);
		EXPECT_EQ(v.length(), 4);
	}

	TEST(Vec4Test, assigment) {
		vec4 v(1.0f, 2.0f, 3.0f, 4.0f);
		vec4 v2 = v;
		EXPECT_EQ(v2.x, 1.0f);
		EXPECT_EQ(v2.y, 2.0f);
		EXPECT_EQ(v2.z, 3.0f);
		EXPECT_EQ(v2.w, 4.0f);
	}

	TEST(Vec4Test, additionVector) {
		vec4 v(1.0f, 2.0f, 3.0f, 4.0f);
		vec4 v2(1.0f, 2.0f, 3.0f, 4.0f);
		v += v2;
		EXPECT_EQ(v.x, 2.0f);
		EXPECT_EQ(v.y, 4.0f);
		EXPECT_EQ(v.z, 6.0f);
		EXPECT_EQ(v.w, 8.0f);
	}

	TEST(Vec4Test, additionScalar) {
		vec4 v(1.0f, 2.0f, 3.0f, 4.0f);
		v += 2.0f;
		EXPECT_EQ(v.x, 3.0f);
		EXPECT_EQ(v.y, 4.0f);
		EXPECT_EQ(v.z, 5.0f);
		EXPECT_EQ(v.w, 6.0f);
	}

	TEST(Vec4Test, subtraction) {
		vec4 v(2.0f, 4.0f, 6.0f, 8.0f);
		vec4 v2(1.0f, 2.0f, 3.0f, 4.0f);
		v -= v2;
		EXPECT_EQ(v.x, 1.0f);
		EXPECT_EQ(v.y, 2.0f);
		EXPECT_EQ(v.z, 3.0f);
		EXPECT_EQ(v.w, 4.0f);
	}

	TEST(Vec4Test, subtractionScalar) {
		vec4 v(3.0f, 4.0f, 5.0f, 6.0f);
		v -= 2.0f;
		EXPECT_EQ(v.x, 1.0f);
		EXPECT_EQ(v.y, 2.0f);
		EXPECT_EQ(v.z, 3.0f);
		EXPECT_EQ(v.w, 4.0f);
	}

	TEST(Vec4Test, multilpicationVector) {
		vec4 v(2.0f, 4.0f, 6.0f, 8.0f);
		vec4 v2(1.0f, 2.0f, 3.0f, 4.0f);
		v *= v2;
		EXPECT_EQ(v.x, 2.0f);
		EXPECT_EQ(v.y, 8.0f);
		EXPECT_EQ(v.z, 18.0f);
		EXPECT_EQ(v.w, 32.0f);
	}

	TEST(Vec4Test, multilpicationScalar) {
		vec4 v(2.0f, 4.0f, 6.0f, 8.0f);
		v *= 3.0f;
		EXPECT_EQ(v.x, 6.0f);
		EXPECT_EQ(v.y, 12.0f);
		EXPECT_EQ(v.z, 18.0f);
		EXPECT_EQ(v.w, 24.0f);
	}

	TEST(Vec4Test, divisionVector) {
		vec4 v(2.0f, 4.0f, 6.0f, 8.0f);
		vec4 v2(1.0f, 2.0f, 3.0f, 4.0f);
		v /= v2;
		EXPECT_EQ(v.x, 2.0f);
		EXPECT_EQ(v.y, 2.0f);
		EXPECT_EQ(v.z, 2.0f);
		EXPECT_EQ(v.w, 2.0f);
	}

	TEST(Vec4Test, divisionScalar) {
		vec4 v(6.0f, 12.0f, 18.0f, 24.0f);
		v /= 3.0f;
		EXPECT_EQ(v.x, 2.0f);
		EXPECT_EQ(v.y, 4.0f);
		EXPECT_EQ(v.z, 6.0f);
		EXPECT_EQ(v.w, 8.0f);
	}

	TEST(Vec4Test, equalityTrue) {
		vec4 v1(6.0f, 12.0f, 18.0f, 24.0f);
		vec4 v2(6.0f, 12.0f, 18.0f, 24.0f);
		EXPECT_TRUE(v1 == v2);
	}

	TEST(Vec4Test, equalityFalse) {
		vec4 v1(6.0f, 12.0f, 18.0f, 24.0f);
		vec4 v2(6.0f, 13.0f, 18.0f, 24.0f);
		EXPECT_FALSE(v1 == v2);
	}

	TEST(Vec4Test, inequalityTrue) {
		vec4 v1(6.0f, 12.0f, 18.0f, 24.0f);
		vec4 v2(6.0f, 14.0f, 18.0f, 24.0f);
		EXPECT_TRUE(v1 != v2);
	}

	TEST(Vec4Test, inequalityFalse) {
		vec4 v1(6.0f, 12.0f, 18.0f, 24.0f);
		vec4 v2(6.0f, 12.0f, 18.0f, 24.0f);
		EXPECT_FALSE(v1 != v2);
	}

}