#include "Hero.h"

#include "sdl_wrapper/Input_Events.h"

#include <iostream>

int32_t Hero::create(const std::unordered_map<int32_t, Frames>& _textureDimensions, const uint8_t imageType, const uint8_t numFrames)
{
	if (EXIT_SUCCESS != this->_image.create(_textureDimensions, imageType, numFrames))
	{
		std::cerr << "ERROR -> Failed to create image with ID: " << imageType << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

void Hero::deinit()
{
	//empty
}

bool Hero::handleEvent(InputEvent& event)
{
	if (TouchEvent::KEYBOARD_PRESS != event.touchEvent)
	{
		return false;
	}

	switch (event.key)
	{
	case Keyboard::Key::KEY_RIGHT:
		this->_image.moveRight();
		this->_image.setNextFrame();
		break;

	case Keyboard::Key::KEY_LEFT:
		this->_image.moveLeft();
		this->_image.setPrevFrame();
		break;

	case Keyboard::Key::KEY_UP:
		this->_image.moveUp();
		this->_image.setPrevFrame();
		break;

	case Keyboard::Key::KEY_DOWN:
		this->_image.moveDown();
		this->_image.setNextFrame();
		break;

	default:
		break;
	}

	return false;
}

DrawParams Hero::getDrawParams() const
{
	return this->_image.getDrawParams();
}

void Hero::draw() const
{
	this->_image.draw();
}
