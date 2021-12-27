#ifndef IMAGE_HANDLER_H
#define IMAGE_HANDLER_H

#include <cstdint>

//Forword Declarations
struct SDL_Surface;

class Image_Handler
{
public:
	Image_Handler() = delete;

	static int32_t loadImage(SDL_Surface*& outImage);
	static void deinit(SDL_Surface*& outImage);
};

#endif // !IMAGE_HANDLER_H
