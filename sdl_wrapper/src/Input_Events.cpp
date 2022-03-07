#include "sdl_wrapper/Input_Events.h"

#include <iostream>
#include <SDL_events.h>

int32_t InputEvent::init()
{
	this->_sdlEvent = new SDL_Event();
	if (nullptr == this->_sdlEvent)
	{
		std::cerr << "ERROR -> bad memory alloc for this->_sdlEvent" << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

void InputEvent::deinit()
{
	if (nullptr != this->_sdlEvent)
	{
		delete this->_sdlEvent;
		this->_sdlEvent = nullptr;
	}
}

bool InputEvent::pollEvent() 
{
	if (!SDL_PollEvent(this->_sdlEvent)) //No Event
	{
		return false;
	}

	this->processEvent();

	return true;
}

bool InputEvent::checkForExitRequestEvent() const
{
	return (EventType::EventDataTypes::QUIT == this->_sdlEvent->quit.type) || 
		(Keyboard::Key::KEY_ESCAPE == this->key && TouchEvent::KEYBOARD_PRESS == this->touchEvent);
}

void InputEvent::processEvent()
{
	SDL_GetMouseState(&this->mousePos.x, &this->mousePos.y);
	
	switch (this->_sdlEvent->type)
	{
	case EventType::EventDataTypes::KEYBOARD_PRESS:
		this->key = this->_sdlEvent->key.keysym.sym;
		this->mouseButton = Mouse::MouseKey::UNKNOWN;
		this->touchEvent = TouchEvent::KEYBOARD_PRESS;
		break;

	case EventType::EventDataTypes::KEYBOARD_RELEASE:
		this->key = this->_sdlEvent->key.keysym.sym;
		this->mouseButton = Mouse::MouseKey::UNKNOWN;
		this->touchEvent = TouchEvent::KEYBOARD_RELEASE;
		break;

	case EventType::EventDataTypes::MOUSE_PRESS:
		this->key = Keyboard::Key::KEY_UNKNOWN;
		this->mouseButton = this->_sdlEvent->button.button;
		this->touchEvent = TouchEvent::MOUSE_PRESS;
		break;

	case EventType::EventDataTypes::MOUSE_RELEASE:
		this->key = Keyboard::Key::KEY_UNKNOWN;
		this->mouseButton = this->_sdlEvent->button.button;
		this->touchEvent = TouchEvent::MOUSE_RELEASE;
		break;

	case EventType::EventDataTypes::QUIT:
		this->key = this->_sdlEvent->key.keysym.sym;
		this->touchEvent = TouchEvent::KEYBOARD_PRESS;
		break;

	default:
		this->key = Keyboard::Key::KEY_UNKNOWN;
		this->mouseButton = Mouse::MouseKey::UNKNOWN;
		this->touchEvent = TouchEvent::UNKNOWN;
		break;
	}
}
