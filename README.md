# 2D Snake Game

In this game, the user controls a snake using the keyboard, and the snake grows in speed and length each time it eats the food on the screen. Internally, the game state includes:

- the speed of the snake
- the current direction the snake is travelling
- the float position of the snake's head
- a vector of int coordinates representing the snake's body
- the position of the food
- other state data needed to make the game function

At each pass through the game loop, the steps

- Input: the keyboard input is handled and used to set the future direction of the snake.
- Update: The snake's position, length, and velocity are updated. If the snake has just eaten the food, a new food item is created.
- Render: The game state is drawn to the screen. The entire game loop happens approximately 60 times per second, so the rendering and motion look fairly smooth, even though every update is a discrete change to the game state.

The positions of the snake head and snake body are not stored in a 2D array in the current implementation, even though would also be a reasonable way to store some of the game state. However, the game is still rendered according to a 2D grid, and not using continuous coordinates. This happens even though the head coordinates are stored and updated with floats. By storing the head coordinates with floats, the program updates the head position according to a fixed velocity. By rendering according to a grid, the vintage, grid-based aesthetic of the game can be maintained.

### SDL library
The SDL library is widely used for Game development as a tool to abstract the hardware. SDL manages video, audio, input devices, and other components, and provides with a simple library interface.

SDL is not a game engine, so doesn't have the full development environment like Unity, but SDL can be used to develop fully-featured games for Android, iOS, Linux, macOS, and Windows. It been used to build thousands of games, including the popular Angry Birds and games from Valve and HumbleBundle.

The latest version is SDL v2.0, also referred to as SDL2.

### Code structure
- `Main.cpp`: 
This is the entrypoint for the program. The main function in this file sets variables such as the window height and width and the number of frames per second at which the game will be played. The main also creates Renderer, Controller, and Game objects, and calls the `Game::Run` method to start the game loop.
- `snake.h` and `snake.cpp`: 
These files define the Snake class which contains attributes to keep track of the Snake speed, size, and location. Additionally, there are methods to update the snake state, which are called from the `Game::Update` method. The Snake head and body are treated separately; the head is stored using float coordinates, and the body is stored using a vector of int cell coordinates. The `Snake::UpdateHead` method updates the head location using the snake's speed. If the head has passed into a new cell, then the body is updated with the `Snake::UpdateBody`.
- `game.h` and `game.cpp`: 
These files define the Game class and the game `loop: Game::Run`. The Game class stores the state of the game, including an instance of a Snake object, the game score, and the location of "food" in the game. Aside from the game loop, the Game class also contains methods to update the state of the game (`Game::Update`), get the size of the snake, get the total score in the game, and place new food in the game if the food has been eaten by the snake.
- `render.h` and `render.cpp` : 
These files define the Renderer class which uses the SDL library to render the game to the screen. The Renderer class constructor creates the SDL window and an SDL renderer object that can draw in the window. The `Renderer::Render` method draws the food and the snake in the window using the SDL renderer.
- `controller.h` and `controller.cpp`: 
These files define the Controller class. This class handles keyboard input using the SDL libary, and it sets the snake's direction based on the input.

### Dependencies for Run time environment
* [cmake >= 3.7](https://cmake.org/install/)
* [make >= 4.1](https://developer.apple.com/xcode/features/),[Windows](http://gnuwin32.sourceforge.net/packages/make.htm)
* [SDL2 >= 2.0](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* [gcc/g++ >= 5.4](https://developer.apple.com/xcode/features/)
* [MinGW](http://www.mingw.org/)

## Basic Build Instructions
1. Make a build directory in the top level directory: `mkdir build && cd build`
2. Compile: `cmake .. && make`
3. Run it: `./SnakeGame`.

### Reference
- [Game loop](https://gameprogrammingpatterns.com/game-loop.html)
- [Game loop with SDL library](http://www.informit.com/articles/article.aspx?p=2928180&seqNum=4)
- [SDL library](https://www.libsdl.org/)
- [LazyFoo SDL2 tutorial](https://lazyfoo.net/tutorials/SDL/)
- [2D Shooter Game tutorial](https://www.parallelrealities.co.uk/tutorials/)
- [Twinklebear SDL2 tutorial](https://www.willusher.io/pages/sdl2/)
- [SDL API](https://wiki.libsdl.org/APIByCategory)
- [Game programming pattern](https://gameprogrammingpatterns.com/)
