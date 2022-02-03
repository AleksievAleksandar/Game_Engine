#ifndef ENGINE_H
#define ENGINE_H

#include "../sdl_wrapper/Input_Events.h"
#include "../sdl_wrapper/Renderer.h"
#include "../sdl_wrapper/Image_Handler.h"

#include <cstdint>

//Forword Declarations
class SDL_Loader;
class Renderer;
class Image_Handler;
class InputEvent;

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

	SDL_Loader* _sdl_loader = nullptr;
	Renderer _renderer;
	Image_Handler _imageHandler;
	InputEvent _event;
};

#endif // !ENGINE_H

