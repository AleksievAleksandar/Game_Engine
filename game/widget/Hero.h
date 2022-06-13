#ifndef HERO_H
#define HERO_H

#include "game/widget/Image.h"

class Hero
{
public:
	int32_t create(const uint8_t imageType, const Point& pos = Point::UNKNOWN, const uint8_t numFrames = 1);
	void deinit();
	bool handleEvent(InputEvent& event);
	DrawParams getDrawParams() const;
	void draw() const;
	void setPosition(const Point& position);

private:
	Image _image;
};

#endif // !HERO_H

