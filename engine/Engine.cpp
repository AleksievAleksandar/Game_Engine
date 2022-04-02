#include "Engine.h"

#include "utils/thread/ThreadUtils.h"
#include "utils/time_measurement/Time.h"
#include "manager_utils/DrawMgr.h"
#include "manager_utils/RsrcMgr.h"

#include <cstdlib>
#include <iostream>
#include <vector>


int32_t Engine::init()
{
	gDrawMgr = new DrawMgr();
	if (nullptr == gDrawMgr)
	{
		std::cerr << "ERROR -> Failed for memory alloc for gDrawMgr. " << std::endl;
		return EXIT_FAILURE;
	}
	gDrawMgr->init();

	gRsrcMgr = new RsrcMgr();
	if (nullptr == gRsrcMgr)
	{
		std::cerr << "ERROR -> Failed for memory alloc for gRsrcMgr. " << std::endl;
		return EXIT_FAILURE;
	}
	gRsrcMgr->init();

	if (EXIT_SUCCESS != this->_event.init())
	{
		std::cerr << "ERROR -> this->_event->init() failed. " << std::endl;
		return EXIT_FAILURE;
	}
	
	if (EXIT_SUCCESS != this->_game.init(gRsrcMgr->getImageDimensions()))
	{
		std::cerr << "ERROR -> this->_game->init() failed. " << std::endl;
		return EXIT_FAILURE;
	}

	//TODO remove me
	gRsrcMgr->createText(this->_game._text.w, this->_game._text.h);

	return EXIT_SUCCESS;
}

void Engine::deinit()
{
	this->_game.deinit();

	this->_event.deinit();

	gRsrcMgr->deinit();
	delete gRsrcMgr;
	gRsrcMgr = nullptr;

	gDrawMgr->deinit();
	delete gDrawMgr;
	gDrawMgr = nullptr;
}

void Engine::draw() const
{
	std::vector<DrawParams> drawParams = this->_game.imagesForDrawing();

	std::vector<SDL_Texture*> textures;
	gRsrcMgr->collectImagesForDrawing(textures, drawParams);
	gRsrcMgr->collectTextsForDrawing(textures, drawParams);

	for (size_t i = 0; i < textures.size(); i++)
	{
		gDrawMgr->drawTexture(textures[i], drawParams[i]);
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

		gDrawMgr->clearScreen();
		this->draw();
		gDrawMgr->updateScreen();

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
