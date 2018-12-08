// This file is part of Tempest-math project
// Author: Karol Kontny

#pragma once

#include "config.h"

namespace tst {
namespace math {

    typedef std::uint32_t length_t;

    template<length_t L, typename T> class vec;

    typedef vec<4, float> vec4;
    typedef vec<3, float> vec3;
    typedef vec<2, float> vec2;

    typedef vec<4, double> vec4d;
    typedef vec<3, double> vec3d;
    typedef vec<2, double> vec2d;

    typedef vec<4, std::int32_t> vec4i;
    typedef vec<3, std::int32_t> vec3i;
    typedef vec<2, std::int32_t> vec2i;

    typedef vec<4, std::uint32_t> vec4u;
    typedef vec<3, std::uint32_t> vec3u;
    typedef vec<2, std::uint32_t> vec2u;
}
}