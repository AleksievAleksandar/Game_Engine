#include "ImageCfg.h"

namespace
{
	constexpr auto PRESS_KEYS_IMG_HEIGHT = 640;
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
};

std::vector<std::string> ImageCfg::getImageParhs()
{
	//Load image from disk
	std::vector<std::string> imagePaths(ImageType::COUNT);

	imagePaths[PRESS_KEYS] = "../resources/press_keys.png";
	imagePaths[UP] = "../resources/up.png";
	imagePaths[DOWN] = "../resources/down.png";
	imagePaths[LEFT] = "../resources/left.png";
	imagePaths[RIGHT] = "../resources/right.png";
	imagePaths[LAYER_2] = "../resources/layer_2.png";

	return imagePaths;
}

std::unordered_map<int32_t, Rectangle> ImageCfg::getImageSizes()
{
	std::unordered_map<int32_t, Rectangle> imageSizes;
	Rectangle rect(0, 0, PRESS_KEYS_IMG_WIDTH, PRESS_KEYS_IMG_HEIGHT);
	imageSizes.insert(std::make_pair(PRESS_KEYS, rect));

	rect.x = 0;
	rect.y = 0;
	rect.w = UP_IMG_WIDTH;
	rect.h = UP_IMG_HEIGHT;
	imageSizes.insert(std::make_pair(UP, rect));

	rect.x = 0;
	rect.y = 0;
	rect.w = DOWN_IMG_WIDTH;
	rect.h = DOWN_IMG_HEIGHT;
	imageSizes.insert(std::make_pair(DOWN, rect));

	rect.x = 0;
	rect.y = 0;
	rect.w = LEFT_IMG_WIDTH;
	rect.h = LEFT_IMG_HEIGHT;
	imageSizes.insert(std::make_pair(LEFT, rect));

	rect.x = 0;
	rect.y = 0;
	rect.w = RIGHT_IMG_WIDTH;
	rect.h = RIGHT_IMG_HEIGHT;
	imageSizes.insert(std::make_pair(RIGHT, rect));

	rect.x = 0;
	rect.y = 0;
	rect.w = LAYER_2_IMG_WIDTH;
	rect.h = LAYER_2_IMG_HEIGHT;
	imageSizes.insert(std::make_pair(LAYER_2, rect));

	return imageSizes;
}
