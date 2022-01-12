#include "Engine.h"

#include "../sdl_wrapper/SDL_Loader.h"

#include <cstdlib>
#include <iostream>

int32_t Engine::init()
{
	this->sdl_loader = new SDL_Loader();
	if (EXIT_SUCCESS != this->sdl_loader->init())
	{
		std::cerr << "ERROR -> this->sdl_loader->init() failed. " << std::endl;
		return EXIT_FAILURE;
	}

	if (EXIT_SUCCESS != this->event.init())
	{
		std::cerr << "ERROR -> this->event->init() failed. " << std::endl;
		return EXIT_FAILURE;
	}
	
	return EXIT_SUCCESS;
}

void Engine::deinit()
{
	this->event.deinit();

	if (nullptr != this->sdl_loader)
	{
		delete this->sdl_loader;
		this->sdl_loader = nullptr;
	}
}

int32_t Engine::draw() const
{
	return this->sdl_loader->draw();
}

void Engine::mainLoop()
{
	while (true)
	{
		const bool shouldExit = this->handleEvent();
		if (shouldExit)
		{
			break;
		}

		if (EXIT_SUCCESS != this->draw())
		{
			std::cerr << "ERROR -> Engine::draw() failed." << std::endl;
			break;
		}
	}
}

bool Engine::handleEvent()
{
	while (this->event.pollEvent())
	{
		if (this->event.touchEvent == TouchEvent::KEYBOARD_PRESS)
		{
			std::cout << "Keyboard press: " << (char)this->event.key << std::endl;
		}
		else if (this->event.touchEvent == TouchEvent::KEYBOARD_RELEASE)
		{
			std::cout << "Keyboard release: " << (char)this->event.key << std::endl;
		}
		else if (this->event.touchEvent == TouchEvent::MOUSE_PRESS)
		{
			std::cout << "Keyboard release: " << (char)this->event.mouseButton << std::endl;
		}
		else if (this->event.touchEvent == TouchEvent::MOUSE_RELEASE)
		{
			std::cout << "Keyboard release: " << (char)this->event.mouseButton << std::endl;
		}

		if (this->event.checkForExitRequestEvent())
		{
			return true;
		}
	}

	return false;
}

void Engine::start()
{
	this->mainLoop();
}
