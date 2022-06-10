#include "game/widget/Image.h"

#include "sdl_wrapper/Input_Events.h"

#include <iostream>

int32_t Image::create(const std::unordered_map<int32_t, Frames>& _textureDimensions, const uint8_t imageType, const Point& pos, const uint8_t numFrames)
{
	auto it = _textureDimensions.find(imageType);
	if (it == _textureDimensions.end())
	{
		std::cerr << "ERROR -> Can not find Texture ID: " << imageType << " to init() Game." << std::endl;
		return EXIT_FAILURE;
	}

	_drawParams.widgetType = WidgetType::IMAGE;
	_drawParams.rsrcId = it->first;

	_drawParams.h = it->second[0].h;
	_drawParams.w = it->second[0].w;
	_drawParams.pos = pos;

	_drawParams.frame = it->second[0];

	this->_drawParams.numFrames = numFrames;

	return EXIT_SUCCESS;
}

void Image::draw() const
{
	Widget::draw();
}
