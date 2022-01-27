#ifndef SDL_LOADER_H
#define SDL_LOADER_H

#include <cstdint>


#include "Image_Handler.h"

//Forword Declarations
struct SDL_Window;
struct SDL_Surface;

class SDL_Loader
{
public:
	int32_t init();
	void deinit();
	//int32_t draw() const;
	SDL_Window* getWindow() const;

private:
	//The window we'll be rendering(drawing) to
	SDL_Window* _window = nullptr;

	//The surface(data structure) contained by the window
	SDL_Surface* _surface = nullptr;
};

#endif // !SDL_LOADER_H

