#include "Engine.h"

#include "../sdl_wrapper/SDL_Loader.h"

#include <cstdlib>
#include <iostream>

int32_t Engine::init()
{
	this->sdl_loader = new SDL_Loader();
	if (EXIT_SUCCESS != this->sdl_loader->init())
	{
		std::cerr << "ERROR -> Engine::init() failed. " << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

void Engine::deinit()
{
	if (nullptr != this->sdl_loader)
	{
		delete this->sdl_loader;
		this->sdl_loader = nullptr;
	}
}

int32_t Engine::draw() const
{
	return this->sdl_loader->draw();
}
