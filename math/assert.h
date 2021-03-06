// This file is part of Tempest-math project
// Author: Karol Kontny

#pragma once
#include <cstdio>
#include <cstdlib>

namespace tst 
{
    namespace math {
        inline void _assert(const char* expression, const char* file, int line)
        {
            fprintf(stderr, "Assertion '%s' failed, file '%s' line '%d'.", expression, file, line);
            abort();
        }
    }

#undef assert

#ifdef NDEBUG
#define assert(EXPRESSION) ((void)0)
#else
#define assert(EXPRESSION) ((EXPRESSION) ? (void)0 : tst::math::_assert(#EXPRESSION, __FILE__, __LINE__))
#endif

}
