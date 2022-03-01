#include "Text_Handler.h"

#include <SDL_ttf.h>
#include <string>
#include <iostream>

#include "../config/TextCfg.h"
#include "../SDL_Helpers.h"

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

	this->createTexturesFromFonts();

	return EXIT_SUCCESS;
}

void Text_Handler::deinit()
{
	for (auto& it : this->_fonts)
	{
		TTF_CloseFont(it.second);
		it.second = nullptr;
	}
}

std::vector<std::pair<SDL_Texture*, DrawParams>> Text_Handler::collectTexturesForDrawing(const std::vector<DrawParams>& drawParams) const
{
	return std::vector<std::pair<SDL_Texture*, DrawParams>>();
}

void Text_Handler::createTexturesFromFonts()
{
	SDL_Color color;
	color.r = 127;
	color.g = 127;
	color.b = 127;
	color.a = 255;

	for (size_t i = 0; i < this->_fonts.size(); i++)
	{
		std::string text = "Aleksandar";
		SDL_Surface* textSurface = TTF_RenderText_Solid(this->_fonts[i], text.c_str(), color);

		if (nullptr == textSurface)
		{
			std::cerr << "ERROR -> Text_Handler::createTexturesFromFonts() failed. Reason: textSurface is nullptr." << std::endl;
		}

		DrawParams drawParams;
		drawParams.h = textSurface->h;
		drawParams.w = textSurface->w;
		drawParams.pos.x = 20;
		drawParams.pos.y = 30;
		drawParams.widgetType = WidgetType::TEXT;

		this->_textures.push_back(std::make_pair(SDL_Helpers::getTextureFromSurface(textSurface), drawParams));

		SDL_FreeSurface(textSurface);
	}
}
