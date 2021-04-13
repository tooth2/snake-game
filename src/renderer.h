#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "snake.h"

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  //void Render(Snake const snake, SDL_Point const &food);
    /**
   * Function renders foods, bombs and snakes in the screen.
   * @param snakes
   * @param foods
   * @param bombs
   */
  void Render(const std::vector<std::shared_ptr<Snake>> &snakes,
              const std::vector<SDL_Point> &foods,
              const std::vector<SDL_Point> &bombs);
  
  void UpdateWindowTitle(int score, int fps);
    /**
   * Updates the left and the right score on the top
   * @param score_left
   * @param score_right
   * @param fps
   */
  void UpdateWindowTitle(int score_left, int score_right, int fps);


 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif