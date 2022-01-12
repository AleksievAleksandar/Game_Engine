#include "Point.h"

const Point Point::UNKNOWN(100000, 100000);
const Point Point::ZERO(0, 0);

Point::Point(int32_t inputX, int32_t inputY):
	x(inputX), y(inputY)
{}

bool Point::operator==(const Point & other) const
{
	return (this->x == other.x && this->y == other.y);
}

bool Point::operator!=(const Point& other) const
{
	return !this->operator==(other);
}
