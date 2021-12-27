#include "SDL_Loader.h"
#include "Window.h"
#include "Image_Handler.h"

#include <cstdlib>
#include <iostream>
#include <SDL.h>

int32_t SDL_Loader::init(SDL_Window*& outWindow, SDL_Surface*& outSurface, SDL_Surface*& outImage)
{
	//Initialize SDL
	if (EXIT_SUCCESS != SDL_Init(SDL_INIT_VIDEO))
	{
		std::cerr << "ERROR -> SDL could not initialize. SDL_Error: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	//Create an Operation System window
	WindowCfg windowCfg;
	Window::createWindow(windowCfg, outWindow);
	if (nullptr == outWindow)
	{
		std::cerr << "ERROR -> Window::createWindow()" << std::endl;
		return EXIT_FAILURE;
	}

	//Get window surface
	outSurface = Window::getSurfaceFromWindow(outWindow);
	if (nullptr == outSurface)
	{
		std::cerr << "ERROR -> Window::getSurfaceFromWindow()" << std::endl;
		return EXIT_FAILURE;
	}

	if (EXIT_SUCCESS != Image_Handler::loadImage(outImage))
	{
		std::cerr << "ERROR -> Image_Handler::loadImage()" << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

void SDL_Loader::deinit(SDL_Window*& outWindow, SDL_Surface*& outImage)
{
	//Deallocate surface
	Image_Handler::deinit(outImage);

	//Destroy window
	Window::destroyWindow(outWindow);

	//Quit SDL subsystems
	SDL_Quit();
}

int32_t SDL_Loader::draw(SDL_Window* window, SDL_Surface* surface, SDL_Surface* image)
{
	//Apply(update) the image
	SDL_BlitSurface(image, nullptr, surface, nullptr);

	//Update the window surface
	if (EXIT_SUCCESS != SDL_UpdateWindowSurface(window))
	{
		std::cerr << "ERROR -> SDL_UpdateWindowSurface() failed. SDL_Error: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	//Wait three seconds before exiting
	SDL_Delay(3000);

	return EXIT_SUCCESS;
}
