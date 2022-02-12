#ifndef DRAW_PARAMS_H
#define DRAW_PARAMS_H

#include "Point.h"

inline constexpr auto UNKNOWN_RSRC_ID = -1;

struct DrawParams
{
	Point pos = Point::UNKNOWN;

	int32_t w = 0;
	int32_t h = 0;

	int32_t rsrcId = UNKNOWN_RSRC_ID;
};

#endif // !DRAW_PARAMS_H

