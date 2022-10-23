cmake_minimum_required(VERSION 3.14.0)

include(FetchContent)

FetchContent_Declare(
  backward
  GIT_REPOSITORY https://github.com/bombela/backward-cpp.git
  GIT_TAG 0ddfadc4b0f5c53e63259fe804ee595e6f01f4df) # 23-10-2022

FetchContent_MakeAvailable(backward)
