#ifndef IMAGE_H
#define IMAGE_H

#include "utils/drawing/DrawParams.h"
#include "utils/drawing/Rectangle.h"
#include "../common_defines/Common_Defines.h"

#include <cstdint>
#include <unordered_map>

class Image
{
public:
	int32_t create(const std::unordered_map<int32_t, Rectangle>& _textureDimensions, const Textures::ImageType& imageType);
	void draw() const;

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

	void setOpacity(const int32_t delta);

	DrawParams getDrawParams() const;

private:
	DrawParams _drawParams;
};

#endif // !IMAGE_H

