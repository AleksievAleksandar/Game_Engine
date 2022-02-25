#include "Renderer.h"

#include <iostream>
#include <SDL_render.h>

#include "SDL_Helpers.h"
#include <SDL_hints.h>

int32_t Renderer::init(SDL_Window* window)
{
	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) 
	{
		std::cerr << "Warning: Linear texture filtering not enabled! SDL_SetHint() failed. SDL Error: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	constexpr auto unspecifiedDriverID = -1;
	this->_sdlRenderer = SDL_CreateRenderer(window, unspecifiedDriverID, SDL_RENDERER_ACCELERATED);
	if (nullptr == this->_sdlRenderer)
	{
		std::cerr << "ERROR -> SDL_CreateRenderer()" << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	if (EXIT_SUCCESS != SDL_SetRenderDrawColor(this->_sdlRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE))
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

void Renderer::drawTexture(const std::vector<std::pair<SDL_Texture*, DrawParams> >& images) const
{
	SDL_Rect rect;
	for (size_t i = 0; i < images.size(); i++)
	{	
		rect.x = images[i].second.pos.x;
		rect.y = images[i].second.pos.y;
		rect.w = images[i].second.w;
		rect.h = images[i].second.h;

		//std::cout << images[i].second << std::endl;

		if (FULL_OPACITY == images[i].second.opacity)
		{
			if (EXIT_SUCCESS != SDL_RenderCopy(this->_sdlRenderer, images[i].first, nullptr, &rect))
			{
				std::cerr << "ERROR -> Renderer::SDL_RenderCopy()" << SDL_GetError() << std::endl;
			}
		}
		else
		{
			if (EXIT_SUCCESS != SDL_Helpers::setAlphaToTexture(images[i].first, images[i].second.opacity))
			{
				std::cerr << "ERROR -> SDL_Helpers::setAlphaToTexture()" << std::endl;
			}

			if (EXIT_SUCCESS != SDL_RenderCopy(this->_sdlRenderer, images[i].first, nullptr, &rect))
			{
				std::cerr << "ERROR -> Renderer::SDL_RenderCopy()" << SDL_GetError() << std::endl;
			}

			//Return FULL_OPACITY state to texture 
			if (EXIT_SUCCESS != SDL_Helpers::setAlphaToTexture(images[i].first, FULL_OPACITY))
			{
				std::cerr << "ERROR -> SDL_Helpers::setAlphaToTexture()" << std::endl;
			}
		}
	}
}
