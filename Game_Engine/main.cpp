#include <cstdlib>
#include <cstdint>
#include <iostream>

#include "engine/Engine.h"

int32_t main([[maybe_unused]] int argc, [[maybe_unused]] char* args[]) 
{
    Engine engine;

    if (EXIT_SUCCESS != engine.init())
    {
        std::cerr << "ERROR -> Engine::init() failed. " << std::endl;
        return EXIT_FAILURE;
    }

    engine.start();

    engine.deinit();

    return EXIT_SUCCESS;
}
