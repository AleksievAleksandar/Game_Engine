#include "game/widget/Widget.h"

#include <iostream>

void Widget::moveUp()
{
	this->_drawParams.pos.y--;
}

void Widget::moveDown()
{
	this->_drawParams.pos.y++;
}

void Widget::moveLeft()
{
	this->_drawParams.pos.x--;
}

void Widget::moveRight()
{
	this->_drawParams.pos.x++;
}

void Widget::setNextFrame()
{
	if (!this->_drawParams._hasFrames)
	{
		std::cerr << "Trying to set next frame to image that has only one frame" << std::endl;
		return;
	}
	this->_drawParams.frame.x = 256;
}

void Widget::setOpacity(const int32_t delta)
{
	this->_drawParams.opacity += delta;
}

DrawParams Widget::getDrawParams() const
{
	return this->_drawParams;
}
