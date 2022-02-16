#ifndef ENGINE_H
#define ENGINE_H

#include "../sdl_wrapper/Window.h"
#include "../sdl_wrapper/Renderer.h"
#include "../sdl_wrapper/Image_Handler.h"
#include "../sdl_wrapper/Input_Events.h"

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

	Window _window;
	Renderer _renderer;
	Image_Handler _imageHandler;
	InputEvent _event;
};

#endif // !ENGINE_H

