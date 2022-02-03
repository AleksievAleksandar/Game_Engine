#ifndef WINDOW_CFG_H
#define WINDOW_CFG_H

struct WindowCfg
{
	const std::string windowName = "Game Engine";

	const uint32_t windowPosX = 536805376; //SDL_WINDOWPOS_UNDEFINED;
	const uint32_t windowPosY = 536805376; //SDL_WINDOWPOS_UNDEFINED;

	const uint32_t SCREEN_WIDTH = 640;
	const uint32_t SCREEN_HEIGHT = 480;

	const int32_t windowShown = 4; //SDL_WINDOW_SHOWN;
};

#endif // !WINDOW_CFG_H

