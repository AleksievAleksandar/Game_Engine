#include <cstdlib>
#include <cstdint>
#include <iostream>

#include <SDL.h>
#include <SDL_image.h>

#include "sdl_wrapper/SDL_Loader.h"
#include "sdl_wrapper/Window.h"


//The window we'll be rendering(drawing) to
SDL_Window* globalWindow = nullptr;

//The surface(data structure) contained by the window
SDL_Surface* globalScreenSurface = nullptr;

//The image that will be loaded from disk and shown on the screen
SDL_Surface* globalImage = nullptr;

//Starts up the SDL2 library and creates window
static int32_t init() {
    //Initialize SDL
    if (EXIT_SUCCESS != SDL_Loader::init()) 
    {
        std::cerr << "ERROR -> SDL_Loader::init()" << std::endl;
        return EXIT_FAILURE;
    }

    //Create an Operation System window
    WindowCfg windowCfg;
    Window::createWindow(windowCfg, globalWindow);
    if (nullptr == globalWindow)
    {
        std::cerr << "ERROR -> Window::createWindow()" << std::endl;
        return EXIT_FAILURE;
    }

    //Get window surface
    globalScreenSurface = Window::getSurfaceFromWindow(globalWindow);

    return EXIT_SUCCESS;
}

//Loads media
static int32_t loadResources() 
{
    //Load image from disk
    globalImage = SDL_LoadBMP("../resources/hello.bmp");
    if (nullptr == globalImage) {
        std::cerr << "Unable to load image: hello.bmp SDL_Error: " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

//Frees media and shuts down SDL
static void deinit() 
{
    //Deallocate surface
    SDL_FreeSurface(globalImage);
    globalImage = nullptr;

    //Destroy window
    Window::destroyWindow(globalWindow);

    //Quit SDL subsystems
    SDL_Loader::deinit();
}

static int32_t draw() 
{
    //Apply(update) the image
    SDL_BlitSurface(globalImage, nullptr, globalScreenSurface, nullptr);

    //Update the window surface
    if (EXIT_SUCCESS != SDL_UpdateWindowSurface(globalWindow)) 
    {
        std::cerr << "SDL_UpdateWindowSurface() failed. SDL_Error: " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    //Wait three seconds before exiting
    SDL_Delay(3000);

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

    //Load image
    if (EXIT_SUCCESS != loadResources()) 
    {
        std::cerr << "loadResources() failed" << std::endl;
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
