#include "Engine.h"

#include "../sdl_wrapper/SDL_Loader.h"
#include "../utils/thread/ThreadUtils.h"
#include "../utils/time_measurement/Time.h"

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
	Time time;
	while (true)
	{
		time.getElapsed();

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

		this->limitFPS(time.getElapsed().toMicroseconds());

	}
}

bool Engine::handleEvent()
{
	while (this->event.pollEvent())
	{
		if (this->event.touchEvent == TouchEvent::KEYBOARD_PRESS && this->event.key == Keyboard::Key::KEY_UP)
		{
			this->sdl_loader->imageHandler._currentImage = this->sdl_loader->imageHandler._images[ImageType::UP];
		}
		else if (this->event.touchEvent == TouchEvent::KEYBOARD_PRESS && this->event.key == Keyboard::Key::KEY_DOWN)
		{
			this->sdl_loader->imageHandler._currentImage = this->sdl_loader->imageHandler._images[ImageType::DOWN];
		}
		else if (this->event.touchEvent == TouchEvent::KEYBOARD_PRESS && this->event.key == Keyboard::Key::KEY_LEFT)
		{
			this->sdl_loader->imageHandler._currentImage = this->sdl_loader->imageHandler._images[ImageType::LEFT];
		}
		else if (this->event.touchEvent == TouchEvent::KEYBOARD_PRESS && this->event.key == Keyboard::Key::KEY_RIGHT)
		{
			this->sdl_loader->imageHandler._currentImage = this->sdl_loader->imageHandler._images[ImageType::RIGHT];
		}
		else if (this->event.touchEvent == TouchEvent::KEYBOARD_RELEASE)
		{
			this->sdl_loader->imageHandler._currentImage = this->sdl_loader->imageHandler._images[ImageType::PRESS_KEYS];
		}

		if (this->event.checkForExitRequestEvent())
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
