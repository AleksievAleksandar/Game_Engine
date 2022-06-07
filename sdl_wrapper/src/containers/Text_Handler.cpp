#include "sdl_wrapper/containers/Text_Handler.h"

#include <SDL_ttf.h>
#include <string>
#include <iostream>

#include "sdl_wrapper/config/TextCfg.h"
#include "sdl_wrapper/SDL_Helpers.h"
#include "utils/drawing/Color.h"

int32_t Text_Handler::loadRsrc()
{
	std::vector<std::pair<std::string, int32_t> > pathLocations = TextCfg::getFontsPaths();
	for (size_t i = 0; i < pathLocations.size(); i++)
	{
		TTF_Font* font = TTF_OpenFont(pathLocations[i].first.c_str(), pathLocations[i].second);

		if (nullptr == font)
		{
			std::cerr << "ERROR -> TTF_OpenFont() failed for path location: " << pathLocations[i].first << ". Reason: " << SDL_GetError() << std::endl;
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

void Text_Handler::collectTexturesForDrawing(std::vector<SDL_Texture*>& outCollection, const std::vector<DrawParams>& drawParams) const
{
	for (size_t i = 0; i < drawParams.size(); i++)
	{
		if (drawParams[i].widgetType == WidgetType::TEXT)
		{
			if (0 > drawParams[i].rsrcId || static_cast<int32_t>(this->_textures.size()) <= drawParams[i].rsrcId)
			{
				std::cerr << "ERROR -> Text_Handler::collectTexturesForDrawing() failed. Providing invalid rsrcId: " << drawParams[i].rsrcId 
						  << ". The size of _textures[] is: " << this->_textures.size() << std::endl;
				break;
			}
			outCollection.push_back(this->_textures[drawParams[i].rsrcId]);
		}
	}
}

SDL_Texture* Text_Handler::createTextTexture(TTF_Font* font, const std::string& text, const Color& color, int32_t& outTextWidth, int32_t& outTextHeight)
{
	SDL_Surface* textSurface = SDL_Helpers::getSurfaceFromFont(font, text, color);
	outTextHeight = textSurface->h;
	outTextWidth = textSurface->w;

	SDL_Texture* textTexture = SDL_Helpers::getTextureFromSurface(textSurface);
	if (nullptr == textTexture)
	{
		std::cerr << "ERROR -> Text_Handler::createTextTexture() failed. Reason: can not create texture from surface." << std::endl;
	}

	return textTexture;
}

void Text_Handler::createText(const int32_t fontTypeIdx, const std::string& text, const Color& color, int32_t& outTextWidth, int32_t& outTextHeight)
{
	auto it = this->_fonts.find(fontTypeIdx);
	if (it == this->_fonts.end())
	{
		std::cerr << "ERROR -> Text_Handler::createText() failed. Invalid fontTypeIdx: " << fontTypeIdx << " provided." << std::endl;
		return;
	}

	SDL_Texture* textTexture = this->createTextTexture(it->second, text, color, outTextWidth, outTextHeight);
	if (nullptr == textTexture)
	{
		std::cerr << "ERROR -> Text_Handler::createText() failed. Reason: can not create texture from surface." << std::endl;
		return;
	}

	this->_textures.push_back(textTexture);
}

void Text_Handler::reloadText(const int32_t idx, const std::string& text, const Color& color, int32_t& outTextWidth, int32_t& outTextHeight)
{
	if (!this->_textures.empty() && idx < static_cast<int32_t>(this->_textures.size()))
	{
		SDL_DestroyTexture(this->_textures[idx]);
		this->_textures[idx] = nullptr;

		SDL_Texture* textTexture = this->createTextTexture(this->_fonts[idx], text, color, outTextWidth, outTextHeight);
		if (nullptr == textTexture)
		{
			std::cerr << "ERROR -> Text_Handler::reloadText() failed. Reason: can not reload texture from surface." << std::endl;
			return;
		}

		this->_textures[idx] = textTexture;
	}
	else
	{
		std::cerr << "ERROR -> Trying to reload text with invalid index: " << idx << " in Text_Handler::reloadText(). The text is not reloaded." << std::endl;
	}
}

void Text_Handler::collectSingleTextureForDrawing(SDL_Texture*& outCollection, const DrawParams& drawParams)
{
	if (0 > drawParams.rsrcId || static_cast<int32_t>(this->_textures.size()) <= drawParams.rsrcId)
	{
		std::cerr << "ERROR -> Text_Handler::collectTexturesForDrawing() failed. Providing invalid rsrcId: " << drawParams.rsrcId
			<< ". The size of _textures[] is: " << this->_textures.size() << std::endl;
		outCollection = nullptr;
		return;
	}
	outCollection = this->_textures[drawParams.rsrcId];
}
