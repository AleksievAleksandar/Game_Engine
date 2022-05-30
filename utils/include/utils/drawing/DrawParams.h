#ifndef DRAW_PARAMS_H
#define DRAW_PARAMS_H

#include "utils/drawing/Point.h"
#include "utils/drawing/Rectangle.h"

inline constexpr auto UNKNOWN_RSRC_ID = -1;
inline constexpr auto FULL_OPACITY = 255;
inline constexpr auto ZERO_OPACITY = 0;
inline constexpr auto ONE_FRAME = 1;

enum class BlendMode : uint8_t
{
	NONE = 0, //value for SDL_BLENDMODE_NONE
	BLEND = 1, //value for SDL_BLENDMODE_BLEND
	ADD = 2, //value for SDL_BLENDMODE_ADD
	MOD = 4  //value for SDL_BLENDMODE_MODE
};

enum class WidgetType : uint8_t 
{
	IMAGE,
	TEXT,
	UNKNOWN
};

struct DrawParams
{
	bool _hasFrames = false;

	Point pos = Point::UNKNOWN;

	int32_t w = 0;
	int32_t h = 0;

	Rectangle frame = Rectangle::ZERO;
	uint8_t numFrames = ONE_FRAME;

	uint8_t currFrame = 0;

	int32_t opacity = FULL_OPACITY;

	int32_t rsrcId = UNKNOWN_RSRC_ID;
	WidgetType widgetType = WidgetType::UNKNOWN;
};

#endif // !DRAW_PARAMS_H

