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

	namespace Location
	{
		constexpr auto PRESS_KEYS_LOCATION = "../resources/pictures/press_keys.png";
		constexpr auto PRESS_UP_LOCATION = "../resources/pictures/up.png";
		constexpr auto PRESS_DOWN_LOCATION = "../resources/pictures/down.png";
		constexpr auto PRESS_LEFT_LOCATION = "../resources/pictures/left.png";
		constexpr auto PRESS_RIGHT_LOCATION = "../resources/pictures/right.png";
		constexpr auto PRESS_LAYER_2_LOCATION = "../resources/pictures/layer_2.png";
	}

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

	namespace Location
	{
		constexpr auto YAGORA_FONT_LOCATION = "../resources/fonts/Yagora.ttf";
		constexpr auto ANGELINE_VINTAGE_FONT_LOCATION = "../resources/fonts/AngelineVintage.ttf";
	}

	namespace Size
	{
		constexpr auto YAGORA_FONT_SIZE_36 = 36;
		constexpr auto ANGELIN_VINTAGE_FONT_SIZE_36 = 36;
	}
}

#endif // !COMMON_DEFINES_H

