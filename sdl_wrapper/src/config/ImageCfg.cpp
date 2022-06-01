#include "sdl_wrapper/config/ImageCfg.h"

#include "../../common_defines/Common_Defines.h"

#include <iostream>

namespace 
{
	constexpr auto PRESS_KEYS_LOCATION = "../resources/pictures/press_keys.png";
	constexpr auto PRESS_UP_LOCATION = "../resources/pictures/up.png";
	constexpr auto PRESS_DOWN_LOCATION = "../resources/pictures/down.png";
	constexpr auto PRESS_LEFT_LOCATION = "../resources/pictures/left.png";
	constexpr auto PRESS_RIGHT_LOCATION = "../resources/pictures/right.png";
	constexpr auto PRESS_LAYER_2_LOCATION = "../resources/pictures/layer_2.png";
	constexpr auto RUNNING_GIRL_LOCATION = "../resources/pictures/running_girl.png";
}

namespace 
{
	constexpr auto PRESS_KEYS_IMG_HEIGHT = 480;
	constexpr auto PRESS_KEYS_IMG_WIDTH = 640;
	constexpr auto PRESS_KEYS_IMG_NUM_FRAMES = 1;

	constexpr auto UP_IMG_HEIGHT = 480;
	constexpr auto UP_IMG_WIDTH = 640;
	constexpr auto UP_IMG_NUM_FRAMES = 1;

	constexpr auto DOWN_IMG_HEIGHT = 480;
	constexpr auto DOWN_IMG_WIDTH = 640;
	constexpr auto DOWN_IMG_NUM_FRAMES = 1;

	constexpr auto LEFT_IMG_HEIGHT = 480;
	constexpr auto LEFT_IMG_WIDTH = 640;
	constexpr auto LEFT_IMG_NUM_FRAMES = 1;

	constexpr auto RIGHT_IMG_HEIGHT = 480;
	constexpr auto RIGHT_IMG_WIDTH = 640;
	constexpr auto RIGHT_IMG_NUM_FRAMES = 1;

	constexpr auto LAYER_2_IMG_HEIGHT = 150;
	constexpr auto LAYER_2_IMG_WIDTH = 150;
	constexpr auto LAYER_2_IMG_NUM_FRAMES = 1;

	constexpr auto RUNNING_GIRL_IMG_HEIGHT = 220;
	constexpr auto RUNNING_GIRL_IMG_WIDTH = 1536;
	constexpr auto RUNNING_GIRL_IMG_NUM_FRAMES = 6;
	constexpr auto RUNNING_GIRL_IMG_FRAME_WIDTH = 256;
}

Frames ImageCfg::createFrames(const int32_t imgWidth, const int32_t imgHeight, const int32_t numFrames)
{
	Frames frames;
	for (int32_t i = 0; i < numFrames; i++)
	{
		frames.push_back(Rectangle(i * imgWidth, 0, imgWidth, imgHeight));
	}

	return frames;
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
	imagePaths[Textures::RUNNING_GIRL] = RUNNING_GIRL_LOCATION;

	return imagePaths;
}

std::unordered_map<int32_t, Frames> ImageCfg::getImageSizes()
{
	std::unordered_map<int32_t, Frames> imageSizes;
	Frames rect = createFrames(PRESS_KEYS_IMG_WIDTH, PRESS_KEYS_IMG_HEIGHT, PRESS_KEYS_IMG_NUM_FRAMES);
	imageSizes.insert(std::make_pair(Textures::PRESS_KEYS, rect));
	rect.clear();

	rect = createFrames(UP_IMG_WIDTH, UP_IMG_HEIGHT, UP_IMG_NUM_FRAMES);
	imageSizes.insert(std::make_pair(Textures::UP, rect));
	rect.clear();

	rect = createFrames(DOWN_IMG_WIDTH, DOWN_IMG_HEIGHT, DOWN_IMG_NUM_FRAMES);
	imageSizes.insert(std::make_pair(Textures::DOWN, rect));
	rect.clear();

	rect = createFrames(LEFT_IMG_WIDTH, LEFT_IMG_HEIGHT, LEFT_IMG_NUM_FRAMES);
	imageSizes.insert(std::make_pair(Textures::LEFT, rect));
	rect.clear();

	rect = createFrames(RIGHT_IMG_WIDTH, RIGHT_IMG_HEIGHT, RIGHT_IMG_NUM_FRAMES);
	imageSizes.insert(std::make_pair(Textures::RIGHT, rect));
	rect.clear();

	rect = createFrames(LAYER_2_IMG_WIDTH, LAYER_2_IMG_HEIGHT, LAYER_2_IMG_NUM_FRAMES);
	imageSizes.insert(std::make_pair(Textures::LAYER_2, rect));
	rect.clear();

	rect = createFrames(RUNNING_GIRL_IMG_FRAME_WIDTH, RUNNING_GIRL_IMG_HEIGHT, RUNNING_GIRL_IMG_NUM_FRAMES);
	imageSizes.insert(std::make_pair(Textures::RUNNING_GIRL, rect));
	rect.clear();

	return imageSizes;
}
