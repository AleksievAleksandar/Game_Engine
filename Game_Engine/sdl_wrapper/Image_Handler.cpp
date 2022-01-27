#include "Image_Handler.h"
#include "Window.h"
#include "SDL_Render.h"

#include <SDL_image.h>
#include <iostream>
#include <string>

int32_t Image_Handler::loadImage()
{
	//Load image from disk
	std::string imagePaths[ImageType::COUNT] = {
		"../resources/press_keys.png",
		"../resources/up.png",
		"../resources/down.png",
		"../resources/left.png",
		"../resources/right.png",
		"../resources/layer_2.png"
	};

	for (int32_t i = 0; i < ImageType::COUNT; i++)
	{
		SDL_Surface* tempImg = IMG_Load(imagePaths[i].c_str());
		//this->_images[i] = IMG_Load(imagePaths[i].c_str());
		if (nullptr == tempImg)
		{
			std::cerr << "ERROR -> Unable to load image " << imagePaths[i] << ". SDL_Error: " << SDL_GetError() << std::endl;
			return EXIT_FAILURE;
		}
		
		this->_texturesImages[i] = Window::getTextureFromSurface(tempImg);
		SDL_FreeSurface(tempImg);
	}
	//this->_currentImage = this->_images[ImageType::PRESS_KEYS];
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
