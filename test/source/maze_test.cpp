#include "lib.hpp"

#include "gtest/gtest.h"

TEST(MAZE, basic_calc_base_1)
{
  auto const lib = library {};

  EXPECT_EQ(lib.name == "maze", 1);
}
