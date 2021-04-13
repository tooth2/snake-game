#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"
#include <memory>
#include <vector>

class Controller {
 public:

  void HandleInput(bool &running, std::vector<std::shared_ptr<Snake>> &snake) const;
  int GetKeyMove(){return *key_moves.get();}
  
 private:
  
   std::unique_ptr<int> key_moves = std::make_unique<int>();
   /**
   * Function to change direction of the snake based on the keyboard input
   * @param snake
   * @param input
   * @param opposite
   */
  void ChangeDirection(std::shared_ptr<Snake> snake, Snake::Direction input,
                       Snake::Direction opposite) const;
  
};

#endif
