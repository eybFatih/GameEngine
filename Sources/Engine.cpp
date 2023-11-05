#include "Engine.h"

Engine* Engine::_instance = nullptr;

/*
 *
 */
bool Engine::Init(int screenWidth, int screenHeight)
{
    _screenWidth = screenWidth;
    _screenHeight = screenHeight;

    // Initialize SDL and create window
    assert(SDL_Init(SDL_INIT_VIDEO)==0 && SDL_GetError());
    SDL_WindowFlags wFlags = (SDL_WindowFlags)(SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
    _window = SDL_CreateWindow("Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, _screenWidth, _screenHeight, wFlags);
    assert(_window != nullptr && SDL_GetError());

    // Create renderer context
    SDL_RendererFlags rFlags = (SDL_RendererFlags)(SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    _renderer = SDL_CreateRenderer(_window, -1, rFlags);
    assert(_renderer != nullptr && SDL_GetError());

    return _isRunning = true;
}

void Engine::Render()
{
    // Capture events
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type)
    {
    case SDL_QUIT:
        _isRunning = false;
        break;
    }

    // Render
    SDL_SetRenderDrawColor(_renderer, 100, 200, 250, 255);
    SDL_RenderClear(_renderer);
    SDL_RenderPresent(_renderer);
}

void Engine::Clean()
{
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindowSurface(_window);

    SDL_Quit();
    IMG_Quit();
}
