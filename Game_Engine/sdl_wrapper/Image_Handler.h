#ifndef IMAGE_HANDLER_H
#define IMAGE_HANDLER_H

#include <cstdint>
#include <vector>

//Forword Declarations
struct SDL_Surface;
struct SDL_Texture;

enum ImageType
{
	PRESS_KEYS,
	UP,
	DOWN,
	LEFT,
	RIGHT,
	LAYER_2,

	COUNT
};

class Image_Handler
{
public:
	int32_t loadImage();
	void deinit();
	std::vector<SDL_Texture*> imagesForDrawing() const;
	void setCurrentImage(const ImageType& type);

	SDL_Texture* _currentTextureImage = nullptr;
	SDL_Texture* _texturesImages[COUNT]{};

	//The image that will be loaded from disk and shown on the screen
	SDL_Surface* _currentImage = nullptr;
	SDL_Surface* _images[COUNT]{};
private:


	
};

#endif // !IMAGE_HANDLER_H
