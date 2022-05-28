#ifndef IMAGE_H
#define IMAGE_H

#include "game/widget/Widget.h"
#include "utils/drawing/Rectangle.h"
#include "../../common_defines/Common_Defines.h"

#include <cstdint>
#include <unordered_map>

class Image : public Widget
{
public:
	int32_t create(const std::unordered_map<int32_t, Rectangle>& _textureDimensions, const Textures::ImageType& imageType, const int32_t numFrames = 1);
};

#endif // !IMAGE_H

