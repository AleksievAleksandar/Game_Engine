#ifndef SDL_LOADER_H
#define SDL_LOADER_H

#include <cstdint>

//Forword Declarations
struct SDL_Window;
struct SDL_Surface;

class SDL_Loader
{
public:
	SDL_Loader() = delete;

	static int32_t init(SDL_Window*& outWindow, SDL_Surface*& outSurface, SDL_Surface*& outImage);
	static void deinit(SDL_Window*& outWindow, SDL_Surface*& outImage);
	static int32_t draw(SDL_Window* window, SDL_Surface* surface, SDL_Surface* image);
};

#endif // !SDL_LOADER_H

