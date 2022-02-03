#ifndef IMAGE_PATH_CFG_H
#define IMAGE_PATH_CFG_H

#include <string>
#include <vector>

enum ImageType
{
	PRESS_KEYS,
	UP,
	DOWN,
	LEFT,
	RIGHT,
	LAYER_2,

	COUNT
};

class ImagePathCfg
{
public:
	static std::vector<std::string> getImageParhs();
};

#endif // !IMAGE_PATH_CFG_H

