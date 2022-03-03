#include "Game.h"

#include "../common_defines/Common_Defines.h"
#include "../sdl_wrapper/Input_Events.h"

#include <cstdlib>
#include <iostream>

int32_t Game::init(const std::unordered_map<int32_t, Rectangle>& _textureDimensions)
{
	auto it = _textureDimensions.find(Textures::LAYER_2);
	if (it == _textureDimensions.end())
	{
		std::cerr << "ERROR -> Can not find Texture ID: " << Textures::LAYER_2 << " to init() Game." << std::endl;
		return EXIT_FAILURE;
	}
	this->_layer_2_image.widgetType = WidgetType::IMAGE;
	this->_layer_2_image.rsrcId = it->first;
	this->_layer_2_image.h = it->second.h;
	this->_layer_2_image.w = it->second.w;
	this->_layer_2_image.pos = Point::ZERO;

	//std::cout << "LAYER_2: X = " << _layer_2_image.pos.x << "; Y = " << _layer_2_image.pos.y << "; W = " << _layer_2_image.w << "; H = " << _layer_2_image.h << " RsrcID = " << this->_layer_2_image.rsrcId << std::endl;

	it = _textureDimensions.find(Textures::PRESS_KEYS);
	if (it == _textureDimensions.end())
	{
		std::cerr << "ERROR -> Can not find Texture ID: " << Textures::PRESS_KEYS << " to init() Game." << std::endl;
		return EXIT_FAILURE;
	}
	this->_press_keys_image.widgetType = WidgetType::IMAGE;
	this->_press_keys_image.rsrcId = it->first;
	this->_press_keys_image.h = it->second.h;
	this->_press_keys_image.w = it->second.w;
	this->_press_keys_image.pos = Point::ZERO;
	
	//std::cout << "PRESS_KEYS: X = " << _press_keys_image.pos.x << "; Y = " << _press_keys_image.pos.y << "; W = " << _press_keys_image.w << "; H = " << _press_keys_image.h << " RsrcID = " << this->_press_keys_image.rsrcId << std::endl;

	this->_text.widgetType = WidgetType::TEXT;
	this->_text.rsrcId = 0;
	this->_text.pos = Point::ZERO;

	return EXIT_SUCCESS;
}

void Game::deinit()
{
}

bool Game::handleEvent(InputEvent& event)
{
	while (event.pollEvent())
	{
		if (event.key == Keyboard::Key::KEY_UP)
		{
			this->_press_keys_image.pos.y--;
		}
		else if (event.key == Keyboard::Key::KEY_DOWN)
		{
			this->_press_keys_image.pos.y++;
		}
		else if (event.key == Keyboard::Key::KEY_LEFT)
		{
			this->_press_keys_image.pos.x--;
		}
		else if (event.key == Keyboard::Key::KEY_RIGHT)
		{
			this->_press_keys_image.pos.x++;
		}
		else if (event.key == Keyboard::Key::KEY_Z)
		{
			this->_press_keys_image.opacity -= 10;
		}
		else if (event.key == Keyboard::Key::KEY_X)
		{
			this->_press_keys_image.opacity += 10;
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
	drawParams.push_back(this->_press_keys_image);
	drawParams.push_back(this->_layer_2_image);

	return drawParams;
}

std::vector<int32_t> Game::imagesForDrawingByRcrsId() const
{
	std::vector<int32_t> drawParamsIds;

	drawParamsIds.push_back(this->_press_keys_image.rsrcId);
	drawParamsIds.push_back(this->_layer_2_image.rsrcId);

	return drawParamsIds;
}

std::vector<DrawParams> Game::textForDrawing() const
{
	std::vector<DrawParams> drawParams;

	drawParams.push_back(this->_text);

	return drawParams;
}

std::vector<int32_t> Game::textForDrawingByRcrsId() const
{
	std::vector<int32_t> drawParamsIds;

	drawParamsIds.push_back(this->_text.rsrcId);

	return drawParamsIds;
}
