# Parent project does not export its library target, so this CML implicitly
# depends on being added from it, i.e. the testing is done only from the build
# tree and is not feasible from an install location

project(mazeTests LANGUAGES CXX)

# ---- Tests ----

function(add_test_fn TEST_NAME)
  add_executable("${TEST_NAME}" "source/${TEST_NAME}.cpp")
  target_link_libraries("${TEST_NAME}" PRIVATE maze_lib gtest_main)

  if (OpenMP_FOUND OR OpenMP_CXX_FOUND)
    target_link_libraries("${TEST_NAME}" PRIVATE OpenMP::OpenMP_CXX)
  endif()

  if (CUDAToolkit_FOUND)
    target_include_directories("${TEST_NAME}" PRIVATE ${CUDAToolkit_INCLUDE_DIRS})
    target_link_libraries("${TEST_NAME}" PRIVATE CUDA::cudart)
    target_link_libraries("${TEST_NAME}" PRIVATE cuda_lib)
  endif()


  add_test(NAME "${TEST_NAME}" COMMAND $<TARGET_FILE:${TEST_NAME}>)
  #target_compile_features("${TEST_NAME}" PRIVATE cxx_std_20)
endfunction()

function(add_bench_fn BENCH_NAME)
  add_executable("${BENCH_NAME}" "source/${BENCH_NAME}.cpp")
  target_link_libraries("${BENCH_NAME}" PRIVATE maze_lib benchmark::benchmark_main)

  if (OpenMP_FOUND OR OpenMP_CXX_FOUND)
    target_link_libraries("${BENCH_NAME}" PRIVATE OpenMP::OpenMP_CXX)
  endif()

  if (CUDAToolkit_FOUND)
    target_include_directories("${BENCH_NAME}" PRIVATE ${CUDAToolkit_INCLUDE_DIRS})
    target_link_libraries("${BENCH_NAME}" PRIVATE CUDA::cudart)
    target_link_libraries("${BENCH_NAME}" PRIVATE cuda_lib)
  endif()

  if(NOT CMAKE_BUILD_TYPE MATCHES Debug AND NOT CMAKE_BUILD_TYPE MATCHES Coverage)
    add_test(NAME "${BENCH_NAME}" COMMAND $<TARGET_FILE:${BENCH_NAME}>)
  elseif()
    message(STATUS "Disable ${BENCH_NAME}, Performance benchmark test only run on Release/RelWithDebInfo/MinSizeRel")
  endif()
  #target_compile_features("${TEST_NAME}" PRIVATE cxx_std_20)
endfunction()

if(NOT WIN32)
include(../cmake/lib/gtest.cmake)
include(../cmake/lib/benchmark.cmake)
  # Add tests
  add_test_fn(maze_test)

  # Add bench
  add_bench_fn(maze_bench)
endif()

# ---- End-of-file commands ----

add_folders(Test)
