#ifndef ENGINE_H
#define ENGINE_H

#include <cstdint>

//Forword Declarations
struct SDL_Loader;
struct Renderer;
struct Image_Handler;
struct InputEvent;

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
	Renderer* _renderer;
	Image_Handler* _imageHandler;
	InputEvent* _event;
};

#endif // !ENGINE_H

