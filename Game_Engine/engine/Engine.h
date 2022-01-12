#ifndef ENGINE_H
#define ENGINE_H

#include "../sdl_wrapper/Input_Events.h"
#include <cstdint>

//Forword Declarations
struct SDL_Loader;

class Engine
{
public:
	int32_t init();
	void deinit();
	void start();

private:
	int32_t draw() const;
	void mainLoop();
	bool handleEvent();
	void limitFPS() const;

	SDL_Loader* sdl_loader = nullptr;
	InputEvent event;
};

#endif // !ENGINE_H

