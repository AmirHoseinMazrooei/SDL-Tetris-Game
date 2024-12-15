#pragma once
#include <SDL.h>
#include <vector>
using Color = SDL_Color;

class Grid
{
public:
    Grid(SDL_Renderer* renderer);
    void Initialize();
    void Print();
    void Draw();
    bool IsCellOutside(int row, int column);
    bool IsCellEmpty(int row, int column);
    int ClearFullRows();
    int grid[20][10];

private:
    bool IsRowFull(int row);
    void ClearRow(int row);
    void MoveRowDown(int row, int numRows);
    void DrawRectangle(int x, int y, int width, int height, Color color);
    SDL_Renderer* renderer;
    int numRows;
    int numCols;
    int cellSize;
    std::vector<Color> colors;
};