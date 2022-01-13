#ifndef IMAGE_HANDLER_H
#define IMAGE_HANDLER_H

#include <cstdint>

//Forword Declarations
struct SDL_Surface;

enum ImageType
{
	PRESS_KEYS,
	UP,
	DOWN,
	LEFT,
	RIGHT,

	COUNT
};

class Image_Handler
{
public:
	int32_t loadImage();
	void deinit();

	//The image that will be loaded from disk and shown on the screen
	SDL_Surface* _currentImage = nullptr;	
	SDL_Surface* _images[COUNT]{};
};

#endif // !IMAGE_HANDLER_H
