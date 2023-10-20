#include <iostream>
#include <assert.h>

#define SDL_MAIN_HANDLED
#include "SDL.h"
#include "SDL_image.h"


#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 800


int main(int argc, char *argv[])
{
    std::cout << "Hello 2D Game Engine!" << std::endl;

    // Initialize SDL and create window
    assert(SDL_Init(SDL_INIT_VIDEO)==0 && SDL_GetError());
    SDL_WindowFlags wFlags = (SDL_WindowFlags)(SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
    SDL_Window* window = SDL_CreateWindow("Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, wFlags);
    assert(window != nullptr && SDL_GetError());

    // Create renderer context
    SDL_RendererFlags rFlags = (SDL_RendererFlags)(SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, rFlags);
    assert(renderer != nullptr && SDL_GetError());

    bool isRunning = true;
    while (isRunning)
    {
        // Capture events
        SDL_Event event;
        SDL_PollEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT:
            isRunning = false;
            break;
        }

        // Render
        SDL_SetRenderDrawColor(renderer, 100, 200, 250, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

    // Clean
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

    return 0;
}
