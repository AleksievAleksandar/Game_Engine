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

	void setOpacity(const int32_t delta);

	DrawParams getDrawParams() const;

protected:
	DrawParams _drawParams;
};

#endif // !I_WIDGET_H

