#ifndef TEXT_HANDLER_H
#define TEXT_HANDLER_H

#include <vector>
#include <unordered_map>

#include "IHandler.h"

//Forword Declarations
typedef struct _TTF_Font TTF_Font;;
struct SDL_Texture;
struct SDL_Surface;
struct Color;

class Text_Handler : public IHandler
{
public:
	int32_t loadRsrc() override;
	void deinit() override;
	std::vector<SDL_Texture*> collectTexturesForDrawing(const std::vector<int32_t>& rsrcId) const override;
	void createText(const int32_t fontTypeIdx, const std::string& text, const Color& color);

private:
	SDL_Surface* createTextureFromFonts(TTF_Font* font, const std::string& text, const Color& color);

	//the textures we'll be drawing
	std::vector<SDL_Texture*> _textures;

	std::unordered_map<int32_t, TTF_Font*> _fonts;
};


#endif // !TEXT_HANDLER_H

