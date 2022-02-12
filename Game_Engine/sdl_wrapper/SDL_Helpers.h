#ifndef SDL_HELPERS_H
#define SDL_HELPERS_H

#include <cstdint>
#include <string>

//Forword Declarations
struct SDL_Window;
struct SDL_Surface;
struct SDL_Texture;
struct SDL_Renderer;

class SDL_Helpers
{
public:
	SDL_Helpers() = delete;
	SDL_Helpers(const SDL_Helpers& other) = delete;
	SDL_Helpers(SDL_Helpers&& other) = delete;

	static int32_t createWindow(SDL_Window*& outWindow);
	static void destroyWindow(SDL_Window*& outWindow);

	static SDL_Surface* getSurfaceFromWindow(SDL_Window* window);
	static SDL_Texture* getTextureFromSurface(SDL_Surface* surface);
	
	static void copy_SDL_Renderer_ptr(SDL_Renderer* renderer);
};

#endif // !SDL_HELPERS_H

