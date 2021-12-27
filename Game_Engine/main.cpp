#include <cstdlib>
#include <cstdint>
#include <iostream>

#include "engine/Engine.h"

int32_t main([[maybe_unused]] int argc, [[maybe_unused]] char* args[]) 
{
    Engine engine;
    engine.init();
    engine.draw();
    engine.deinit();

    return EXIT_SUCCESS;
}
