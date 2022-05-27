#include "utils/drawing/Rectangle.h"

const Rectangle Rectangle::UNKNOWN(100000, 100000, 100000, 100000);
const Rectangle Rectangle::ZERO(0, 0, 0, 0);

Rectangle::Rectangle(int32_t inputX, int32_t inputY, int32_t inputW, int32_t inputH):
	x(inputX), y(inputY), w(inputW), h(inputH)
{}

Rectangle::Rectangle(const Rectangle& other):
	x(other.x), y(other.y), w(other.w), h(other.h)
{}

Rectangle& Rectangle::operator=(const Rectangle& other)
{
	this->x = other.x;
	this->y = other.y;
	this->w = other.w;
	this->h = other.h;

	return *this;
}

//Rectangle& Rectangle::operator=(const DrawParams& drawParams)
//{
//	this->x = drawParams.pos.x;
//	this->y = drawParams.pos.y;
//	this->h = drawParams.h;
//	this->w = drawParams.w;
//
//	return *this;
//}

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

std::ostream& operator<<(std::ostream& out, const Rectangle& rect)
{
	out << "X = " << rect.x << "; Y = " << rect.y << "; W = " << rect.w << "; H = " << rect.h << ";";

	return out;
}
