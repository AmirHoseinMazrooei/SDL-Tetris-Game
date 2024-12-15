// filepath: /c:/Users/mirhi/Documents/GitHub/SDL/SDL2_Template/SDL2_Template/utils.h
#pragma once
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <string>

// Function Declarations
TTF_Font* LoadFont(const std::string& relativePath, int fontSize);
Mix_Music* LoadMusic(const std::string& relativePath);
Mix_Chunk* LoadSound(const std::string& relativePath);

// Function to render text directly onto the renderer
void RenderText(SDL_Renderer* renderer, TTF_Font* font, const std::string& text, SDL_Color color, int x, int y);

// Function to create a texture from text (useful for pre-rendered texts)
SDL_Texture* CreateTextureFromText(SDL_Renderer* renderer, TTF_Font* font, const std::string& text, SDL_Color color);