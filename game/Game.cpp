#include "Game.h"

#include "../common_defines/Common_Defines.h"

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
	this->_press_keys_image.rsrcId = it->first;
	this->_press_keys_image.h = it->second.h;
	this->_press_keys_image.w = it->second.w;
	this->_press_keys_image.pos = Point::ZERO;
	
	//std::cout << "PRESS_KEYS: X = " << _press_keys_image.pos.x << "; Y = " << _press_keys_image.pos.y << "; W = " << _press_keys_image.w << "; H = " << _press_keys_image.h << " RsrcID = " << this->_press_keys_image.rsrcId << std::endl;

	return EXIT_SUCCESS;
}

void Game::deinit()
{
}

std::vector<DrawParams> Game::imagesForDrawing() const
{
	std::vector<DrawParams> drawParamsIDs;
	drawParamsIDs.push_back(this->_press_keys_image);
	drawParamsIDs.push_back(this->_layer_2_image);

	return drawParamsIDs;
}
