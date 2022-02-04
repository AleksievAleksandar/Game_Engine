#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <cstdint>

class Rectangle
{
public:
	int32_t x = 0;
	int32_t y = 0;
	int32_t w = 0;
	int32_t h = 0;

	Rectangle(int32_t inputX, int32_t inputY, int32_t inputW, int32_t inputH);
	Rectangle(const Rectangle& other);

	Rectangle& operator=(const Rectangle& other);

	bool operator==(const Rectangle& other);
	bool operator!=(const Rectangle& other);

	static const Rectangle UNKNOWN;
	static const Rectangle ZERO;
};

#endif // !RECTANGLE_H

