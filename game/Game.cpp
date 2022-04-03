#include "Game.h"

#include "../common_defines/Common_Defines.h"
#include "sdl_wrapper/Input_Events.h"

#include <cstdlib>
#include <iostream>

int32_t Game::init(const std::unordered_map<int32_t, Rectangle>& _textureDimensions)
{
	this->_layer_2.create(_textureDimensions, Textures::LAYER_2);
	this->_press_keys.create(_textureDimensions, Textures::PRESS_KEYS);

	this->_text.create(Fonts::YAGORA_FONT);
	this->_text.createContent("Hello World");

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
		if (event.key == Keyboard::Key::KEY_UP)
		{
			this->_press_keys.moveUp();
		}
		else if (event.key == Keyboard::Key::KEY_DOWN)
		{
			this->_press_keys.moveDown();
		}
		else if (event.key == Keyboard::Key::KEY_LEFT)
		{
			this->_press_keys.moveLeft();
		}
		else if (event.key == Keyboard::Key::KEY_RIGHT)
		{
			this->_press_keys.moveRight();
		}
		else if (event.key == Keyboard::Key::KEY_Z)
		{
			this->_press_keys.setOpacity(-10);
		}
		else if (event.key == Keyboard::Key::KEY_X)
		{
			this->_press_keys.setOpacity(10);
		}
		else if (event.key == Keyboard::Key::KEY_R)
		{
			this->_text.reloadContent("Aleksandar");
		}

		if (event.checkForExitRequestEvent())
		{
			return true;
		}
	}
	return false;
}

std::vector<DrawParams> Game::imagesForDrawing() const
{
	std::vector<DrawParams> drawParams;
	drawParams.push_back(this->_press_keys.getDrawParams());
	drawParams.push_back(this->_layer_2.getDrawParams());
	drawParams.push_back(this->_text.getDrawParams());

	return drawParams;
}

void Game::setTextDimmensions(const int32_t param_w, const int32_t param_h)
{
	this->_text.setTextWidth(param_w);
	this->_text.setTextHeight(param_h);
}

