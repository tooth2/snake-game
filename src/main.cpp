#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include <thread>
#include <chrono>

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  std::cout << "Choose Left(Green, w,a,s,d key) or Right Snake(Blue, arrow keys): \n";

  for (int i = 3; i > 0; i --)
  {
    std::cout << i << "\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  }
  
  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight);
  std::cout << "Let's start!" << "\n";
  game.Run(controller, renderer, kMsPerFrame);
  
  if (!game.GetLeftStatus() && game.GetRightStatus()) {
    std::cout << "Left snake touched a bomb! Right snake, you win!" << "\n";
    return 0;
  }
  
  if (game.GetLeftStatus() && !game.GetRightStatus()) {
    std::cout << "Right snake touched a bomb! Left snake, you win!" << "\n";
    return 0;
  }
  
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Left Score: " << game.GetLeftScore() << "------------------";
  std::cout << "Right Score: " << game.GetRightScore() << "\n";
  std::cout << "Left Size: " << game.GetLeftSize() << "------------------";
  std::cout << "Right Size: " << game.GetRightSize() << "\n";
  if (game.GetLeftScore() > game.GetRightScore()) {
    std::cout << "Left sanke, you win!" << "\n";
  } else if (game.GetLeftScore() < game.GetRightScore()) {
    std::cout << "Right snake, you win!" << "\n";
  } else {
    std::cout << "It's a tie!" << "\n";
  }
  return 0;
}