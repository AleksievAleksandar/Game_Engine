#include "Image_Handler.h"

#include <SDL_image.h>
#include <iostream>
#include <string>

int32_t Image_Handler::loadImage()
{
    //Load image from disk
    std::string imagePaths[ImageType::COUNT] = { 
        "../resources/press_keys.png", 
        "../resources/up.png",
        "../resources/down.png",
        "../resources/left.png",
        "../resources/right.png"
    };

    for (int32_t i = 0; i < ImageType::COUNT; i++)
    {
        this->_images[i] = IMG_Load(imagePaths[i].c_str());
        if (nullptr == this->_images[i])
        {
            std::cerr << "ERROR -> Unable to load image " << imagePaths[i] << ". SDL_Error: " << SDL_GetError() << std::endl;
            return EXIT_FAILURE;
        }
    }
    this->_currentImage = this->_images[ImageType::PRESS_KEYS];
    return EXIT_SUCCESS;
}

void Image_Handler::deinit()
{
    //Deallocate surface
    for (int32_t i = 0; i < ImageType::COUNT; i++)
    {
        if (nullptr != this->_images[i])
        {
            SDL_FreeSurface(this->_images[i]);
            this->_images[i] = nullptr;
        }
    }

    if (nullptr != this->_currentImage)
    {
        this->_currentImage = nullptr;
    }
}
