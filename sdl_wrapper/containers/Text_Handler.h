#ifndef TEXT_HANDLER_H
#define TEXT_HANDLER_H

#include <vector>
#include <unordered_map>

#include "IHandler.h"

//Forword Declarations
typedef struct _TTF_Font TTF_Font;;
struct SDL_Texture;

class Text_Handler : public IHandler
{
public:
	int32_t loadRsrc() override;
	void deinit() override;
	std::vector<SDL_Texture*> collectTexturesForDrawing(const std::vector<int32_t>& rsrcId) const override;

private:
	void createTexturesFromFonts();

	//the textures we'll be drawing
	std::vector<SDL_Texture*> _textures;

	std::unordered_map<int32_t, TTF_Font*> _fonts;
};


#endif // !TEXT_HANDLER_H

