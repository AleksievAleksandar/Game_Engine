#ifndef RECTANGLE_H
#define RECTANGLE_H

//#include "utils/drawing/DrawParams.h"

#include <cstdint>
#include <sstream>

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
	//Rectangle& operator=(const DrawParams& drawParams);

	bool operator==(const Rectangle& other);
	bool operator!=(const Rectangle& other);
	friend std::ostream& operator<<(std::ostream& out, const Rectangle& rect);

	static const Rectangle UNKNOWN;
	static const Rectangle ZERO;
};

std::ostream& operator<<(std::ostream& out, const Rectangle& rect);

#endif // !RECTANGLE_H

