#include "game/widget/Image.h"

#include <iostream>

int32_t Image::create(const std::unordered_map<int32_t, Rectangle>& _textureDimensions, const Textures::ImageType& imageType)
{
	auto it = _textureDimensions.find(imageType);
	if (it == _textureDimensions.end())
	{
		std::cerr << "ERROR -> Can not find Texture ID: " << imageType << " to init() Game." << std::endl;
		return EXIT_FAILURE;
	}
	_drawParams.widgetType = WidgetType::IMAGE;
	_drawParams.rsrcId = it->first;
	_drawParams.h = it->second.h;
	_drawParams.w = it->second.w;
	_drawParams.pos = Point::ZERO;

	return EXIT_SUCCESS;
}

void Image::draw() const
{
	//TODO
}
