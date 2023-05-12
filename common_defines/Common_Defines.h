#ifndef COMMON_DEFINES_H
#define COMMON_DEFINES_H

namespace Textures
{
	enum ImageType
	{
		PRESS_KEYS,
		UP,
		DOWN,
		LEFT,
		RIGHT,
		LAYER_2,
		RUNNING_GIRL,

		COUNT
	};

	namespace ImageFrames
	{
		constexpr auto PRESS_KEYS_FRAMES 	= 1;
		constexpr auto UP_FRAMES 			= 1;
		constexpr auto DOWN_FRAMES 			= 1;
		constexpr auto LEFT_FRAMES 			= 1;
		constexpr auto RIGHT_FRAMES 		= 1;
		constexpr auto LAYER_2_FRAMES 		= 1;
		constexpr auto RUNNING_GIRL_FRAMES 	= 6;
	}
}

namespace Fonts
{
	enum FontType
	{
		YAGORA_FONT,
		ANGELINE_VINTAGE_FONT,

		COUNT
	};
}

#endif // !COMMON_DEFINES_H

