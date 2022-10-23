#include <benchmark/benchmark.h>

#include "lib.hpp"

static void maze_bench(benchmark::State& state)
{
  // Code inside this loop is measured repeatedly
  auto range = state.range(0);

  auto const lib = library {};

  benchmark::DoNotOptimize(lib.name);
  for (auto _ : state) {
    if (lib.name == "maze") {
    }
    benchmark::ClobberMemory();
  }
  state.SetItemsProcessed(state.iterations());
  state.SetBytesProcessed(state.iterations() * sizeof(uint64_t));
}
// Register the function as a benchmark
BENCHMARK(maze_bench)
    ->Name("maze_bench")
    ->RangeMultiplier(100)
    ->Range(1, 1000000000000000);

// Run the benchmark
// BENCHMARK_MAIN();