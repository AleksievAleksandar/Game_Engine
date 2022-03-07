#include "Renderer.h"

#include <iostream>
#include <SDL_render.h>
#include <SDL_hints.h>

#include "SDL_Helpers.h"
#include "utils/drawing/DrawParams.h"

SDL_Rect createSDL_RectfromDrawParams(const DrawParams& drawParam)
{
	SDL_Rect rect;
	rect.x = drawParam.pos.x;
	rect.y = drawParam.pos.y;
	rect.w = drawParam.w;
	rect.h = drawParam.h;

	return rect;
}

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

	if (EXIT_SUCCESS != SDL_Helpers::copy_SDL_Renderer_ptr(this->_sdlRenderer))
	{
		std::cerr << "ERROR -> SDL_Helpers::copy_SDL_Renderer_ptr()" << std::endl;
		return EXIT_FAILURE;
	}
	
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

void Renderer::drawTexture(SDL_Texture* texture, const DrawParams& drawParam) const
{
	if (WidgetType::IMAGE == drawParam.widgetType)
	{
		this->drawImages(texture, drawParam);
	}
	else if (WidgetType::TEXT == drawParam.widgetType)
	{
		this->drawTexts(texture, drawParam);
	}
	else
	{
		std::cerr << "ERROR -> Unsupported WidgetType is provided to Renderer::drawTexture()" << std::endl;
	}

}

void Renderer::drawImages(SDL_Texture* texture, const DrawParams& drawParam) const
{
	SDL_Rect rect = createSDL_RectfromDrawParams(drawParam);

	if (FULL_OPACITY == drawParam.opacity)
	{
		if (EXIT_SUCCESS != SDL_RenderCopy(this->_sdlRenderer, texture, nullptr, &rect))
		{
			std::cerr << "ERROR -> Renderer::SDL_RenderCopy()" << SDL_GetError() << std::endl;
		}
	}
	else
	{
		if (EXIT_SUCCESS != SDL_Helpers::setAlphaToTexture(texture, drawParam.opacity))
		{
			std::cerr << "ERROR -> SDL_Helpers::setAlphaToTexture()" << std::endl;
		}

		if (EXIT_SUCCESS != SDL_RenderCopy(this->_sdlRenderer, texture, nullptr, &rect))
		{
			std::cerr << "ERROR -> Renderer::SDL_RenderCopy()" << SDL_GetError() << std::endl;
		}

		//Return FULL_OPACITY to texture 
		if (EXIT_SUCCESS != SDL_Helpers::setAlphaToTexture(texture, FULL_OPACITY))
		{
			std::cerr << "ERROR -> SDL_Helpers::setAlphaToTexture()" << std::endl;
		}
	}
}

void Renderer::drawTexts(SDL_Texture* texture, const DrawParams& drawParam) const
{
	SDL_Rect rect = createSDL_RectfromDrawParams(drawParam);

	if (EXIT_SUCCESS != SDL_RenderCopy(this->_sdlRenderer, texture, nullptr, &rect))
	{
		std::cerr << "ERROR -> Renderer::SDL_RenderCopy()" << SDL_GetError() << std::endl;
	}
}
