#ifndef IMAGE_PATH_CFG_H
#define IMAGE_PATH_CFG_H

#include <string>
#include <vector>
#include <unordered_map>

#include "utils/drawing/Rectangle.h"

using Frames = std::vector<Rectangle>;

class ImageCfg
{
public:
	static std::vector<std::string> getImagePaths();
	static std::unordered_map<int32_t, Frames> getImageSizes();
};

#endif // !IMAGE_PATH_CFG_H

