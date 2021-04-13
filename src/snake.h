#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "SDL.h"
#include <memory>

class Snake {
 public:
  enum class Direction { kUp, kDown, kLeft, kRight };

  Snake(int grid_width, int grid_height, int id)
      : grid_width(grid_width),
        grid_height(grid_height),
        head_x(grid_width / 2),
        head_y(grid_height / 2),
        snake_id_(id) {}

  void Update();

  void GrowBody();
  bool SnakeCell(int x, int y);
  
  
  int GetSnakeId() const;
  

  Direction direction = Direction(rand() % 4);

  float speed{0.1f};
  int size{1};
  bool alive{true};
  float head_x;
  float head_y;
  std::vector<SDL_Point> body;

 private:
  void UpdateHead();
  void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell);

  bool growing{false};
  int grid_width;
  int grid_height;
  int snake_id_;
};

#endif