#include "SDL_Loader.h"

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

	return EXIT_SUCCESS;
}

void SDL_Loader::deinit()
{
	//Quit SDL subsystems
	SDL_Quit();
}

//int32_t SDL_Loader::draw() const
//{
//	//Apply(update) the image
//	std::vector<SDL_Surface*> images = this->imageHandler.imagesForDrawing();
//	for (size_t i = 0; i < images.size(); i++)
//	{
//		SDL_BlitSurface(images[i], nullptr, this->_surface, nullptr);
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
