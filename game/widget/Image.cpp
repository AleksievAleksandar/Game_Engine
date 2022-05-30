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

	std::cout << "create Img:\n";
	std::cout << "x = " << _drawParams.frame.x << " y = " << _drawParams.frame.y << std::endl;
	std::cout << "w = " << _drawParams.frame.w << " h = " << _drawParams.frame.h << std::endl;
	std::cout << "drawParams w = " << _drawParams.w << " drawParams h = " << _drawParams.h << std::endl;

	for (int32_t i = 0; i < numFrames; i++)
	{
		std::cout << "x = " << it->second[i].x << " y = " << it->second[i].y << std::endl;
		//std::cout << "w = " << it->second[i].w << " h = " << it->second[i].h << std::endl;
	}


	//std::cout << "x = " << it->second[0].x << " y = " << it->second[0].y << std::endl;
	//std::cout << "x = " << it->second[1].x << " y = " << it->second[1].y << std::endl;
	//std::cout << "x = " << it->second[2].x << " y = " << it->second[2].y << std::endl;
	//std::cout << "x = " << it->second[3].x << " y = " << it->second[3].y << std::endl;
	//std::cout << "x = " << it->second[4].x << " y = " << it->second[4].y << std::endl;
	//std::cout << "x = " << it->second[5].x << " y = " << it->second[5].y << std::endl;

	//if (1 < numFrames)
	//{
	//	_drawParams.frame.h = it->second[0].h;
	//	_drawParams.frame.w = it->second[0].w;

	//	_drawParams.frame.x = it->second[0].x;
	//	_drawParams.frame.y = it->second[0].y;


	//}
	this->_drawParams._hasFrames = true;
	this->_drawParams.numFrames = numFrames;

	return EXIT_SUCCESS;
}
