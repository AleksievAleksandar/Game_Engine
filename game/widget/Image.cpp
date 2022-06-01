#include "game/widget/Image.h"

#include <iostream>

int32_t Image::create(const std::unordered_map<int32_t, Frames>& _textureDimensions, const uint8_t imageType, const uint8_t numFrames)
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
	_drawParams.pos = Point::ZERO;

	_drawParams.frame = it->second[0];

	if (1 < numFrames)
	{
		this->_drawParams._hasFrames = true;
		this->_drawParams.numFrames = numFrames;
	}

	return EXIT_SUCCESS;
}
