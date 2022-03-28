#include "manager_utils/DrawMgr.h"

#include <iostream>

DrawMgr* gDrawMgr = nullptr;

int32_t DrawMgr::init()
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

	return EXIT_SUCCESS;
}

void DrawMgr::deinit()
{
	this->_renderer.deinit();
	this->_window.deinit();
}

void DrawMgr::drawTexture(SDL_Texture* texture, const DrawParams& drawParam)
{
	this->_renderer.drawTexture(texture, drawParam);
}

void DrawMgr::clearScreen()
{
	this->_renderer.clearScreen();
}

void DrawMgr::updateScreen()
{
	this->_renderer.updateScreen();
}
