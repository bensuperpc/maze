cmake_minimum_required(VERSION 3.14.0)

include(FetchContent)

find_package(raylib_cpp QUIET)

if (NOT raylib_cpp_FOUND)
    FetchContent_Declare(raylib_cpp
        GIT_REPOSITORY https://github.com/RobLoach/raylib-cpp.git
        GIT_TAG 7323fb312297b90ab6b19c17175d142c16b4d298 # 05-08-2022
    )
    FetchContent_MakeAvailable(raylib_cpp)
endif()