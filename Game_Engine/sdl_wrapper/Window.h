#ifndef WINDOW_H
#define WINDOW_H

#include <cstdint>
#include <string>

//Forword Declarations
struct SDL_Window;
struct SDL_Surface;

struct WindowCfg
{
	const std::string windowName = "Game Engine";

	const uint32_t windowPosX = 536805376; //SDL_WINDOWPOS_UNDEFINED;
	const uint32_t windowPosY = 536805376; //SDL_WINDOWPOS_UNDEFINED;

	const uint32_t SCREEN_WIDTH = 640;
	const uint32_t SCREEN_HEIGHT = 480;

	const int32_t windowShown = 4; //SDL_WINDOW_SHOWN;
};

class Window
{
public:
	Window() = delete;

	static int32_t createWindow(const WindowCfg& winCfg, SDL_Window*& outWindow);
	static void destroyWindow(SDL_Window*& outWindow);

	static SDL_Surface* getSurfaceFromWindow(SDL_Window* window);
};

#endif // !WINDOW_H

