#ifndef DRAW_MANAGER_H
#define DRAW_MANAGER_H

#include <cstdlib>

#include "sdl_wrapper/Window.h"
#include "sdl_wrapper/Renderer.h"

class DrawMgr
{
public:
	DrawMgr() = default;

	//forbid the copy and move constructors
	DrawMgr(const DrawMgr & other) = delete;
	DrawMgr(DrawMgr && other) = delete;

	//forbid the copy and move assignment operators
	DrawMgr& operator=(const DrawMgr & other) = delete;
	DrawMgr& operator=(DrawMgr && other) = delete;

	int32_t init();
	void deinit();
	void drawTexture(SDL_Texture*& texture, const DrawParams& drawParam);
	void clearScreen();
	void updateScreen();

private:
	Window _window;
	Renderer _renderer;
};

extern DrawMgr* gDrawMgr;

#endif // !DRAW_MANAGER_H

