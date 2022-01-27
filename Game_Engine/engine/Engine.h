#ifndef ENGINE_H
#define ENGINE_H

#include "../sdl_wrapper/Input_Events.h"
#include "../sdl_wrapper/Renderer.h"
#include "../sdl_wrapper/Image_Handler.h"
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
	void limitFPS(int64_t elapsedMicroseconds) const;

	Image_Handler _imageHandler;
	SDL_Loader* _sdl_loader = nullptr;
	InputEvent _event;
	Renderer _renderer;
};

#endif // !ENGINE_H

