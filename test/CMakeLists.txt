# Parent project does not export its library target, so this CML implicitly
# depends on being added from it, i.e. the testing is done only from the build
# tree and is not feasible from an install location

project(mazeTests LANGUAGES CXX)

# ---- Tests ----

add_executable(maze_test source/maze_test.cpp)
target_link_libraries(maze_test PRIVATE maze_lib)
target_compile_features(maze_test PRIVATE cxx_std_20)

add_test(NAME maze_test COMMAND maze_test)

# ---- End-of-file commands ----

add_folders(Test)
