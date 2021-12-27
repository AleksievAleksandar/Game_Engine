#include <cstdlib>
#include <cstdint>
#include <iostream>

#include "sdl_wrapper/SDL_Loader.h"


//The window we'll be rendering(drawing) to
SDL_Window* globalWindow = nullptr;

//The surface(data structure) contained by the window
SDL_Surface* globalScreenSurface = nullptr;

//The image that will be loaded from disk and shown on the screen
SDL_Surface* globalImage = nullptr;

//Starts up the SDL2 library and creates window
static int32_t init() {
    //Initialize SDL
    if (EXIT_SUCCESS != SDL_Loader::init(globalWindow, globalScreenSurface, globalImage)) 
    {
        std::cerr << "ERROR -> SDL_Loader::init()" << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

//Frees media and shuts down SDL
static void deinit() 
{
    //Quit SDL subsystems
    SDL_Loader::deinit(globalWindow, globalImage);
}

static int32_t draw() 
{
    if (EXIT_SUCCESS != SDL_Loader::draw(globalWindow, globalScreenSurface, globalImage)) 
    {
        std::cerr << "ERROR -> SDL_Loader::draw()" << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int32_t main([[maybe_unused]] int argc, [[maybe_unused]] char* args[]) 
{
    //Start up SDL library and create a window
    if (EXIT_SUCCESS != init()) 
    {
        std::cerr << "init() failed" << std::endl;
        return EXIT_FAILURE;
    }

    //Draw image
    if (EXIT_SUCCESS != draw()) 
    {
        std::cerr << "draw() failed" << std::endl;
        return EXIT_FAILURE;
    }

    //Free resources and close SDL library
    deinit();

    return EXIT_SUCCESS;
}
