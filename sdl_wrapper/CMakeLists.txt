cmake_minimum_required(VERSION 3.10.2)

project(sdl_wrapper LANGUAGES CXX)
  
if(UNIX)
    set(SDL_IMAGE_PKG_NAME SDL2_image)
    set(SDL_TTF_PKG_NAME SDL2_ttf)
    set(SDL_MIXER_PKG_NAME SDL2_mixer)
elseif(WIN32)
    set(SDL_IMAGE_PKG_NAME SDL2_IMAGE)
    set(SDL_TTF_PKG_NAME SDL2_TTF)
    set(SDL_MIXER_PKG_NAME SDL2_MIXER)
else()
    message("Error: Unsupported OS")
endif()
  
find_package(SDL2 REQUIRED)
find_package(${SDL_IMAGE_PKG_NAME} REQUIRED)
find_package(${SDL_TTF_PKG_NAME} REQUIRED)
find_package(${SDL_MIXER_PKG_NAME} REQUIRED)

set(_BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(_INC_DIR ${_BASE_DIR}/sdl_wrapper)
set(_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_library(
    ${PROJECT_NAME} STATIC 

        ${_INC_DIR}/SDL_Loader.h
        ${_INC_DIR}/SDL_Helpers.h
        ${_INC_DIR}/Input_Events.h
        ${_INC_DIR}/Renderer.h
        ${_INC_DIR}/Window.h
        ${_INC_DIR}/config/WindowCfg.h
        ${_INC_DIR}/config/ImageCfg.h
        ${_INC_DIR}/config/TextCfg.h
        ${_INC_DIR}/containers/IHandler.h
        ${_INC_DIR}/containers/Image_Handler.h
        ${_INC_DIR}/containers/Text_Handler.h
        
        ${_SRC_DIR}/SDL_Loader.cpp
        ${_SRC_DIR}/SDL_Helpers.cpp
        ${_SRC_DIR}/Input_Events.cpp
        ${_SRC_DIR}/Renderer.cpp
        ${_SRC_DIR}/Window.cpp
        ${_SRC_DIR}/config/ImageCfg.cpp
        ${_SRC_DIR}/config/TextCfg.cpp
        ${_SRC_DIR}/containers/Image_Handler.cpp
        ${_SRC_DIR}/containers/Text_Handler.cpp
)

set_target_cpp_standard(${PROJECT_NAME} 17)
enable_target_warnings(${PROJECT_NAME})

target_include_directories(
    ${PROJECT_NAME}
        PUBLIC 
            ${_BASE_DIR}
        PRIVATE
            ${SDL2_INCLUDE_DIR}
            ${SDL2_IMAGE_INCLUDE_DIR}
            ${SDL2_TTF_INCLUDE_DIR}
            ${SDL2_MIXER_INCLUDE_DIR}
)

target_link_libraries(
    ${PROJECT_NAME}
        PUBLIC
            utils
        PRIVATE
            ${SDL2_LIBRARY}       # -lSDL2 flag
            ${SDL2_IMAGE_LIBRARY} # -lSDL2_image flag
            ${SDL2_TTF_LIBRARY}   # -lSDL2_ttf flag
            ${SDL2_MIXER_LIBRARY} # -lSDL2_mixer flag  
)
