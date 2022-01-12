#ifndef POINT_H
#define POINT_H

#include <cstdint>

struct Point
{
	Point(int32_t inputX, int32_t inputY);

	int32_t x = 0;
	int32_t y = 0;

	bool operator==(const Point& other) const;
	bool operator!=(const Point& other) const;

	static const Point UNKNOWN;
	static const Point ZERO;
};

#endif // !POINT_H

