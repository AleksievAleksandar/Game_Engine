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
	virtual void collectTexturesForDrawing(std::vector<SDL_Texture*>& outCollection, const std::vector<DrawParams>& drawParams) const = 0;

	virtual ~IHandler() {};
};

#endif // !IHANDLER_H

