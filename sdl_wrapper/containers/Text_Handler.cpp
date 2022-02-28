#include "Text_Handler.h"

#include <SDL_ttf.h>
#include <string>
#include <iostream>

#include "../config/TextCfg.h"

int32_t Text_Handler::loadRsrc()
{
	std::string pathLocation = TextCfg::getTextPaths();
	TTF_Font* font = TTF_OpenFont(pathLocation.c_str(), (int)4);

	if (nullptr == font)
	{
		std::cerr << "ERROR -> TTF_OpenFont() failed. Reason: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

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
