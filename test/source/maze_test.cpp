#include "lib.hpp"

auto main() -> int
{
  auto const lib = library {};

  return lib.name == "maze" ? 0 : 1;
}
