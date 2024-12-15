#pragma once
#include "grid.h"
#include "blocks.cpp"
#include <SDL_mixer.h>

using Music = Mix_Music*;
using Sound = Mix_Chunk*;

class Game
{
public:
    Game(SDL_Renderer* renderer);
    ~Game();
    void Draw();
    void HandleInput(SDL_Event &event);
    void MoveBlockDown();
    bool gameOver;
    int score;
    Music music;

private:
    SDL_Renderer *renderer;
    void MoveBlockLeft();
    void MoveBlockRight();
    Block GetRandomBlock();
    std::vector<Block> GetAllBlocks(SDL_Renderer* renderer);
    bool IsBlockOutside();
    void RotateBlock();
    void LockBlock();
    bool BlockFits();
    void Reset();
    void UpdateScore(int linesCleared, int moveDownPoints);
    Grid grid;
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
    Sound rotateSound;
    Sound clearSound;
};