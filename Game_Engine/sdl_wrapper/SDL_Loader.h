#ifndef SDL_LOADER_H
#define SDL_LOADER_H

#include <cstdint>

class SDL_Loader
{
public:
	int32_t init();
	void deinit();
	//int32_t draw() const;
};

#endif // !SDL_LOADER_H

