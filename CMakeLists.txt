cmake_minimum_required(VERSION 3.14)

include(cmake/prelude.cmake)

project(
    maze
    VERSION 0.1.0
    DESCRIPTION "maze"
    HOMEPAGE_URL "https://github.com/bensuperpc"
    LANGUAGES CXX
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

# ---- Declare library ----

add_library(
    maze_lib OBJECT
    source/lib.cpp
)

target_include_directories(
    maze_lib ${warning_guard}
    PUBLIC
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/source>"
)

target_compile_features(maze_lib PUBLIC cxx_std_20)

# ---- Declare executable ----

add_executable(maze_exe source/main.cpp)
add_executable(maze::exe ALIAS maze_exe)

set_property(TARGET maze_exe PROPERTY OUTPUT_NAME maze)

target_compile_features(maze_exe PRIVATE cxx_std_20)

target_link_libraries(maze_exe PRIVATE maze_lib)

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# ---- Developer mode ----

if(NOT maze_DEVELOPER_MODE)
  return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
  message(
      AUTHOR_WARNING
      "Developer mode is intended for developers of maze"
  )
endif()

include(cmake/dev-mode.cmake)
