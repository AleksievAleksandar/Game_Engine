#ifndef I_WIDGET_H
#define I_WIDGET_H

#include "utils/drawing/DrawParams.h"

class Widget
{
public:
	virtual ~Widget() = default;
	virtual void draw() const = 0;

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

	void setOpacity(const int32_t delta);

	virtual DrawParams getDrawParams() const;

protected:
	DrawParams _drawParams;
};

#endif // !I_WIDGET_H

