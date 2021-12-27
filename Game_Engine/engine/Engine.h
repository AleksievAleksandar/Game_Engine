#ifndef ENGINE_H
#define ENGINE_H

#include <cstdint>

//Forword Declarations
struct SDL_Loader;

class Engine
{
public:
	int32_t init();
	void deinit();
	int32_t draw() const;

private:
	SDL_Loader* sdl_loader = nullptr;
};

#endif // !ENGINE_H

