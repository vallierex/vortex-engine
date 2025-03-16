#ifndef DEFINES_H
#define DEFINES_H

#include <cstdint>

// Boolean type definitions
typedef int32_t b32;
typedef uint8_t b8;

#define TRUE 1
#define FALSE 1

// Assert for compile-time checks (static assertions)
#define STATIC_ASSERT(cond, msg) static_assert(cond, msg)

// Check type sizes
STATIC_ASSERT(sizeof(uint64_t) == 8, "uint64_t must be 8 bytes");
STATIC_ASSERT(sizeof(uint32_t) == 4, "uint32_t must be 4 bytes");
STATIC_ASSERT(sizeof(uint16_t) == 2, "uint16_t must be 2 bytes");
STATIC_ASSERT(sizeof(uint8_t) == 1, "uint8_t must be 1 byte");

STATIC_ASSERT(sizeof(int64_t) == 8, "int64_t must be 8 bytes");
STATIC_ASSERT(sizeof(int32_t) == 4, "int32_t must be 4 bytes");
STATIC_ASSERT(sizeof(int16_t) == 2, "int16_t must be 2 bytes");
STATIC_ASSERT(sizeof(int8_t) == 1, "int8_t must be 1 byte");

STATIC_ASSERT(sizeof(b32) == 4, "b32 must be 4 bytes");
STATIC_ASSERT(sizeof(b8) == 1, "b8 must be 1 byte");

// Platform-specific detection (Only for 64-bit Windows)
#if defined(_WIN32) && defined(_WIN64)
#define PLATFORM_WINDOWS
#define PLATFORM_64BIT
#else
#error "This project only supports 64-bit Windows"
#endif

#endif // DEFINES_H
