#pragma once
#include <SDL.h>

// Window dimensions
const int WINDOW_WIDTH = 500;
const int WINDOW_HEIGHT = 620;

// UI Element Positions and Sizes
const SDL_Rect SCORE_RECT = { 320, 55, 170, 60 };
const SDL_Rect NEXT_RECT = { 320, 215, 170, 180 };
const SDL_Rect GAME_OVER_RECT = { 350, 450, 100, 50 };

// Text Positions
const SDL_Point SCORE_TEXT_POS = { 360, 0 };
const SDL_Point NEXT_TEXT_POS = { 365, 160 };
const SDL_Point GAME_OVER_TEXT_POS = { 320, 450 };

// Colors
const SDL_Color WHITE = { 255, 255, 255, 255 };
const SDL_Color LIGHT_BLUE = { 173, 216, 230, 255 };
const SDL_Color DARK_BLUE = { 44, 44, 127, 255 };
const SDL_Color SEMI_TRANSPARENT_BLACK = { 0, 0, 0, 200 };

// Frame Rate
const int FRAME_RATE = 60;
const int FRAME_DELAY = 1000 / FRAME_RATE;