#ifndef SDL_LOADER_H
#define SDL_LOADER_H

#include <cstdint>

//Forword Declarations
struct SDL_Window;
struct SDL_Surface;

class SDL_Loader
{
public:
	int32_t init();
	void deinit();
	int32_t draw() const;

private:
	//The window we'll be rendering(drawing) to
	SDL_Window* _window = nullptr;

	//The surface(data structure) contained by the window
	SDL_Surface* _surface = nullptr;

	//The image that will be loaded from disk and shown on the screen
	SDL_Surface* _image = nullptr;
};

#endif // !SDL_LOADER_H

