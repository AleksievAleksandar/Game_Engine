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

		COUNT
	};

	namespace ImageSize
	{
		constexpr auto PRESS_KEYS_IMG_HEIGHT = 480;
		constexpr auto PRESS_KEYS_IMG_WIDTH = 640;

		constexpr auto UP_IMG_HEIGHT = 640;
		constexpr auto UP_IMG_WIDTH = 640;

		constexpr auto DOWN_IMG_HEIGHT = 640;
		constexpr auto DOWN_IMG_WIDTH = 640;

		constexpr auto LEFT_IMG_HEIGHT = 640;
		constexpr auto LEFT_IMG_WIDTH = 640;

		constexpr auto RIGHT_IMG_HEIGHT = 640;
		constexpr auto RIGHT_IMG_WIDTH = 640;

		constexpr auto LAYER_2_IMG_HEIGHT = 150;
		constexpr auto LAYER_2_IMG_WIDTH = 150;
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

	namespace Size
	{
		int32_t YAGORA_FONT_SIZE_36 = 36;
		int32_t ANGELIN_VINTAGE_FONT_SIZE_36 = 36;
	}
}

#endif // !COMMON_DEFINES_H

