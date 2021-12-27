#include "Image_Handler.h"

#include <SDL_Surface.h>
#include <iostream>

int32_t Image_Handler::loadImage(SDL_Surface*& outImage)
{
    //Load image from disk
    outImage = SDL_LoadBMP("../resources/hello.bmp");
    if (nullptr == outImage)
    {
        std::cerr << "ERROR -> Unable to load image. SDL_Error: " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void Image_Handler::deinit(SDL_Surface*& outImage)
{
    //Deallocate surface
    if (nullptr != outImage)
    {
        SDL_FreeSurface(outImage);
        outImage = nullptr;
    }
}
