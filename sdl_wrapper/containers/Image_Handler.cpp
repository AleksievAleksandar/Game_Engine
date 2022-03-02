#include "Image_Handler.h"
#include "../SDL_Helpers.h"
#include "SDL_Render.h"
#include "../config/ImageCfg.h"

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

std::vector<SDL_Texture*> Image_Handler::collectTexturesForDrawing(const std::vector<int32_t>& rsrcId) const
{
	std::vector<SDL_Texture*> images;

	for (size_t i = 0; i < rsrcId.size(); i++)
	{
		auto it = this->_textures.find(rsrcId[i]);
		if (it != this->_textures.end())
		{
			images.push_back(it->second);
		}
		else
		{
			std::cerr << "ERROR -> Wrong Rsrc ID: " << rsrcId[i] << " is provided." << std::endl;
			break;
		}
	}
	return images;
}

std::unordered_map<int32_t, Rectangle> Image_Handler::getTexturesDimensions() const
{
	return this->_textureDimensions;
}
