#ifndef SDL_LOADER_H
#define SDL_LOADER_H

#include <cstdint>

class SDL_Loader
{
public:
	SDL_Loader() = delete;

	static int32_t init();
	static void deinit();
};

#endif // !SDL_LOADER_H

