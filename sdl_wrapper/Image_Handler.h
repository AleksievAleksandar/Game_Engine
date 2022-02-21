#ifndef IMAGE_HANDLER_H
#define IMAGE_HANDLER_H

#include <cstdint>
#include <vector>
#include <unordered_map>

#include "config/ImageCfg.h"
#include "../utils/drawing/Rectangle.h"
#include "../common_defines/Common_Defines.h"
#include "../utils/drawing/DrawParams.h"

//Forword Declarations
struct SDL_Surface;
struct SDL_Texture;

class Image_Handler
{
public:
	int32_t loadImage();
	void deinit();
	std::vector<std::pair<SDL_Texture*, DrawParams> > imagesForDrawing(const std::vector<DrawParams>& drawParamsIDs) const;
	void setCurrentImage(const Textures::ImageType& type);

	std::pair<SDL_Texture*, Rectangle> getImage(const int32_t rsrcId) const;
	std::unordered_map<int32_t, Rectangle> getImagesDimensions() const;

private:
	SDL_Texture* _currentTextureImage = nullptr;

	std::unordered_map<int32_t, SDL_Texture*> _texturesImages;
	std::unordered_map<int32_t, Rectangle> _textureDimensions;
};

#endif // !IMAGE_HANDLER_H
