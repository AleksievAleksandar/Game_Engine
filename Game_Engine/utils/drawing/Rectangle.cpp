#include "Rectangle.h"

const Rectangle Rectangle::UNKNOWN(100000, 100000, 100000, 100000);
const Rectangle Rectangle::ZERO(0, 0, 0, 0);

Rectangle::Rectangle(int32_t inputX, int32_t inputY, int32_t inputW, int32_t inputH):
	x(inputX), y(inputY), w(inputW), h(inputH)
{}

Rectangle::Rectangle(const Rectangle& other):
	x(other.h), y(other.y), w(other.w), h(other.h)
{}

Rectangle& Rectangle::operator=(const Rectangle& other)
{
	this->x = other.x;
	this->y = other.y;
	this->w = other.w;
	this->h = other.h;

	return *this;
}

bool Rectangle::operator==(const Rectangle& other)
{
	return this->x == other.x && 
		this->y == other.y &&
		this->w == other.w && 
		this->h == other.h;
}

bool Rectangle::operator!=(const Rectangle& other)
{
	return !this->operator==(other);
}
