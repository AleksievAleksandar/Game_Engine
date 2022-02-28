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

std::vector<std::pair<SDL_Texture*, DrawParams> > Image_Handler::collectTexturesForDrawing(const std::vector<DrawParams>& drawParams) const
{
	std::vector<std::pair<SDL_Texture*, DrawParams> > images;

	for (size_t i = 0; i < drawParams.size(); i++)
	{
		auto it = this->_textures.find(drawParams[i].rsrcId);
		if (it == this->_textures.end())
		{
			std::cerr << "ERROR -> Wrong Rsrc ID: " << drawParams[i].rsrcId << " is provided." << std::endl;
		}
		else
		{
			images.push_back(std::make_pair(it->second, drawParams[i]));
			//std::cout << this->_textureDimensions.find(drawParamsIDs[i])->second.x << " " << this->_textureDimensions.find(drawParamsIDs[i])->second.y << std::endl;
		}
	}
	return images;
}

std::pair<SDL_Texture*, Rectangle> Image_Handler::getTextures(const int32_t rsrcId) const
{
	auto it = this->_textures.find(rsrcId);
	auto itDimen = this->_textureDimensions.find(rsrcId);

	if (it == this->_textures.end() || itDimen == this->_textureDimensions.end())
	{
		std::cerr << "ERROR -> you're providing non existing rsrcId: " << rsrcId << " to Image_Handler::getImage()." << std::endl;
		return std::pair<SDL_Texture*, Rectangle>(nullptr, Rectangle::UNKNOWN);
	}

	return std::pair<SDL_Texture*, Rectangle>(it->second, itDimen->second);
}

std::unordered_map<int32_t, Rectangle> Image_Handler::getTexturesDimensions() const
{
	return this->_textureDimensions;
}
