#include "sdl_wrapper/Window.h"
#include "sdl_wrapper/SDL_Loader.h"
#include "sdl_wrapper/SDL_Helpers.h"

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

//int32_t Window::draw() const
//{
//	//Apply(update) the image
//	std::vector<SDL_Surface*> images = this->imageHandler.imagesForDrawing();
//	for (size_t i = 0; i < images.size(); i++)
//	{
//		SDL_BlitSurface(images[i], nullptr, this->_windowSurface, nullptr);
//	}
//
//	//Update the window surface
//	if (EXIT_SUCCESS != SDL_UpdateWindowSurface(this->_window))
//	{
//		std::cerr << "ERROR -> SDL_UpdateWindowSurface() failed. SDL_Error: " << SDL_GetError() << std::endl;
//		return EXIT_FAILURE;
//	}
//	return EXIT_SUCCESS;
//}
