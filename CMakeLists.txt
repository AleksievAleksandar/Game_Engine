cmake_minimum_required(VERSION 3.10.2)

project(GameEngine LANGUAGES CXX)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake_helpers/helpers.cmake)
set(CMAKE_MODULE_PATH 
    ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake_helpers/find_modules)
  
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

set(_BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

#generate project binary
message(${_BASE_DIR})
add_executable(
    ${PROJECT_NAME}  
        ${_BASE_DIR}/common_defines/Common_Defines.h

        ${_BASE_DIR}/sdl_wrapper/SDL_Loader.h
        ${_BASE_DIR}/sdl_wrapper/SDL_Loader.cpp
        ${_BASE_DIR}/sdl_wrapper/SDL_Helpers.h
        ${_BASE_DIR}/sdl_wrapper/SDL_Helpers.cpp
        ${_BASE_DIR}/sdl_wrapper/Input_Events.h
        ${_BASE_DIR}/sdl_wrapper/Input_Events.cpp
        ${_BASE_DIR}/sdl_wrapper/Renderer.h
        ${_BASE_DIR}/sdl_wrapper/Renderer.cpp
        ${_BASE_DIR}/sdl_wrapper/Window.h
        ${_BASE_DIR}/sdl_wrapper/Window.cpp

        ${_BASE_DIR}/sdl_wrapper/config/WindowCfg.h
        ${_BASE_DIR}/sdl_wrapper/config/ImageCfg.h
        ${_BASE_DIR}/sdl_wrapper/config/ImageCfg.cpp

        ${_BASE_DIR}/sdl_wrapper/containers/Image_Handler.h
        ${_BASE_DIR}/sdl_wrapper/containers/Image_Handler.cpp

        ${_BASE_DIR}/utils/EventDefines.h
        ${_BASE_DIR}/utils/drawing/DrawParams.h
        ${_BASE_DIR}/utils/drawing/Point.h
        ${_BASE_DIR}/utils/drawing/Point.cpp
        ${_BASE_DIR}/utils/drawing/Color.h
        ${_BASE_DIR}/utils/drawing/Color.cpp
        ${_BASE_DIR}/utils/drawing/Rectangle.h
        ${_BASE_DIR}/utils/drawing/Rectangle.cpp
        ${_BASE_DIR}/utils/thread/ThreadUtils.h
        ${_BASE_DIR}/utils/thread/ThreadUtils.cpp
        ${_BASE_DIR}/utils/time_measurement/Time.h
        ${_BASE_DIR}/utils/time_measurement/Time.cpp

        ${_BASE_DIR}/engine/Engine.h
        ${_BASE_DIR}/engine/Engine.cpp

        ${_BASE_DIR}/game/Game.h
        ${_BASE_DIR}/game/Game.cpp

        ${_BASE_DIR}/main.cpp
)

set_target_cpp_standard(${PROJECT_NAME} 17)
enable_target_warnings(${PROJECT_NAME})

target_include_directories(
    ${PROJECT_NAME}
        PRIVATE 
            ${SDL2_INCLUDE_DIR}
            ${SDL2_IMAGE_INCLUDE_DIR}
            ${SDL2_TTF_INCLUDE_DIR}
            ${SDL2_MIXER_INCLUDE_DIR}
)

target_link_libraries(
    ${PROJECT_NAME}
        PRIVATE
            ${SDL2_LIBRARY}       # -lSDL2 flag
            ${SDL2_IMAGE_LIBRARY} # -lSDL2_image flag
            ${SDL2_TTF_LIBRARY}   # -lSDL2_ttf flag
            ${SDL2_MIXER_LIBRARY} # -lSDL2_mixer flag  
)
