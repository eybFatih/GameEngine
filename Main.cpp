#include <iostream>
#include <assert.h>

#include "Engine.h"


int main(int argc, char *argv[])
{
    std::cout << "Hello 2D Game Engine!" << std::endl;

    Engine::GetInstance()->Init(1280, 800);

    while (Engine::GetInstance()->IsRunning())
    {
        Engine::GetInstance()->Render();
    }

    Engine::GetInstance()->Clean();

    return 0;
}
