#ifndef DRAW_PARAMS_H
#define DRAW_PARAMS_H

#include "utils/drawing/Point.h"
#include "utils/drawing/Rectangle.h"

inline constexpr auto UNKNOWN_RSRC_ID = -1;
inline constexpr auto FULL_OPACITY = 255;
inline constexpr auto ZERO_OPACITY = 0;
inline constexpr auto UNKNOWN_NUM_FRAMES = -1;

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

//const double angle,
//const SDL_Point* center,
//const SDL_RendererFlip flip

enum class FlipMode : uint8_t
{
	FLIP_NONE                = 0, /**< Do not flip */
	FLIP_HORIZONTAL          = 1, /**< flip horizontally */
	FLIP_VERTICAL            = 2, /**< flip vertically */
	FLIP_VERTICAL_HORIZONTAL = 3  /**< flip vertically and horizontally */
};

struct DrawParams
{
	Point pos = Point::UNKNOWN;

	Point rotationCenter = Point::UNKNOWN;
	double rotationAngle = 0.0;

	int32_t w = 0;
	int32_t h = 0;

	Rectangle frame 	= Rectangle::ZERO;
	int32_t numFrames 	= UNKNOWN_NUM_FRAMES;
	int32_t currFrame 	= 0;

	int32_t opacity 		= FULL_OPACITY;

	int32_t rsrcId 			= UNKNOWN_RSRC_ID;
	WidgetType widgetType 	= WidgetType::UNKNOWN;

	FlipMode flipMode = FlipMode::FLIP_NONE;
};

#endif // !DRAW_PARAMS_H

