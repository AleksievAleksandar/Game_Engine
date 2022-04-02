#ifndef I_WIDGET_H
#define I_WIDGET_H

#include "utils/drawing/DrawParams.h"

class Widget
{
public:
	virtual ~Widget() = default;
	virtual void draw() const = 0;

	virtual void moveUp();
	virtual void moveDown();
	virtual void moveLeft();
	virtual void moveRight();

	virtual void setOpacity(const int32_t delta);

	virtual DrawParams getDrawParams() const;

protected:
	DrawParams _drawParams;
};

#endif // !I_WIDGET_H

