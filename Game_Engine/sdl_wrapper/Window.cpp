#include "Window.h"
#include "SDL_Loader.h"
#include "SDL_Helpers.h"

#include <iostream>

int32_t Window::init()
{
	this->_sdl_loader = new SDL_Loader();
	if (EXIT_SUCCESS != this->_sdl_loader->init())
	{
		std::cerr << "ERROR -> this->sdl_loader->init() failed. " << std::endl;
		return EXIT_FAILURE;
	}

	//Create an Operation System window
	SDL_Helpers::createWindow(this->_window);
	if (nullptr == this->_window)
	{
		std::cerr << "ERROR -> Window::createWindow()" << std::endl;
		return EXIT_FAILURE;
	}

	//Get window surface
	this->_windowSurface = SDL_Helpers::getSurfaceFromWindow(this->_window);
	if (nullptr == this->_windowSurface)
	{
		std::cerr << "ERROR -> Window::getSurfaceFromWindow()" << std::endl;
		return EXIT_FAILURE;
	}
	return int32_t();
}

void Window::deinit()
{
	//Destroy window
	SDL_Helpers::destroyWindow(this->_window);

	this->_sdl_loader->deinit();

	if (nullptr != this->_sdl_loader)
	{
		delete this->_sdl_loader;
		this->_sdl_loader = nullptr;
	}
}

SDL_Window* Window::getWindow() const
{
	return this->_window;
}
