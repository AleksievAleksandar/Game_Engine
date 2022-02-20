#include "Engine.h"

#include "../utils/thread/ThreadUtils.h"
#include "../utils/time_measurement/Time.h"

#include <cstdlib>
#include <iostream>
#include <vector>

int32_t Engine::init()
{
	if (EXIT_SUCCESS != this->_window.init())
	{
		std::cerr << "ERROR -> this->_window->init() failed. " << std::endl;
		return EXIT_FAILURE;
	}
	
	if (EXIT_SUCCESS != this->_renderer.init(this->_window.getWindow()))
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

	if (EXIT_SUCCESS != this->_game.init(this->_imageHandler.getImagesDimensions()))
	{
		std::cerr << "ERROR -> this->_game->init() failed. " << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

void Engine::deinit()
{
	this->_game.deinit();

	this->_event.deinit();

	this->_imageHandler.deinit();

	this->_renderer.deinit();

	this->_window.deinit();
}

void Engine::draw() const
{
	std::vector<int32_t> drawParamsIDs = this->_game.imagesForDrawing();
	std::vector<std::pair<SDL_Texture*, Rectangle> > images = this->_imageHandler.imagesForDrawing(drawParamsIDs);
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
			this->_imageHandler.setCurrentImage(Textures::UP);
		}
		else if (this->_event.touchEvent == TouchEvent::KEYBOARD_PRESS && this->_event.key == Keyboard::Key::KEY_DOWN)
		{
			this->_imageHandler.setCurrentImage(Textures::DOWN);
		}
		else if (this->_event.touchEvent == TouchEvent::KEYBOARD_PRESS && this->_event.key == Keyboard::Key::KEY_LEFT)
		{
			this->_imageHandler.setCurrentImage(Textures::LEFT);
		}
		else if (this->_event.touchEvent == TouchEvent::KEYBOARD_PRESS && this->_event.key == Keyboard::Key::KEY_RIGHT)
		{
			this->_imageHandler.setCurrentImage(Textures::RIGHT);
		}
		else if (this->_event.touchEvent == TouchEvent::KEYBOARD_RELEASE)
		{
			this->_imageHandler.setCurrentImage(Textures::PRESS_KEYS);
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
