#ifndef ENGINE_H
#define ENGINE_H

#include "sdl_wrapper/containers/Image_Handler.h"
#include "sdl_wrapper/containers/Text_Handler.h"
#include "sdl_wrapper/Input_Events.h"
#include "../game/Game.h"

#include <cstdint>

class Engine
{
public:
	int32_t init();
	void deinit();
	void start();

private:
	void draw() const;
	void mainLoop();
	bool handleEvent();
	void limitFPS(int64_t elapsedMicroseconds) const;

	Image_Handler _imageHandler;
	Text_Handler _textHandler;
	InputEvent _event;
	Game _game;
};

#endif // !ENGINE_H

