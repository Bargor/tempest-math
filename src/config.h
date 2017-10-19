// This file is part of Tempest-math project
// Author: Karol Kontny

#pragma once

#define VERSION_MAJOR 0 
#define VERSION_MINOR 0 
#define VERSION_PATCH 1


// Detect platform
#ifdef _WIN32
    #define TST_PLATFORM PLATFORM_WINDOWS
#elif defined(__linux)
    #define TST_PLATFORM PLATFORM_LINUX
#elif defined(__unix)
    #define TST_PLATFORM PLATFORM_UNIX
#else
    #define TST_PLATFORM PLATFORM_UNKNOWN
#endif//

// Detect compiler
#ifdef _MSC_VER
    #ifdef _MSC_VER >= 1910
        #define TST_COMPILER TST_COMPILER_VC15
    #endif//_MSC_VER

#elif defined(__GNUC__)
    #ifdef (__GNUC__ == 7)
        #define TST_COMPILER (TST_COMPILER_GCC7)
    #elif (__GNUC__ >= 8)
        #define TST_COMPILER (TST_COMPILER_GCC8)
    #endif  

#elif defined(__clang__)
    #ifdef __clang_major__ == 4 && __clang_minor__ == 0
        #define TST_COMPILER TST_COMPILER_CLANG40
    #elif __clang_major__ == 4 && __clang_minor__ == 1
        #define TST_COMPILER TST_COMPILER_CLANG41
    #elif __clang_major__ == 4 && __clang_minor__ >= 2
        #define TST_COMPILER TST_COMPILER_CLANG42
    #elif __clang_major__ >= 4
        #define TST_COMPILER TST_COMPILER_CLANG42
    #endif
#else
    #define TST_COMPILER TST_COMPILER_UNKNOWN
#endif

