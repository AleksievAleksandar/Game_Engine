#include "Window.h"

#include <SDL_video.h>
#include <iostream>

int32_t Window::createWindow(const WindowCfg& winCfg, SDL_Window*& outWindow)
{
	outWindow = SDL_CreateWindow(winCfg.windowName.c_str(), winCfg.windowPosX, winCfg.windowPosY, winCfg.SCREEN_WIDTH, winCfg.SCREEN_HEIGHT, winCfg.windowShown);
	if (nullptr == outWindow)
	{
		std::cerr << "Windows creation failed. SDL_Error: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

void Window::destroyWindow(SDL_Window*& outWindow)
{
	//Destroy window
	if (nullptr != outWindow)
	{
		SDL_DestroyWindow(outWindow);
		outWindow = nullptr;
	}
}

SDL_Surface* Window::getSurfaceFromWindow(SDL_Window* window)
{
	//Get window surface
	return SDL_GetWindowSurface(window);
}
