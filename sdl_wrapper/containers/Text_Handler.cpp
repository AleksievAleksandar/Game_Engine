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

std::vector<SDL_Texture*> Text_Handler::collectTexturesForDrawing(const std::vector<int32_t>& rsrcId) const
{
	(void)rsrcId;
	return this->_textures;
}

void Text_Handler::createTexturesFromFonts()
{
}
