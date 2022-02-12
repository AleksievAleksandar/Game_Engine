#ifndef RENDERER_H
#define RENDERER_H

#include <cstdint>
#include <vector>

#include "../utils/drawing/Rectangle.h"

//Forward declarations
struct SDL_Renderer;
struct SDL_Texture; //cross-platform GPU primitive
struct SDL_Window;

class Renderer
{
public:
	int32_t init(SDL_Window* window);
	void deinit();
	void clearScreen();
	void updateScreen();
	void drawTexture(const std::vector<SDL_Texture*>& images) const;
	void drawTexture(const std::vector<std::pair<SDL_Texture*, Rectangle> >& images) const;

private:
	SDL_Renderer* _sdlRenderer = nullptr;
};

#endif // !RENDERER_H
