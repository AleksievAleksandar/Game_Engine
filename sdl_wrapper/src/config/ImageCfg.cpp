#include "sdl_wrapper/config/ImageCfg.h"

#include "../../common_defines/Common_Defines.h"

namespace 
{
	constexpr auto PRESS_KEYS_LOCATION = "../resources/pictures/press_keys.png";
	constexpr auto PRESS_UP_LOCATION = "../resources/pictures/up.png";
	constexpr auto PRESS_DOWN_LOCATION = "../resources/pictures/down.png";
	constexpr auto PRESS_LEFT_LOCATION = "../resources/pictures/left.png";
	constexpr auto PRESS_RIGHT_LOCATION = "../resources/pictures/right.png";
	constexpr auto PRESS_LAYER_2_LOCATION = "../resources/pictures/layer_2.png";
}

namespace 
{
	constexpr auto PRESS_KEYS_IMG_HEIGHT = 480;
	constexpr auto PRESS_KEYS_IMG_WIDTH = 640;

	constexpr auto UP_IMG_HEIGHT = 640;
	constexpr auto UP_IMG_WIDTH = 640;

	constexpr auto DOWN_IMG_HEIGHT = 640;
	constexpr auto DOWN_IMG_WIDTH = 640;

	constexpr auto LEFT_IMG_HEIGHT = 640;
	constexpr auto LEFT_IMG_WIDTH = 640;

	constexpr auto RIGHT_IMG_HEIGHT = 640;
	constexpr auto RIGHT_IMG_WIDTH = 640;

	constexpr auto LAYER_2_IMG_HEIGHT = 150;
	constexpr auto LAYER_2_IMG_WIDTH = 150;
}

std::vector<std::string> ImageCfg::getImagePaths()
{
	//Load image from disk
	std::vector<std::string> imagePaths(Textures::COUNT);

	imagePaths[Textures::PRESS_KEYS] = PRESS_KEYS_LOCATION;
	imagePaths[Textures::UP] = PRESS_UP_LOCATION;
	imagePaths[Textures::DOWN] = PRESS_DOWN_LOCATION;
	imagePaths[Textures::LEFT] = PRESS_LEFT_LOCATION;
	imagePaths[Textures::RIGHT] = PRESS_RIGHT_LOCATION;
	imagePaths[Textures::LAYER_2] = PRESS_LAYER_2_LOCATION;

	return imagePaths;
}

std::unordered_map<int32_t, Rectangle> ImageCfg::getImageSizes()
{
	std::unordered_map<int32_t, Rectangle> imageSizes;

	Rectangle rect(0, 0, PRESS_KEYS_IMG_WIDTH, PRESS_KEYS_IMG_HEIGHT);
	imageSizes.insert(std::make_pair(Textures::PRESS_KEYS, rect));

	rect.x = 0;
	rect.y = 0;
	rect.w = UP_IMG_WIDTH;
	rect.h = UP_IMG_HEIGHT;
	imageSizes.insert(std::make_pair(Textures::UP, rect));

	rect.x = 0;
	rect.y = 0;
	rect.w = DOWN_IMG_WIDTH;
	rect.h = DOWN_IMG_HEIGHT;
	imageSizes.insert(std::make_pair(Textures::DOWN, rect));

	rect.x = 0;
	rect.y = 0;
	rect.w = LEFT_IMG_WIDTH;
	rect.h = LEFT_IMG_HEIGHT;
	imageSizes.insert(std::make_pair(Textures::LEFT, rect));

	rect.x = 0;
	rect.y = 0;
	rect.w = RIGHT_IMG_WIDTH;
	rect.h = RIGHT_IMG_HEIGHT;
	imageSizes.insert(std::make_pair(Textures::RIGHT, rect));

	rect.x = 0;
	rect.y = 0;
	rect.w = LAYER_2_IMG_WIDTH;
	rect.h = LAYER_2_IMG_HEIGHT;
	imageSizes.insert(std::make_pair(Textures::LAYER_2, rect));

	return imageSizes;
}
