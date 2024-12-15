# SDL Tetris Game

This project is a Tetris game implemented using SDL. It is based on the original code from [educ8s/Cpp-Tetris-Game-with-raylib](https://github.com/educ8s/Cpp-Tetris-Game-with-raylib.git), but has been modified to use SDL instead of raylib.

## Features

- Classic Tetris gameplay
- Score tracking
- Next block preview
- Game over detection
- Sound effects and background music

## Prerequisites

- SDL2
- SDL2_ttf
- SDL2_mixer

## Getting Started

### Clone the Repository

```sh
git clone https://github.com/yourusername/SDL-Tetris-Game.git
cd SDL-Tetris-Game
```
# Game Project

## Install Dependencies
Make sure you have the required SDL libraries installed. You can download the development libraries from the SDL website.

1. Download the development libraries for SDL2, SDL2_ttf, and SDL2_mixer.
2. Extract the downloaded files.
3. Copy the include and lib folders from each library to your project directory or set up your development environment to reference these folders.

Alternatively, on Ubuntu, you can install them using your package manager:

```bash
sudo apt-get install libsdl2-dev libsdl2-image-dev libsdl2-mixer-dev libsdl2-ttf-dev
```

## Build the Project
Use the provided Visual Studio solution or compile the project using your preferred method. If you are using Visual Studio:

1. Open the `SDL2_Template.sln` solution file in Visual Studio.
2. Make sure the include and library directories for SDL2, SDL2_ttf, and SDL2_mixer are set correctly in the project properties.
3. Build the solution.

If you are using the command line, you can compile the project with `g++`:

```bash
g++ -o game main.cpp -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
```

## Run the Game
Run the compiled executable from Visual Studio or directly from the command line.

## Project Structure
The project is organized as follows:

```
.
├── Font/
│   └── monogram.ttf
├── Sounds/
│   ├── clear.wav
│   ├── music.mp3
│   └── rotate.wav
├── SDL2_Template/
│   ├── block.cpp
│   ├── block.h
│   ├── blocks.cpp
│   ├── colors.cpp
│   ├── colors.h
│   ├── constants.h
│   ├── game.cpp
│   ├── game.h
│   ├── grid.cpp
│   ├── grid.h
│   ├── main.cpp
│   ├── position.cpp
│   ├── position.h
│   ├── ui.cpp
│   ├── ui.h
│   ├── utils.cpp
│   └── utils.h
├── .gitignore
├── README.md
└── SDL2_Template.sln
```

## Acknowledgements
- Original code by [educ8s](https://github.com/educ8s)
- SDL2 library

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
