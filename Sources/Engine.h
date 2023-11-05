#ifndef ENGINE_H
#define ENGINE_H

#include <assert.h>
#include <iostream>

#define SDL_MAIN_HANDLED
#include "SDL.h"
#include "SDL_image.h"


class Engine
{
public:
    static Engine* GetInstance() {
        return _instance = (_instance != nullptr) ? _instance : new Engine();
    }

    inline bool IsRunning() { return _isRunning; }
    inline void Quit() { _isRunning = false; }

    bool Init(int screenWidth=1280, int screenHeight=800);
    void Clean();
    void Update();
    void Render();
    void Events();

private:
    Engine() {}

    static Engine* _instance;
    bool _isRunning;

    int _screenWidth;
    int _screenHeight;

    SDL_Window* _window;
    SDL_Renderer* _renderer;
};

#endif // ENGINE_H
