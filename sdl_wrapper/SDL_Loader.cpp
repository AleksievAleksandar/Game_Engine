#include "SDL_Loader.h"

#include <cstdlib>
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

int32_t SDL_Loader::init()
{
	//Initialize SDL
	if (EXIT_SUCCESS != SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER))
	{
		std::cerr << "ERROR -> SDL could not initialize. SDL_Error: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	if (EXIT_SUCCESS != TTF_Init())
	{
		std::cerr << "TTF_Init() failed. Reason: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	constexpr int32_t imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags)) {
		std::cerr << "SDL_image could not be initialised! SDL_image Error: " << IMG_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

void SDL_Loader::deinit()
{
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
}
