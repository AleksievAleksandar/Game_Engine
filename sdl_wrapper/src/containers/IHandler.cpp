#include "sdl_wrapper/containers/IHandler.h"

#include <iostream>
#include <SDL_ttf.h>

void IHandler::deinit()
{
	//Deallocate texture
	for (auto& texture : this->_textures)
	{
		if (nullptr != texture.second)
		{
			SDL_DestroyTexture(texture.second);
			texture.second = nullptr;
		}
	}
}

void IHandler::collectSingleTextureForDrawing(SDL_Texture*& outCollection, const DrawParams& drawParams) const
{
	const auto& it = this->_textures.find(drawParams.rsrcId);

	if (it == this->_textures.end())
	{
		std::cerr << "ERROR -> IHandler::collectTexturesForDrawing() failed. Providing invalid rsrcId: " << drawParams.rsrcId << std::endl;
		outCollection = nullptr;
		return;
	}

	outCollection = it->second;
}