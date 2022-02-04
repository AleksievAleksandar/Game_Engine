#include "Renderer.h"

#include <iostream>
#include <SDL_render.h>

#include "SDL_Helpers.h"


int32_t Renderer::init(SDL_Window* window)
{
	constexpr auto unspecifiedDriverID = -1;
	this->_sdlRenderer = SDL_CreateRenderer(window, unspecifiedDriverID, SDL_RENDERER_ACCELERATED);
	if (nullptr == this->_sdlRenderer)
	{
		std::cerr << "ERROR -> SDL_CreateRenderer()" << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	if (EXIT_SUCCESS != SDL_SetRenderDrawColor(this->_sdlRenderer, 0, 255, 255, SDL_ALPHA_OPAQUE))
	{
		std::cerr << "ERROR -> SDL_SetRenderDrawColor()" << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	SDL_Helpers::copy_SDL_Renderer_ptr(this->_sdlRenderer);

	return EXIT_SUCCESS;
}

void Renderer::deinit()
{
	if (nullptr != this->_sdlRenderer)
	{
		SDL_DestroyRenderer(this->_sdlRenderer);
		this->_sdlRenderer = nullptr;
	}
}

void Renderer::clearScreen()
{
	if (EXIT_SUCCESS != SDL_RenderClear(this->_sdlRenderer))
	{
		std::cerr << "ERROR -> Renderer::SDL_RenderClear()" << SDL_GetError() << std::endl;
	}
}

void Renderer::updateScreen()
{
	//Update the screen with any rendering performed since the previous call.
	SDL_RenderPresent(this->_sdlRenderer);
}

void Renderer::drawTexture(const std::vector<SDL_Texture*>& images) const
{	
	for (size_t i = 0; i < images.size(); i++)
	{
		if (EXIT_SUCCESS != SDL_RenderCopy(this->_sdlRenderer, images[i], nullptr, nullptr))
		{
			std::cerr << "ERROR -> Renderer::SDL_RenderCopy()" << SDL_GetError() << std::endl;
		}
	}
}
