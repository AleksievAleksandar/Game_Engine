#include "Window.h"

#include <SDL_video.h>
#include <SDL_render.h>
#include <iostream>

static SDL_Renderer* gRenderer = nullptr;

int32_t Window::createWindow(const WindowCfg& winCfg, SDL_Window*& outWindow)
{
	outWindow = SDL_CreateWindow(winCfg.windowName.c_str(), winCfg.windowPosX, winCfg.windowPosY, winCfg.SCREEN_WIDTH, winCfg.SCREEN_HEIGHT, winCfg.windowShown);
	if (nullptr == outWindow)
	{
		std::cerr << "ERROR -> Windows creation failed. SDL_Error: " << SDL_GetError() << std::endl;
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
	SDL_Surface* surface = SDL_GetWindowSurface(window);
	if (nullptr == surface)
	{
		std::cerr << "ERROR -> SDL_GetWindowSurface(). SDL_Error: " << SDL_GetError() << std::endl;
	}

	return surface;
}

SDL_Texture* Window::getTextureFromSurface(SDL_Surface* surface)
{
	SDL_Texture* texture = SDL_CreateTextureFromSurface(gRenderer, surface);
	if (nullptr == texture)
	{
		std::cerr << "ERROR -> SDL_CreateTextureFromSurface(). SDL_Error: " << SDL_GetError() << std::endl;
	}

	return texture;
}

void Window::copy_SDL_Renderer_ptr(SDL_Renderer* renderer)
{
	gRenderer = renderer;
}

