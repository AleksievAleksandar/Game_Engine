#ifndef RENDERER_H
#define RENDERER_H

#include <cstdint>

//Forward declarations
struct SDL_Renderer;
struct SDL_Texture; //cross-platform GPU primitive
struct SDL_Window;
struct DrawParams;

class Renderer
{
public:
	int32_t init(SDL_Window* window);
	void deinit();
	void clearScreen();
	void updateScreen();
	void drawTexture(SDL_Texture* texture, const DrawParams& drawParam) const;

private:
	void drawImages(SDL_Texture* texture, const DrawParams& drawParam) const;
	void drawTexts(SDL_Texture* texture, const DrawParams& drawParam) const;
	void renderTexture(SDL_Texture* texture, const DrawParams& drawParam) const;

	SDL_Renderer* _sdlRenderer = nullptr;
};

#endif // !RENDERER_H
