#ifndef IMAGE_HANDLER_H
#define IMAGE_HANDLER_H

#include <cstdint>
#include <vector>
#include <unordered_map>

#include "config/ImageCfg.h"
#include "../utils/drawing/Rectangle.h"

//Forword Declarations
struct SDL_Surface;
struct SDL_Texture;

class Image_Handler
{
public:
	int32_t loadImage();
	void deinit();
	std::vector<SDL_Texture*> imagesForDrawing() const;
	void setCurrentImage(const ImageType& type);

	std::pair<SDL_Texture*, Rectangle> getImage(const int32_t rsrcId) const;
	int dummy = -1;
private:
	SDL_Texture* _currentTextureImage = nullptr;
	//SDL_Texture* _texturesImages[COUNT]{};

	std::unordered_map<int32_t, SDL_Texture*> _texturesImages;
	std::unordered_map<int32_t, Rectangle> _textureDimensions;

	//The image that will be loaded from disk and shown on the screen
	//SDL_Surface* _currentImage = nullptr;
	//SDL_Surface* _images[COUNT]{};
};

#endif // !IMAGE_HANDLER_H
