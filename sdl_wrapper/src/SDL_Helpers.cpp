#include "sdl_wrapper/SDL_Helpers.h"
#include "sdl_wrapper/config/WindowCfg.h"

#include <SDL_video.h>
#include <SDL_render.h>
#include <iostream>

static SDL_Renderer* gRenderer = nullptr;

int32_t SDL_Helpers::createWindow(SDL_Window*& outWindow)
{
	WindowCfg winCfg;
	outWindow = SDL_CreateWindow(winCfg.windowName.c_str(), winCfg.windowPosX, winCfg.windowPosY, winCfg.SCREEN_WIDTH, winCfg.SCREEN_HEIGHT, winCfg.windowShown);
	if (nullptr == outWindow)
	{
		std::cerr << "ERROR -> SDL_CreateWindow() failed. SDL_Error: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

void SDL_Helpers::destroyWindow(SDL_Window*& outWindow)
{
	//Destroy window
	if (nullptr != outWindow)
	{
		SDL_DestroyWindow(outWindow);
		outWindow = nullptr;
	}
}

SDL_Surface* SDL_Helpers::getSurfaceFromWindow(SDL_Window* window)
{
	//Get window surface
	SDL_Surface* surface = SDL_GetWindowSurface(window);
	if (nullptr == surface)
	{
		std::cerr << "ERROR -> SDL_GetWindowSurface(). SDL_Error: " << SDL_GetError() << std::endl;
	}

	return surface;
}

SDL_Texture* SDL_Helpers::getTextureFromSurface(SDL_Surface*& surface)
{
	SDL_Texture* texture = SDL_CreateTextureFromSurface(gRenderer, surface);
	if (nullptr == texture)
	{
		std::cerr << "ERROR -> SDL_CreateTextureFromSurface(). SDL_Error: " << SDL_GetError() << std::endl;
	}

	SDL_FreeSurface(surface);
	surface = nullptr;

	return texture;
}

int32_t SDL_Helpers::copy_SDL_Renderer_ptr(SDL_Renderer* renderer)
{
	if (nullptr == renderer)
	{
		std::cerr << "ERROR -> You trying to copy SDL_Renderer* as a nullptr." << std::endl;
		return EXIT_FAILURE;
	}

	gRenderer = renderer;
	
	return EXIT_SUCCESS;
}

int32_t SDL_Helpers::setBlendModeToTexture(SDL_Texture* texture, BlendMode blendMode)
{
	if (EXIT_SUCCESS != SDL_SetTextureBlendMode(texture, static_cast<SDL_BlendMode>(blendMode)))
	{
		std::cerr << "ERROR -> SDL_SetTextureBlendMode(). SDL_Error: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

int32_t SDL_Helpers::setAlphaToTexture(SDL_Texture* texture, int32_t alpha)
{
	if (ZERO_OPACITY > alpha || FULL_OPACITY < alpha)
	{
		std::cerr << "ERROR -> Providing wrong value: " << alpha << " for alpha." << std::endl;
		return EXIT_FAILURE;
	}

	if (EXIT_SUCCESS != SDL_SetTextureAlphaMod(texture, static_cast<uint8_t>(alpha)))
	{
		std::cerr << "ERROR -> SDL_SetTextureAlphaMod(). SDL_Error: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

