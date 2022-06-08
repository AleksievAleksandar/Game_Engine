#ifndef IHANDLER_H
#define IHANDLER_H

#include <cstdint>
#include <vector>

#include "utils/drawing/DrawParams.h"

//Forword Declarations
struct SDL_Texture;

class IHandler
{
public:
	virtual int32_t loadRsrc() = 0;
	virtual void deinit() = 0;
	virtual void collectSingleTextureForDrawing(SDL_Texture*& outCollection, const DrawParams& drawParams) const = 0;

	virtual ~IHandler() {};

protected:
	//the textures we'll be drawing
	std::unordered_map<int32_t, SDL_Texture*> _textures;
};

#endif // !IHANDLER_H

