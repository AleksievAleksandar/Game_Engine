#include "Image.h"

#include "../common_defines/Common_Defines.h"

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

void Image::moveUp()
{
	this->_drawParams.pos.y--;
}

void Image::moveDown()
{
	this->_drawParams.pos.y++;
}

void Image::moveLeft()
{
	this->_drawParams.pos.x--;
}

void Image::moveRight()
{
	this->_drawParams.pos.x++;
}

void Image::setOpacity(const int32_t delta)
{
	this->_drawParams.opacity += delta;
}

DrawParams Image::getDrawParams() const
{
	return this->_drawParams;
}
