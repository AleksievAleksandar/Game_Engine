#ifndef TEXT_HANDLER_H
#define TEXT_HANDLER_H

#include <vector>
#include <unordered_map>

//Forword Declarations
struct TTF_Font;
struct SDL_Texture;

class Text_Handler
{

private:
	//the textures we'll be drawing
	std::vector<SDL_Texture*> _textures;

	std::unordered_map<int32_t, TTF_Font*> _fonts;
};


#endif // !TEXT_HANDLER_H

