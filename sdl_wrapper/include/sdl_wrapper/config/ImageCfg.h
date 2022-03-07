#ifndef IMAGE_PATH_CFG_H
#define IMAGE_PATH_CFG_H

#include <string>
#include <vector>
#include <unordered_map>

#include "utils/drawing/Rectangle.h"



class ImageCfg
{
public:
	static std::vector<std::string> getImageParhs();
	static std::unordered_map<int32_t, Rectangle> getImageSizes();
};

#endif // !IMAGE_PATH_CFG_H

