#include "block.h"
#include "position.h"

class LBlock : public Block
{

public:
    LBlock(SDL_Renderer* renderer) : Block(renderer)
    {
        id = 1;
        cells[0] = { Position(0, 2), Position(1, 0), Position(1, 1), Position(1, 2) };
        cells[1] = { Position(0, 1), Position(1, 1), Position(2, 1), Position(2, 2) };
        cells[2] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 0) };
        cells[3] = { Position(0, 0), Position(0, 1), Position(1, 1), Position(2, 1) };
        Move(0, 3);
    }
};

class JBlock : public Block
{
public:
    JBlock(SDL_Renderer* renderer) : Block(renderer)
    {
        id = 2;
        cells[0] = { Position(0, 0), Position(1, 0), Position(1, 1), Position(1, 2) };
        cells[1] = { Position(0, 1), Position(0, 2), Position(1, 1), Position(2, 1) };
        cells[2] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 2) };
        cells[3] = { Position(0, 1), Position(1, 1), Position(2, 0), Position(2, 1) };
        Move(0, 3);
    }
};

class IBlock : public Block
{
public:
    IBlock(SDL_Renderer* renderer) : Block(renderer)
    {
        id = 3;
        cells[0] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(1, 3) };
        cells[1] = { Position(0, 2), Position(1, 2), Position(2, 2), Position(3, 2) };
        cells[2] = { Position(2, 0), Position(2, 1), Position(2, 2), Position(2, 3) };
        cells[3] = { Position(0, 1), Position(1, 1), Position(2, 1), Position(3, 1) };
        Move(-1, 3);
    }
};

class OBlock : public Block
{
public:
    OBlock(SDL_Renderer* renderer) : Block(renderer)
    {
        id = 4;
        cells[0] = { Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1) };
        Move(0, 4);
    }
};

class SBlock : public Block
{
public:
    SBlock(SDL_Renderer* renderer) : Block(renderer)
    {
        id = 5;
        cells[0] = { Position(0, 1), Position(0, 2), Position(1, 0), Position(1, 1) };
        cells[1] = { Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 2) };
        cells[2] = { Position(1, 1), Position(1, 2), Position(2, 0), Position(2, 1) };
        cells[3] = { Position(0, 0), Position(1, 0), Position(1, 1), Position(2, 1) };
        Move(0, 3);
    }
};

class TBlock : public Block
{
public:
    TBlock(SDL_Renderer* renderer) : Block(renderer)
    {
        id = 6;
        cells[0] = { Position(0, 1), Position(1, 0), Position(1, 1), Position(1, 2) };
        cells[1] = { Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 1) };
        cells[2] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 1) };
        cells[3] = { Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 1) };
        Move(0, 3);
    }
};

class ZBlock : public Block
{
public:
    ZBlock(SDL_Renderer* renderer) : Block(renderer)
    {
        id = 7;
        cells[0] = { Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2) };
        cells[1] = { Position(0, 2), Position(1, 1), Position(1, 2), Position(2, 1) };
        cells[2] = { Position(1, 0), Position(1, 1), Position(2, 1), Position(2, 2) };
        cells[3] = { Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 0) };
        Move(0, 3);
    }
};