#include "SDL_Loader.h"
#include "Window.h"
#include "Image_Handler.h"

#include <cstdlib>
#include <iostream>
#include <SDL.h>

int32_t SDL_Loader::init()
{
	//Initialize SDL
	if (EXIT_SUCCESS != SDL_Init(SDL_INIT_VIDEO))
	{
		std::cerr << "ERROR -> SDL could not initialize. SDL_Error: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	//Create an Operation System window
	WindowCfg windowCfg;
	Window::createWindow(windowCfg, this->_window);
	if (nullptr == this->_window)
	{
		std::cerr << "ERROR -> Window::createWindow()" << std::endl;
		return EXIT_FAILURE;
	}

	//Get window surface
	this->_surface = Window::getSurfaceFromWindow(this->_window);
	if (nullptr == this->_surface)
	{
		std::cerr << "ERROR -> Window::getSurfaceFromWindow()" << std::endl;
		return EXIT_FAILURE;
	}

	if (EXIT_SUCCESS != this->imageHandler.loadImage())
	{
		std::cerr << "ERROR -> _imageHandler.loadImage()" << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

void SDL_Loader::deinit()
{
	//Deallocate surface
	this->imageHandler.deinit();

	//Destroy window
	Window::destroyWindow(this->_window);

	//Quit SDL subsystems
	SDL_Quit();
}

int32_t SDL_Loader::draw() const
{
	//Apply(update) the image
	SDL_BlitSurface(this->imageHandler._currentImage, nullptr, this->_surface, nullptr);

	//Update the window surface
	if (EXIT_SUCCESS != SDL_UpdateWindowSurface(this->_window))
	{
		std::cerr << "ERROR -> SDL_UpdateWindowSurface() failed. SDL_Error: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
