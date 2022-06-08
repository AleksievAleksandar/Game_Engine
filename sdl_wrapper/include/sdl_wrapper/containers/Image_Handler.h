#ifndef IMAGE_HANDLER_H
#define IMAGE_HANDLER_H

#include <cstdint>
#include <vector>
#include <unordered_map>

#include "utils/drawing/Rectangle.h"
#include "IHandler.h"

//Forword Declarations
struct SDL_Surface;
struct SDL_Texture;

using Frames = std::vector<Rectangle>;

class Image_Handler : public IHandler
{
public:
	int32_t loadRsrc() override;
	void deinit() override;

	std::unordered_map<int32_t, Frames> getTexturesDimensions() const;

private:
	std::unordered_map<int32_t, Frames> _textureDimensions;
};

#endif // !IMAGE_HANDLER_H
