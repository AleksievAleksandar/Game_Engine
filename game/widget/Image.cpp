#include "game/widget/Image.h"

#include "sdl_wrapper/Input_Events.h"

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
		this->_drawParams.numFrames = numFrames;
	}

	return EXIT_SUCCESS;
}

bool Image::handleEvent(InputEvent& event)
{
	if (TouchEvent::KEYBOARD_RELEASE != event.touchEvent)
	{
		return false;
	}

	switch (event.key)
	{
	case Keyboard::Key::KEY_RIGHT:
		this->moveRight();
		this->setNextFrame();
		break;

	case Keyboard::Key::KEY_LEFT:
		this->moveLeft();
		this->setPrevFrame();
		break;

	case Keyboard::Key::KEY_UP:
		this->moveUp();
		this->setPrevFrame();
		break;

	case Keyboard::Key::KEY_DOWN:
		this->moveDown();
		this->setNextFrame();
		break;

	default:
		break;
	}

	return false;
}
