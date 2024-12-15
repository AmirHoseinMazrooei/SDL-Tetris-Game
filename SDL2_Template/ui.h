#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include "constants.h"
#include <string>
#include "game.h" // Ensure this path is correct based on your project structure

class UI
{
public:
    UI(SDL_Renderer* renderer, TTF_Font* font);
    ~UI();
    void Render(const Game& game); // Renders all UI elements

private:
    SDL_Renderer* renderer;
    TTF_Font* font;

    // Textures
    SDL_Texture* scoreLabelTexture;
    SDL_Texture* nextLabelTexture;
    SDL_Texture* gameOverTexture;

    SDL_Texture* CreateTexture(const std::string& text, SDL_Color color);

    void RenderTexture(SDL_Texture* texture, const SDL_Point& position);
};