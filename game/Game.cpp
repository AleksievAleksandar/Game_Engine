#include "Game.h"

#include "../common_defines/Common_Defines.h"
#include "sdl_wrapper/Input_Events.h"

#include <cstdlib>
#include <iostream>

int32_t Game::init(const std::unordered_map<int32_t, Frames>& _textureDimensions)
{
	if (EXIT_SUCCESS != this->_layer_2.create(_textureDimensions, Textures::LAYER_2))
	{
		std::cerr << "ERROR -> Failed to create image obj with ID: " << Textures::LAYER_2 << std::endl;
		return EXIT_FAILURE;
	}

	if (EXIT_SUCCESS != this->_press_keys.create(_textureDimensions, Textures::PRESS_KEYS))
	{
		std::cerr << "ERROR -> Failed to create image obj with ID: " << Textures::PRESS_KEYS << std::endl;
		return EXIT_FAILURE;
	}

	if (EXIT_SUCCESS != this->_running_girl.create(_textureDimensions, Textures::RUNNING_GIRL, Textures::ImageFrames::RUNNING_GIRL_FRAMES))
	{
		std::cerr << "ERROR -> Failed to create hero obj with ID: " << Textures::RUNNING_GIRL << std::endl;
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

		this->_running_girl.handleEvent(event);


		if (event.touchEvent != TouchEvent::KEYBOARD_RELEASE)
		{
			return false;
		}

		if (event.key == Keyboard::Key::KEY_NUMPAD_PLUS)
		{
			this->_press_keys.setOpacity(10);
		}
		else if (event.key == Keyboard::Key::KEY_NUMPAD_MINUS)
		{
			this->_press_keys.setOpacity(-10);
		}
		else if (event.key == Keyboard::Key::KEY_R)
		{
			this->_text.reloadContent("RELOADED TEXT");
		}
	}
	return false;
}

//std::vector<DrawParams> Game::giveWidgetsForDrawing() const
//{
//	std::vector<DrawParams> drawParams;
//
//	drawParams.push_back(this->_press_keys.getDrawParams());
//	drawParams.push_back(this->_layer_2.getDrawParams());
//	drawParams.push_back(this->_running_girl.getDrawParams());
//
//	drawParams.push_back(this->_text.getDrawParams());
//	drawParams.push_back(this->_secondText.getDrawParams());
//
//	return drawParams;
//}

void Game::draw() const
{
	this->_press_keys.draw();
	this->_layer_2.draw();
	this->_running_girl.draw();

	this->_text.draw();
	this->_secondText.draw();
}

