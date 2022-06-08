#include "sdl_wrapper/containers/Image_Handler.h"

#include "sdl_wrapper/SDL_Helpers.h"
#include "sdl_wrapper/config/ImageCfg.h"
#include "../../common_defines/Common_Defines.h"

#include <SDL_image.h>
#include <iostream>
#include <string>

int32_t Image_Handler::loadRsrc()
{
	std::vector<std::string> imagePaths = ImageCfg::getImagePaths();
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
	}

	return EXIT_SUCCESS;
}

void Image_Handler::deinit()
{
	IHandler::deinit();
}

std::unordered_map<int32_t, Frames> Image_Handler::getTexturesDimensions() const
{
	return this->_textureDimensions;
}
