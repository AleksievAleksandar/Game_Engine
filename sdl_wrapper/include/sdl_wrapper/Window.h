#ifndef WINDOW_H
#define WINDOW_H

#include <cstdint>

//Forword Declarations
struct SDL_Loader;
struct SDL_Window;
struct SDL_Surface;

class Window
{
public:
	int32_t init();
	void deinit();
	//int32_t draw() const;
	SDL_Window* getWindow() const;

private:
	SDL_Loader* _sdl_loader = nullptr;

	//The window we'll be rendering(drawing) to
	SDL_Window* _window = nullptr;

	//The surface(data structure) contained by the window
	SDL_Surface* _windowSurface = nullptr;
};

#endif // !WINDOW_H
