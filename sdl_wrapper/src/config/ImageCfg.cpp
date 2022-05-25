#include "sdl_wrapper/config/ImageCfg.h"

#include "../../common_defines/Common_Defines.h"

std::vector<std::string> ImageCfg::getImagePaths()
{
	//Load image from disk
	std::vector<std::string> imagePaths(Textures::COUNT);

	imagePaths[Textures::PRESS_KEYS] = Textures::Location::PRESS_KEYS_LOCATION;
	imagePaths[Textures::UP] = Textures::Location::PRESS_UP_LOCATION;
	imagePaths[Textures::DOWN] = Textures::Location::PRESS_DOWN_LOCATION;
	imagePaths[Textures::LEFT] = Textures::Location::PRESS_LEFT_LOCATION;
	imagePaths[Textures::RIGHT] = Textures::Location::PRESS_RIGHT_LOCATION;
	imagePaths[Textures::LAYER_2] = Textures::Location::PRESS_LAYER_2_LOCATION;

	return imagePaths;
}

std::unordered_map<int32_t, Rectangle> ImageCfg::getImageSizes()
{
	std::unordered_map<int32_t, Rectangle> imageSizes;

	Rectangle rect(0, 0, Textures::ImageSize::PRESS_KEYS_IMG_WIDTH, Textures::ImageSize::PRESS_KEYS_IMG_HEIGHT);
	imageSizes.insert(std::make_pair(Textures::PRESS_KEYS, rect));

	rect.x = 0;
	rect.y = 0;
	rect.w = Textures::ImageSize::UP_IMG_WIDTH;
	rect.h = Textures::ImageSize::UP_IMG_HEIGHT;
	imageSizes.insert(std::make_pair(Textures::UP, rect));

	rect.x = 0;
	rect.y = 0;
	rect.w = Textures::ImageSize::DOWN_IMG_WIDTH;
	rect.h = Textures::ImageSize::DOWN_IMG_HEIGHT;
	imageSizes.insert(std::make_pair(Textures::DOWN, rect));

	rect.x = 0;
	rect.y = 0;
	rect.w = Textures::ImageSize::LEFT_IMG_WIDTH;
	rect.h = Textures::ImageSize::LEFT_IMG_HEIGHT;
	imageSizes.insert(std::make_pair(Textures::LEFT, rect));

	rect.x = 0;
	rect.y = 0;
	rect.w = Textures::ImageSize::RIGHT_IMG_WIDTH;
	rect.h = Textures::ImageSize::RIGHT_IMG_HEIGHT;
	imageSizes.insert(std::make_pair(Textures::RIGHT, rect));

	rect.x = 0;
	rect.y = 0;
	rect.w = Textures::ImageSize::LAYER_2_IMG_WIDTH;
	rect.h = Textures::ImageSize::LAYER_2_IMG_HEIGHT;
	imageSizes.insert(std::make_pair(Textures::LAYER_2, rect));

	return imageSizes;
}
