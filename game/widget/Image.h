#ifndef IMAGE_H
#define IMAGE_H

#include "game/widget/Widget.h"

#include <cstdint>

class Image : public Widget
{
public:
	int32_t create(const uint8_t imageType, const Point& pos = Point::UNKNOWN, const uint8_t numFrames = 1);
};

#endif // !IMAGE_H

