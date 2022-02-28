#ifndef IMAGE_HANDLER_H
#define IMAGE_HANDLER_H

#include <cstdint>
#include <vector>
#include <unordered_map>

#include "../config/ImageCfg.h"
#include "../../utils/drawing/Rectangle.h"
#include "../../common_defines/Common_Defines.h"
#include "IHandler.h"

//Forword Declarations
struct SDL_Surface;
struct SDL_Texture;

class Image_Handler : public IHandler
{
public:
	int32_t loadRsrc() override;
	void deinit() override;

	std::vector<std::pair<SDL_Texture*, DrawParams> > collectTexturesForDrawing(const std::vector<DrawParams>& drawParams) const override;	
	std::pair<SDL_Texture*, Rectangle> getTextures(const int32_t rsrcId) const;
	std::unordered_map<int32_t, Rectangle> getTexturesDimensions() const;

private:
	std::unordered_map<int32_t, SDL_Texture*> _textures;
	std::unordered_map<int32_t, Rectangle> _textureDimensions;
};

#endif // !IMAGE_HANDLER_H
