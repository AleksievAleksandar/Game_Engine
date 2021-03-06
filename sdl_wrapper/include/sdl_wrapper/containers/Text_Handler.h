#ifndef TEXT_HANDLER_H
#define TEXT_HANDLER_H

#include <vector>
#include <unordered_map>

#include "sdl_wrapper/containers/IHandler.h"

//Forward Declarations
typedef struct _TTF_Font TTF_Font;
struct SDL_Texture;
struct Color;

class Text_Handler : public IHandler
{
public:
	int32_t loadRsrc() override;
	void deinit() override;

	void createText(const int32_t fontTypeIdx, const std::string& text, const Color& color, int32_t& outTextWidth, int32_t& outTextHeight);
	void reloadText(const int32_t idx, const std::string& newText, const Color& color, int32_t& outTextWidth, int32_t& outTextHeight);

private:
	SDL_Texture* createTextTexture(TTF_Font* font, const std::string& text, const Color& color, int32_t& outTextWidth, int32_t& outTextHeight);
	
	std::unordered_map<int32_t, TTF_Font*> _fonts;
};


#endif // !TEXT_HANDLER_H

