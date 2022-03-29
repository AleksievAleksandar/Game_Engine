#ifndef ENGINE_H
#define ENGINE_H


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

	InputEvent _event;
	Game _game;
};

#endif // !ENGINE_H

