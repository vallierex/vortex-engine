# Set the CMake standard
cmake_minimum_required(VERSION 4.0)

# Define project
project(vortex_engine)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 23)

# MACROS for the build configurations
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(-DVE_DEBUG)
elseif (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_definitions(-DVE_RELEASE)
endif ()

# Collect all source files for the engine
file(GLOB_RECURSE ENGINE_SOURCES CONFIGURE_DEPENDS src/*.cpp)

# Create a static library for the engine core
add_library(vortex_engine_lib STATIC ${ENGINE_SOURCES})
target_include_directories(vortex_engine_lib PUBLIC src)

# Create the executable for the engine (main app)
add_executable(vortex_engine main.cpp)
target_link_libraries(vortex_engine PRIVATE vortex_engine_lib)

# Google Test
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Collect all test source files
file(GLOB_RECURSE TEST_SOURCES tests/*.cpp)

# Create the test executable
add_executable(vortex_tests ${TEST_SOURCES})

# Link Google Test and the engine library to the test executable
target_link_libraries(vortex_tests PRIVATE gtest gtest_main gmock vortex_engine_lib)

# Enable Testing
enable_testing()
add_test(NAME RunAllTests COMMAND vortex_tests)
