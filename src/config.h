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

// Compiler 

#define TST_COMPILER_VC	        0x00010000
#define TST_COMPILER_VC15       0x00010001

#define TST_COMPILER_GCC	    0x00020000
#define TST_COMPILER_GCC7       0x00020001
#define TST_COMPILER_GCC8       0x00020002

#define TST_COMPILER_CLANG      0x00040000
#define TST_COMPILER_CLANG40    0x00040001
#define TST_COMPILER_CLANG41    0x00040002
#define TST_COMPILER_CLANG42    0x00040003

// Detect compiler
#ifdef _MSC_VER
    #if _MSC_VER >= 1910
        #define TST_COMPILER TST_COMPILER_VC15
    #endif//_MSC_VER

#elif defined(__GNUC__)
    #ifdef __GNUC__ == 7
        #define TST_COMPILER (TST_COMPILER_GCC7)
    #elif __GNUC__ >= 8
        #define TST_COMPILER (TST_COMPILER_GCC8)
    #endif  

#elif defined(__clang__)
    #if defined __clang_major__ == 4 && __clang_minor__ == 0
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

// Setup inlining

#ifdef TST_COMPILER_VC 
    #define TST_INLINE __forceinline
    #define TST_NEVER_INLINE __declspec((noinline))
    #define TST_CALL __vectorcall
#elif defined(TST_COMPILER_GCC)
    #define TST_INLINE inline __attribute__((__always_inline__))
    #define TST_NEVER_INLINE __attribute__((__noinline__))
    #define TST_CALL __attribute__((fastcall)) //GCC probably don't have vectorcall
#elif defined(TST_COMPILER_CLANG)
    #define TST_INLINE inline __attribute__((__always_inline__))
    #define TST_NEVER_INLINE __attribute__((__noinline__))
    #define TST_CALL __vectorcall
#else
    #define TST_INLINE inline
    #define TST_NEVER_INLINE
#endif

// Detect instruction set
#define TST_X86_BIT     0x00000001
#define TST_SSE2_BIT    0x00000002
#define TST_SSE3_BIT    0x00000004
#define TST_SSSE3_BIT   0x00000008
#define TST_SSE41_BIT   0x00000010
#define TST_SSE42_BIT   0x00000020
#define TST_AVX_BIT     0x00000040
#define TST_AVX2_BIT    0x00000080
#define TST_AVX512_BIT  0x00000100

#define TST_ARCH_PURE   0x00000000
#define TST_ARCH_X86    TST_X86_BIT
#define TST_ARCH_SSE2   (TST_ARCH_X86 | TST_SSE2_BIT)
#define TST_ARCH_SSE3   (TST_ARCH_SSE2 | TST_SSE3_BIT)
#define TST_ARCH_SSSE3  (TST_ARCH_SSE3 | TST_SSSE3_BIT)
#define TST_ARCH_SSE41  (TST_ARCH_SSSE3 | TST_SSE41_BIT)
#define TST_ARCH_SSE42  (TST_ARCH_SSE41 | TST_SSE42_BIT)
#define TST_ARCH_AVX    (TST_ARCH_SSE42 | TST_AVX_BIT)
#define TST_ARCH_AVX2   (TST_ARCH_AVX | TST_AVX2_BIT)
#define TST_ARCH_AVX512 (TST_ARCH_AVX2 | TST_AVX512_BIT)

#ifdef __AVX2__
    #define TST_ARCH TST_ARCH_AVX2
#elif defined(__AVX__)
    #define TST_ARCH TST_ARCH_AVX
#elif defined(__SSE4_2__)
    #define TST_ARCH TST_ARCH_SSE42
#elif defined(__SSE4_1__)
    #define TST_ARCH TST_ARCH_SSE42
#elif defined(__SSSE3__)
    #define TST_ARCH TST_ARCH_SSSE3
#elif defined(__SSE3__)
    #define TST_ARCH TST_ARCH_SSE3
#elif defined(__SSE2__) || defined(__x86_64__)
    #define TST_ARCH TST_ARCH_SSE2
#elif defined(__i386__) 
    #define TST_ARCH (TST_ARCH_X86)
#else
    #define TST_ARCH (GLM_ARCH_PURE)
#endif

#if TST_ARCH & TST_AVX512_BIT
    #include <immintrin.h>
#elif TST_ARCH & TST_AVX2_BIT
    #include <immintrin.h>
#elif TST_ARCH & TST_AVX_BIT
    #include <immintrin.h>
#elif TST_ARCH & TST_SSE42_BIT
    #if GLM_COMPILER & GLM_COMPILER_CLANG
        #include <popcntintrin.h>
    #endif
    #include <nmmintrin.h>
#elif TST_ARCH & TST_SSE41_BIT
    #include <smmintrin.h>
#elif TST_ARCH & TST_SSSE3_BIT
    #include <tmmintrin.h>
#elif TST_ARCH & TST_SSE3_BIT
    #include <pmmintrin.h>
#elif TST_ARCH & TST_SSE2_BIT
    #include <emmintrin.h>
#endif//GLM_ARCH


#if TST_ARCH & TST_SSE2_BIT
typedef __m128		tst_vec4;
typedef __m128i		tst_ivec4;
typedef __m128i		tst_uvec4;
#endif

#if TST_ARCH & TST_AVX_BIT
typedef __m256d		tst_dvec4;
#endif

#if TST_ARCH & TST_AVX2_BIT
typedef __m256i		tst_i64vec4;
typedef __m256i		tst_u64vec4;
#endif