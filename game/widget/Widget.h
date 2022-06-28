#ifndef I_WIDGET_H
#define I_WIDGET_H

#include "utils/drawing/DrawParams.h"

class Widget
{
public:
	virtual ~Widget() = default;

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

	void setNextFrame();
	void setPrevFrame();

	void setOpacity(const int32_t delta);
	void setPosition(const Point& position);

	void setFlipMode(const FlipMode& flipMode);

	void setWidth(int32_t delta);
	void setHeight(int32_t delta);

	void rotateLeft(const double delta);
	void rotateRight(const double delta);
	void setRotationCenter(const Point& newRotCenter);

	DrawParams getDrawParams() const;
	void draw() const;

protected:
	DrawParams _drawParams;
};

#endif // !I_WIDGET_H

