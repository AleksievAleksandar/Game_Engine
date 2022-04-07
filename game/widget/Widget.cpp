#include "game/widget/Widget.h"

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

void Widget::setOpacity(const int32_t delta)
{
	this->_drawParams.opacity += delta;
}

DrawParams Widget::getDrawParams() const
{
	return this->_drawParams;
}
