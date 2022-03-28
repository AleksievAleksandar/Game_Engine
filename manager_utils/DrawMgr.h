#ifndef DRAW_MANAGER_H
#define DRAW_MANAGER_H

#include <cstdlib>

#include "sdl_wrapper/Window.h"
#include "sdl_wrapper/Renderer.h"

class DrawMgr
{
public:
	int32_t init();
	void deinit();
	void drawTexture(SDL_Texture* texture, const DrawParams& drawParam);
	void clearScreen();
	void updateScreen();

private:
	Window _window;
	Renderer _renderer;
};

extern DrawMgr* gDrawMgr;

#endif // !DRAW_MANAGER_H

