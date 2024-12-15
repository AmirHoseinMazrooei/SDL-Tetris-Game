#include "ui.h"
#include "utils.h"
#include <iostream>


// Helper function to draw a filled rounded rectangle
void DrawRoundedRectangle(SDL_Renderer* renderer, const SDL_Rect& rect, int radius, SDL_Color color)
{
    // Convert SDL_Color to RGBA
    Uint8 r = color.r;
    Uint8 g = color.g;
    Uint8 b = color.b;
    Uint8 a = color.a;

    // Draw filled rounded rectangle with SDL2_gfx
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_RenderFillRect(renderer, &rect);
}

UI::UI(SDL_Renderer* renderer, TTF_Font* font)
    : renderer(renderer), font(font)
{
    // Initialize textures
    scoreLabelTexture = CreateTexture("Score", WHITE);
    nextLabelTexture = CreateTexture("Next", WHITE);
    gameOverTexture = CreateTexture("Game Over", WHITE);
}

UI::~UI()
{
    // Clean up textures
    SDL_DestroyTexture(scoreLabelTexture);
    SDL_DestroyTexture(nextLabelTexture);
    SDL_DestroyTexture(gameOverTexture);
}

SDL_Texture* UI::CreateTexture(const std::string& text, SDL_Color color)
{
    return CreateTextureFromText(renderer, font, text, color);
}

void UI::RenderTexture(SDL_Texture* texture, const SDL_Point& position)
{
    if (!texture)
        return;

    SDL_Rect dst;
    dst.x = position.x;
    dst.y = position.y;
    SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);
    SDL_RenderCopy(renderer, texture, NULL, &dst);
}

void UI::Render(const Game& game)
{
    // Define semi-transparent color for rectangles
    SDL_Color semiTransparentBlack = SEMI_TRANSPARENT_BLACK;

    // Draw rounded rectangles behind "Score" and "Next"
    DrawRoundedRectangle(renderer, SCORE_RECT, 15, semiTransparentBlack);
    DrawRoundedRectangle(renderer, NEXT_RECT, 15, semiTransparentBlack);

    // Render "Score" and "Next" labels
    RenderTexture(scoreLabelTexture, SCORE_TEXT_POS);
    RenderTexture(nextLabelTexture, NEXT_TEXT_POS);

    // Render Score Value (centered within SCORE_RECT)
    std::string scoreStr = std::to_string(game.score);
    int scoreTextWidth = 0; // Will be set after rendering
    int scoreTextHeight = 0;
    SDL_Surface* tempSurface = TTF_RenderText_Blended(font, scoreStr.c_str(), WHITE);
    if (tempSurface)
    {
        scoreTextWidth = tempSurface->w;
        scoreTextHeight = tempSurface->h;
        SDL_FreeSurface(tempSurface);
    }
    int scoreX = SCORE_RECT.x + (SCORE_RECT.w - scoreTextWidth) / 2;
    int scoreY = SCORE_RECT.y + (SCORE_RECT.h - scoreTextHeight) / 2;
    RenderText(renderer, font, scoreStr, WHITE, scoreX, scoreY);

    // Render "GAME OVER" if needed
    if (game.gameOver)
    {
        RenderTexture(gameOverTexture, GAME_OVER_TEXT_POS);
    }
}