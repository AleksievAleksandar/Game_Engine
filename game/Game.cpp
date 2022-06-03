#include "Game.h"

#include "../common_defines/Common_Defines.h"
#include "sdl_wrapper/Input_Events.h"

#include <cstdlib>
#include <iostream>

int32_t Game::init(const std::unordered_map<int32_t, Frames>& _textureDimensions)
{
	if (EXIT_SUCCESS != this->_layer_2.create(_textureDimensions, Textures::LAYER_2))
	{
		std::cerr << "ERROR -> Failed to create image with ID: " << Textures::LAYER_2 << std::endl;
		return EXIT_FAILURE;
	}

	if (EXIT_SUCCESS != this->_press_keys.create(_textureDimensions, Textures::PRESS_KEYS))
	{
		std::cerr << "ERROR -> Failed to create image with ID: " << Textures::PRESS_KEYS << std::endl;
		return EXIT_FAILURE;
	}

	if (EXIT_SUCCESS != this->_running_girl.create(_textureDimensions, Textures::RUNNING_GIRL, Textures::ImageFrames::RUNNING_GIRL_FRAMES))
	{
		std::cerr << "ERROR -> Failed to create image with ID: " << Textures::RUNNING_GIRL << std::endl;
		return EXIT_FAILURE;
	}

	if (EXIT_SUCCESS != this->_text.create("Hello World"))
	{
		std::cerr << "ERROR -> Failed to create text" << std::endl;
		return EXIT_FAILURE;
	}

	if (EXIT_SUCCESS != this->_secondText.create("secondText", Fonts::ANGELINE_VINTAGE_FONT, Colors::BLUE, Point(100, 100)))
	{
		std::cerr << "ERROR -> Failed to create text" << std::endl;
		return EXIT_FAILURE;
	}
	
	return EXIT_SUCCESS;
}

void Game::deinit()
{
	//empty
}

bool Game::handleEvent(InputEvent& event)
{
	while (event.pollEvent())
	{
		if (event.checkForExitRequestEvent())
		{
			return true;
		}

		if (event.touchEvent != TouchEvent::KEYBOARD_RELEASE)
		{
			return false;
		}

		this->_running_girl.handleEvent(event);
	}
	return false;
}

std::vector<DrawParams> Game::giveWidgetsForDrawing() const
{
	std::vector<DrawParams> drawParams;

	drawParams.push_back(this->_press_keys.getDrawParams());
	drawParams.push_back(this->_layer_2.getDrawParams());
	drawParams.push_back(this->_running_girl.getDrawParams());

	drawParams.push_back(this->_text.getDrawParams());
	drawParams.push_back(this->_secondText.getDrawParams());

	return drawParams;
}

