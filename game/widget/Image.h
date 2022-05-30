#ifndef IMAGE_H
#define IMAGE_H

#include "game/widget/Widget.h"
#include "utils/drawing/Rectangle.h"

#include <cstdint>
#include <vector>
#include <unordered_map>

using Frames = std::vector<Rectangle>;

class Image : public Widget
{
public:
	int32_t create(const std::unordered_map<int32_t, Frames>& _textureDimensions, const uint8_t imageType, const uint8_t numFrames = 1);
};

#endif // !IMAGE_H

