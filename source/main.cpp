#include <iostream>
#include <string>
#include <vector>

#include "intro/benlib_intro.h"
#include "intro/raylib_cpp_intro.h"
#include "intro/raylib_intro.h"
#include "raylib-cpp.hpp"

//#include "lib.hpp"

auto main() -> int
{
  std::ios_base::sync_with_stdio(false);

  auto width_maze = 51;
  auto height_maze = 51;

  std::vector<uint64_t> vect(width_maze * height_maze, 0);

  // lambda function to get the index of a 2D array
  const auto maze = [&vect, width_maze, height_maze](auto x,
                                                     auto y) -> uint64_t&
  { return vect[y * width_maze + x]; };

  const auto path = 0;
  const auto internal_wall = 1;
  const auto external_wall = 2;

  const int screenWidth = 510;
  const int screenHeight = 510;

  //SetConfigFlags(FLAG_WINDOW_RESIZABLE);

  raylib::Window window(screenWidth,
                        screenHeight,
                        "raylib [shapes] example - raylib logo animation");

  SetTargetFPS(60);

  play_intro_raylib(screenWidth, screenHeight);
  play_intro_raylib_cpp(screenWidth, screenHeight);
  play_intro_benlib(screenWidth, screenHeight);

  // Generate walls maze
  for (auto y = 0; y < height_maze; y++) {
    for (auto x = 0; x < width_maze; x++) {
      // Generate the external walls
      if (x == 0 || x == width_maze - 1 || y == 0 || y == height_maze - 1) {
        maze(x, y) = external_wall;
        continue;
      }

      // Generate the internal walls
      if (x % 2 == 0 || y % 2 == 0) {
        maze(x, y) = internal_wall;
        continue;
      }
    }
  }

  // Set entrance and exit
  maze(1, 0) = path;
  maze(width_maze - 2, height_maze - 1) = path;

  // Fill path with random values
  for (auto y = 1; y < height_maze - 1; y++) {
    for (auto x = 1; x < width_maze - 1; x++) {
      if (maze(x, y) == path) {
        maze(x, y) = static_cast<uint64_t>(GetRandomValue(3, 100));
      }
    }
  }

  // Generate the maze path
  while(false){
    // Select a random internal wall
    auto x = GetRandomValue(1, width_maze - 2);
    auto y = GetRandomValue(1, height_maze - 2);

    if (maze(x, y) != internal_wall) {
      continue;
    }

    // Check if number of adjacent cells is different
    if (maze(x, y) == maze(x + 1, y) || maze(x, y) == maze(x - 1, y) ||
        maze(x, y) == maze(x, y + 1) || maze(x, y) == maze(x, y - 1)) {
      continue;
    }
  }


  while (!WindowShouldClose()) {
    Vector2 mousePosition = GetMousePosition();

    BeginDrawing();
    ClearBackground(RAYWHITE);

    for (auto y = 0; y < height_maze; y++) {
      for (auto x = 0; x < width_maze; x++) {
        if (maze(x, y) == external_wall) {
          DrawRectangle(x * 10, y * 10, 10, 10, BLACK);
        } else if (maze(x, y) == internal_wall) {
          DrawRectangle(x * 10, y * 10, 10, 10, DARKGRAY);
        } else if (maze(x, y) == path) {
          DrawRectangle(x * 10, y * 10, 10, 10, WHITE);
        } else {
          DrawRectangle(x * 10, y * 10, 10, 10, RED);
        }
      }
    }

    EndDrawing();
  }

  /*
  // print the maze
  for (auto y = 0; y < height_maze; y++) {
    for (auto x = 0; x < width_maze; x++) {
      std::cout << maze(x, y);
    }
    std::cout << std::endl;
  }
  */

  return 0;
}
