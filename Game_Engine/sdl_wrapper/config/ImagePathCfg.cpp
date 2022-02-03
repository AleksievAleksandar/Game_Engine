#include "ImagePathCfg.h"

std::vector<std::string> ImagePathCfg::getImageParhs()
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
