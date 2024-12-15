#include "game.h"
#include "ui.h"
#include "constants.h"
#include "utils.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>

double lastUpdateTime = 0;

// Function to determine if a certain time interval has passed
bool EventTriggered(double interval)
{
    double currentTime = SDL_GetTicks() / 1000.0;
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main(int argc, char* argv[])
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
    {
        std::cerr << "SDL Initialization failed: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Initialize SDL_ttf
    if (TTF_Init() == -1)
    {
        std::cerr << "TTF Initialization failed: " << TTF_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Initialize SDL_mixer
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        std::cerr << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << std::endl;
        TTF_Quit();
        SDL_Quit();
        return 1;
    }

    // Create window
    SDL_Window* window = SDL_CreateWindow("SDL Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr)
    {
        std::cerr << "Window creation failed: " << SDL_GetError() << std::endl;
        Mix_CloseAudio();
        TTF_Quit();
        SDL_Quit();
        return 1;
    }

    // Create renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr)
    {
        std::cerr << "Renderer creation failed: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        Mix_CloseAudio();
        TTF_Quit();
        SDL_Quit();
        return 1;
    }

    // Load font using the helper function
    TTF_Font* font = LoadFont("Font/monogram.ttf", 50); // Adjust font size as needed
    if (font == nullptr)
    {
        // Handle error (already logged in LoadFont)
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        Mix_CloseAudio();
        TTF_Quit();
        SDL_Quit();
        return 1;
    }

    // Initialize Game and UI
    Game game(renderer);
    UI ui(renderer, font);

    bool isRunning = true;
    SDL_Event event;

    Uint32 frameStart;
    int frameTime;

    while (isRunning)
    {
        frameStart = SDL_GetTicks();

        // Event handling
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                isRunning = false;
            }
            else
            {
                // Pass other events to the game
                game.HandleInput(event);
            }
        }

        if (EventTriggered(0.2))
        {
            game.MoveBlockDown();
        }

        // Clear screen with background color
        SDL_SetRenderDrawColor(renderer, DARK_BLUE.r, DARK_BLUE.g, DARK_BLUE.b, DARK_BLUE.a);
        SDL_RenderClear(renderer);

        // Render UI elements
        ui.Render(game);

        // Draw game elements
        game.Draw();

        // Present the renderer
        SDL_RenderPresent(renderer);

        // Frame rate control
        frameTime = SDL_GetTicks() - frameStart;
        if (FRAME_DELAY > frameTime)
        {
            SDL_Delay(FRAME_DELAY - frameTime);
        }
    }

    // Clean up resources
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_CloseAudio();
    TTF_Quit();
    SDL_Quit();

    return 0;
}