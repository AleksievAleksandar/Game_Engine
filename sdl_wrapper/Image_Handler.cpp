#include "Image_Handler.h"
#include "SDL_Helpers.h"
#include "SDL_Render.h"
#include "config/ImageCfg.h"

#include <SDL_image.h>
#include <iostream>
#include <string>

int32_t Image_Handler::loadImage()
{
	std::vector<std::string> imagePaths = ImageCfg::getImageParhs();
	this->_textureDimensions = ImageCfg::getImageSizes();

	for (int32_t i = 0; i < Textures::COUNT; i++)
	{
		SDL_Surface* tempImg = IMG_Load(imagePaths[i].c_str());
		if (nullptr == tempImg)
		{
			std::cerr << "ERROR -> Unable to load image " << imagePaths[i] << ". SDL_Error: " << SDL_GetError() << std::endl;
			return EXIT_FAILURE;
		}

		this->_textures[i] = SDL_Helpers::getTextureFromSurface(tempImg);
		SDL_FreeSurface(tempImg);
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

std::vector<std::pair<SDL_Texture*, DrawParams> > Image_Handler::collectImagesForDrawing(const std::vector<DrawParams>& drawParams) const
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

std::pair<SDL_Texture*, Rectangle> Image_Handler::getImage(const int32_t rsrcId) const
{
	auto it = this->_textures.find(rsrcId);

	if (it == this->_textures.end())
	{
		std::cerr << "ERROR -> you're providing non existing rsrcId: " << rsrcId << " to Image_Handler::getImage()." << std::endl;
		return std::pair<SDL_Texture*, Rectangle>(nullptr, Rectangle::UNKNOWN);
	}

	auto itDimen = this->_textureDimensions.find(rsrcId);

	return std::pair<SDL_Texture*, Rectangle>(it->second, itDimen->second);
}

std::unordered_map<int32_t, Rectangle> Image_Handler::getImagesDimensions() const
{
	return this->_textureDimensions;
}
