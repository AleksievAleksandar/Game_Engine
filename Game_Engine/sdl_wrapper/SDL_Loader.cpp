#include "SDL_Loader.h"

#include <cstdlib>
#include <iostream>
#include <SDL.h>

int32_t SDL_Loader::init()
{
	//Initialize SDL
	if (EXIT_SUCCESS != SDL_Init(SDL_INIT_VIDEO))
	{
		std::cerr << "SDL could not initialize. SDL_Error: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

void SDL_Loader::deinit()
{
	//Quit SDL subsystems
	SDL_Quit();
}
