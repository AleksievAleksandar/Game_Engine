#include "Engine.h"

#include "../sdl_wrapper/SDL_Loader.h"
#include "../utils/thread/ThreadUtils.h"
#include "../utils/time_measurement/Time.h"

#include <cstdlib>
#include <iostream>
#include <vector>

int32_t Engine::init()
{
	this->_sdl_loader = new SDL_Loader();
	if (EXIT_SUCCESS != this->_sdl_loader->init())
	{
		std::cerr << "ERROR -> this->sdl_loader->init() failed. " << std::endl;
		return EXIT_FAILURE;
	}

	if (EXIT_SUCCESS != this->_renderer.init(this->_sdl_loader->getWindow()))
	{
		std::cerr << "ERROR -> this->_renderer.init() failed. " << std::endl;
		return EXIT_FAILURE;
	}

	if (EXIT_SUCCESS != this->_imageHandler.loadImage())
	{
		std::cerr << "ERROR -> _imageHandler.loadImage()" << std::endl;
		return EXIT_FAILURE;
	}

	if (EXIT_SUCCESS != this->_event.init())
	{
		std::cerr << "ERROR -> this->_event->init() failed. " << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

void Engine::deinit()
{
	this->_event.deinit();

	this->_imageHandler.deinit();

	this->_renderer.deinit();

	if (nullptr != this->_sdl_loader)
	{
		delete this->_sdl_loader;
		this->_sdl_loader = nullptr;
	}
}

void Engine::draw() const
{
	std::vector<SDL_Texture*> images = this->_imageHandler.imagesForDrawing();
	this->_renderer.drawTexture(images);
}

void Engine::mainLoop()
{
	Time time;
	while (true)
	{
		time.getElapsed();

		const bool shouldExit = this->handleEvent();
		if (shouldExit)
		{
			break;
		}

		this->_renderer.clearScreen();
		this->draw();
		this->_renderer.updateScreen();

		this->limitFPS(time.getElapsed().toMicroseconds());
	}
}

bool Engine::handleEvent()
{
	while (this->_event.pollEvent())
	{
		if (this->_event.touchEvent == TouchEvent::KEYBOARD_PRESS && this->_event.key == Keyboard::Key::KEY_UP)
		{
			this->_imageHandler.setCurrentImage(ImageType::UP);
		}
		else if (this->_event.touchEvent == TouchEvent::KEYBOARD_PRESS && this->_event.key == Keyboard::Key::KEY_DOWN)
		{
			this->_imageHandler.setCurrentImage(ImageType::DOWN);
		}
		else if (this->_event.touchEvent == TouchEvent::KEYBOARD_PRESS && this->_event.key == Keyboard::Key::KEY_LEFT)
		{
			this->_imageHandler.setCurrentImage(ImageType::LEFT);
		}
		else if (this->_event.touchEvent == TouchEvent::KEYBOARD_PRESS && this->_event.key == Keyboard::Key::KEY_RIGHT)
		{
			this->_imageHandler.setCurrentImage(ImageType::RIGHT);
		}
		else if (this->_event.touchEvent == TouchEvent::KEYBOARD_RELEASE)
		{
			this->_imageHandler.setCurrentImage(ImageType::PRESS_KEYS);
		}

		if (this->_event.checkForExitRequestEvent())
		{
			return true;
		}
	}

	return false;
}

void Engine::limitFPS(int64_t elapsedMicroseconds) const
{
	constexpr auto maxFrames = 60;
	constexpr auto microsecondsInASeconds = 1000000;
	constexpr auto maxMicrosecondsPerFrame = microsecondsInASeconds / maxFrames;

	const int64_t microSecondsFpsDelay = maxMicrosecondsPerFrame - elapsedMicroseconds;

	if (0 < microSecondsFpsDelay)
	{
		ThreadUtil::sleepFor(microSecondsFpsDelay);
		//std::cout << "Sleep time = " << microSecondsFpsDelay << std::endl;
	}
}

void Engine::start()
{
	this->mainLoop();
}
