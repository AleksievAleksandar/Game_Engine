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

	for (int32_t i = 0; i < ImageType::COUNT; i++)
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
	this->_currentTextureImage = this->_texturesImages[ImageType::PRESS_KEYS];
	
	return EXIT_SUCCESS;
}

void Image_Handler::deinit()
{
	////Deallocate surface
	//for (int32_t i = 0; i < ImageType::COUNT; i++)
	//{
	//	if (nullptr != this->_images[i])
	//	{
	//		SDL_FreeSurface(this->_images[i]);
	//		this->_images[i] = nullptr;
	//	}
	//}

	//if (nullptr != this->_currentImage)
	//{
	//	this->_currentImage = nullptr;
	//}

	for (size_t i = 0; i < COUNT; i++)
	{
		SDL_DestroyTexture(this->_texturesImages[i]);
		this->_texturesImages[i] = nullptr;
	}

	if (nullptr != this->_currentTextureImage)
	{
		this->_currentTextureImage = nullptr;
	}
}

std::vector<SDL_Texture*> Image_Handler::imagesForDrawing() const
{
	std::vector<SDL_Texture*> images;

	//images.push_back(this->_texturesImages[LAYER_2]);
	images.push_back(this->_currentTextureImage);

	return images;
}

void Image_Handler::setCurrentImage(const ImageType& type)
{
	switch (type)
	{
	case ImageType::UP:
		this->_currentTextureImage = this->_texturesImages[UP];
		break;

	case ImageType::DOWN:
		this->_currentTextureImage = this->_texturesImages[DOWN];
		break;

	case ImageType::LEFT:
		this->_currentTextureImage = this->_texturesImages[LEFT];
		break;

	case ImageType::RIGHT:
		this->_currentTextureImage = this->_texturesImages[RIGHT];
		break;

	case ImageType::PRESS_KEYS:
		this->_currentTextureImage = this->_texturesImages[PRESS_KEYS];
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
