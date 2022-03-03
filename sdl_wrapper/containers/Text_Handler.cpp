#include "Text_Handler.h"

#include <SDL_ttf.h>
#include <string>
#include <iostream>

#include "../config/TextCfg.h"
#include "../SDL_Helpers.h"
#include "../../utils/drawing/Color.h"

int32_t Text_Handler::loadRsrc()
{
	std::vector<std::string> pathLocations = TextCfg::getTextPaths();
	for (size_t i = 0; i < pathLocations.size(); i++)
	{
		TTF_Font* font = TTF_OpenFont(pathLocations[i].c_str(), TextCfg::getTextSize());

		if (nullptr == font)
		{
			std::cerr << "ERROR -> TTF_OpenFont() failed for path location: " << pathLocations[i] << "Reason: " << SDL_GetError() << std::endl;
			return EXIT_FAILURE;
		}
		this->_fonts[i] = font;
	}

	return EXIT_SUCCESS;
}

void Text_Handler::deinit()
{
	for (auto& texture : this->_textures)
	{
		if (nullptr != texture)
		{
			SDL_DestroyTexture(texture);
			texture = nullptr;
		}
	}

	for (auto& it : this->_fonts)
	{
		TTF_CloseFont(it.second);
		it.second = nullptr;
	}
}

std::vector<SDL_Texture*> Text_Handler::collectTexturesForDrawing(const std::vector<int32_t>& rsrcId) const
{
	std::vector<SDL_Texture*> textures;
	for (size_t i = 0; i < rsrcId.size(); i++)
	{
		if (0 > rsrcId[i] || static_cast<int32_t>(this->_textures.size()) <= rsrcId[i])
		{
			std::cerr << "ERROR -> providing invalid rsrcId: " << rsrcId[i] << " to Text_Handler::collectTexturesForDrawing()" << std::endl;
			textures.push_back(nullptr);
			break;
		}
		textures.push_back(this->_textures[rsrcId[i]]);
	}
	return textures;
}

void Text_Handler::createText(const int32_t fontTypeIdx, const std::string& text, const Color& color)
{
	auto it = this->_fonts.find(fontTypeIdx);
	if (it == this->_fonts.end())
	{
		std::cerr << "ERROR -> Text_Handler::createText() failed. Invalid fontTypeIdx: " << fontTypeIdx << " provided." << std::endl;
		return;
	}
	SDL_Surface* textSurface = this->createTexturesFromFonts(it->second, text, color);

	SDL_Texture* textTexture = SDL_Helpers::getTextureFromSurface(textSurface);
	if (nullptr == textTexture)
	{
		std::cerr << "ERROR -> Text_Handler::createText() failed. Reason: can not create texture from surface." << std::endl;
		return;
	}
	this->_textures.push_back(textTexture);
}

SDL_Surface* Text_Handler::createTextureFromFonts(TTF_Font* font, const std::string& text, const Color& color)
{
	SDL_Color sdlColor;
	sdlColor.a = color.rgba.a;
	sdlColor.b = color.rgba.b;
	sdlColor.g = color.rgba.g;
	sdlColor.r = color.rgba.r;

	SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.c_str(), sdlColor);

	if (nullptr == textSurface)
	{
		std::cerr << "ERROR -> TTF_RenderText_Solid(). SDL_Error: " << SDL_GetError() << std::endl;
	}

	return textSurface;
}
