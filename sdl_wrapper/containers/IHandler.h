#ifndef IHANDLER_H
#define IHANDLER_H

#include <cstdint>
#include <vector>

//Forword Declarations
struct SDL_Texture;

class IHandler
{
public:
	virtual int32_t loadRsrc() = 0;
	virtual void deinit() = 0;
	virtual std::vector<SDL_Texture*> collectTexturesForDrawing(const std::vector<int32_t>& rsrcId) const = 0;

	virtual ~IHandler() {};
};

#endif // !IHANDLER_H

