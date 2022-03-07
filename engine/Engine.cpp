#include "Engine.h"

#include "utils/thread/ThreadUtils.h"
#include "utils/time_measurement/Time.h"

#include <cstdlib>
#include <iostream>
#include <vector>

// TODO remove me
#include "utils/drawing/Color.h"
#include "../common_defines/Common_Defines.h"

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

	if (EXIT_SUCCESS != this->_imageHandler.loadRsrc())
	{
		std::cerr << "ERROR -> _imageHandler.loadRsrc()" << std::endl;
		return EXIT_FAILURE;
	}

	if (EXIT_SUCCESS != this->_textHandler.loadRsrc())
	{
		std::cerr << "ERROR -> _textHandler.loadRsrc()" << std::endl;
		return EXIT_FAILURE;
	}

	if (EXIT_SUCCESS != this->_event.init())
	{
		std::cerr << "ERROR -> this->_event->init() failed. " << std::endl;
		return EXIT_FAILURE;
	}

	if (EXIT_SUCCESS != this->_game.init(this->_imageHandler.getTexturesDimensions()))
	{
		std::cerr << "ERROR -> this->_game->init() failed. " << std::endl;
		return EXIT_FAILURE;
	}

	//TODO remove me
	this->_textHandler.createText(Fonts::YAGORA_FONT, "Hello World!", Colors::GREEN, this->_game._text.w, this->_game._text.h);

	return EXIT_SUCCESS;
}

void Engine::deinit()
{
	this->_game.deinit();

	this->_event.deinit();

	this->_textHandler.deinit();

	this->_imageHandler.deinit();

	this->_renderer.deinit();

	this->_window.deinit();
}

void Engine::draw() const
{
	std::vector<DrawParams> drawParams = this->_game.imagesForDrawing();

	std::vector<SDL_Texture*> textures;
	this->_imageHandler.collectTexturesForDrawing(textures, drawParams);
	this->_textHandler.collectTexturesForDrawing(textures, drawParams);

	for (size_t i = 0; i < textures.size(); i++)
	{
		this->_renderer.drawTexture(textures[i], drawParams[i]);
	}
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
	return this->_game.handleEvent(this->_event);
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
