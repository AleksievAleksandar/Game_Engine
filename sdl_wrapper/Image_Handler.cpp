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

		this->_texturesImages[i] = SDL_Helpers::getTextureFromSurface(tempImg);
		SDL_FreeSurface(tempImg);
	}
	this->_currentTextureImage = this->_texturesImages[Textures::PRESS_KEYS];
	
	return EXIT_SUCCESS;
}

void Image_Handler::deinit()
{
	//Deallocate texture
	for (size_t i = 0; i < Textures::COUNT; i++)
	{
		SDL_DestroyTexture(this->_texturesImages[i]);
		this->_texturesImages[i] = nullptr;
	}

	if (nullptr != this->_currentTextureImage)
	{
		this->_currentTextureImage = nullptr;
	}
}

//std::vector<SDL_Texture*> Image_Handler::imagesForDrawing() const
//{
//	std::vector<SDL_Texture*> images;
//
//	//images.push_back(this->_texturesImages[LAYER_2]);
//	images.push_back(this->_currentTextureImage);
//
//	return images;
//}

std::vector<std::pair<SDL_Texture*, Rectangle> > Image_Handler::imagesForDrawing(const std::vector<DrawParams>& drawParamsIDs) const
{
	std::vector<std::pair<SDL_Texture*, Rectangle> > images;
	Rectangle tempRect = Rectangle::UNKNOWN;

	for (size_t i = 0; i < drawParamsIDs.size(); i++)
	{
		tempRect = drawParamsIDs[i];

		images.push_back(std::make_pair(this->_texturesImages.find(drawParamsIDs[i].rsrcId)->second, tempRect));
		//std::cout << this->_textureDimensions.find(drawParamsIDs[i])->second.x << " " << this->_textureDimensions.find(drawParamsIDs[i])->second.y << std::endl;
	}

	return images;
}

void Image_Handler::setCurrentImage(const Textures::ImageType& type)
{
	switch (type)
	{
	case Textures::UP:
		this->_currentTextureImage = this->_texturesImages[Textures::UP];
		break;

	case Textures::DOWN:
		this->_currentTextureImage = this->_texturesImages[Textures::DOWN];
		break;

	case Textures::LEFT:
		this->_currentTextureImage = this->_texturesImages[Textures::LEFT];
		break;

	case Textures::RIGHT:
		this->_currentTextureImage = this->_texturesImages[Textures::RIGHT];
		break;

	case Textures::PRESS_KEYS:
		this->_currentTextureImage = this->_texturesImages[Textures::PRESS_KEYS];
		break;

	default:
		std::cerr << "ERROR -> Image_Handler::setCurrentImage() unknown image type provided." << std::endl;
		break;
	}
}

std::pair<SDL_Texture*, Rectangle> Image_Handler::getImage(const int32_t rsrcId) const
{
	auto it = this->_texturesImages.find(rsrcId);

	if (it == this->_texturesImages.end())
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
