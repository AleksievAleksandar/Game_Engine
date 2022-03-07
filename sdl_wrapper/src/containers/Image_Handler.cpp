#include "sdl_wrapper/containers/Image_Handler.h"
#include "sdl_wrapper/SDL_Helpers.h"
#include "SDL_Render.h"
#include "sdl_wrapper/config/ImageCfg.h"
#include "../../common_defines/Common_Defines.h"

#include <SDL_image.h>
#include <iostream>
#include <string>

int32_t Image_Handler::loadRsrc()
{
	std::vector<std::string> imagePaths = ImageCfg::getImageParhs();
	this->_textureDimensions = ImageCfg::getImageSizes();

	for (int32_t i = 0; i < Textures::COUNT; i++)
	{
		SDL_Surface* tempSurface = IMG_Load(imagePaths[i].c_str());
		if (nullptr == tempSurface)
		{
			std::cerr << "ERROR -> Unable to load image " << imagePaths[i] << ". SDL_Error: " << SDL_GetError() << std::endl;
			return EXIT_FAILURE;
		}

		SDL_Texture* texture = SDL_Helpers::getTextureFromSurface(tempSurface);

		//Enable Blend Mode to textures
		if (EXIT_SUCCESS != SDL_Helpers::setBlendModeToTexture(texture, BlendMode::BLEND))
		{
			std::cerr << "ERROR -> SDL_Helpers::setBlendModeToTexture() failed for file:  " << imagePaths[i] << ". SDL_Error: " << SDL_GetError() << std::endl;
			return EXIT_FAILURE;
		}

		this->_textures[i] = texture;

		SDL_FreeSurface(tempSurface);
	}

	return EXIT_SUCCESS;
}

void Image_Handler::deinit()
{
	//Deallocate texture
	for (auto& it : this->_textures)
	{
		SDL_DestroyTexture(it.second);
		it.second = nullptr;
	}
}

void Image_Handler::collectTexturesForDrawing(std::vector<SDL_Texture*>& outCollection, const std::vector<DrawParams>& drawParams) const
{
	for (size_t i = 0; i < drawParams.size(); i++)
	{
		if (drawParams[i].widgetType == WidgetType::IMAGE)
		{
			auto it = this->_textures.find(drawParams[i].rsrcId);
			if (it != this->_textures.end())
			{
				outCollection.push_back(it->second);
			}
			else
			{
				std::cerr << "ERROR -> Image_Handler::collectTexturesForDrawing() failed. Wrong Rsrc ID: " << drawParams[i].rsrcId << " is provided." << std::endl;
				break;
			}
		}
	}
}

std::unordered_map<int32_t, Rectangle> Image_Handler::getTexturesDimensions() const
{
	return this->_textureDimensions;
}