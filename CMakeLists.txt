﻿cmake_minimum_required(VERSION 3.10.2)

project(GameEngine 
        VERSION 0.0.1
        DESCRIPTION "Game Engine"
        LANGUAGES CXX)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake_helpers/helpers.cmake)

set(CMAKE_MODULE_PATH 
    ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake_helpers/find_modules)

set(_BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

message("base dir is: " ${_BASE_DIR})

#generate project binary
add_executable(
    ${PROJECT_NAME}  
        ${_BASE_DIR}/common_defines/Common_Defines.h

        ${_BASE_DIR}/engine/Engine.h
        ${_BASE_DIR}/engine/Engine.cpp

        ${_BASE_DIR}/game/Game.h
        ${_BASE_DIR}/game/Game.cpp
        ${_BASE_DIR}/game/widget/Widget.h
        ${_BASE_DIR}/game/widget/Widget.cpp
        ${_BASE_DIR}/game/widget/Image.h
        ${_BASE_DIR}/game/widget/Image.cpp
        ${_BASE_DIR}/game/widget/Text.h
        ${_BASE_DIR}/game/widget/Text.cpp
        ${_BASE_DIR}/game/widget/Hero.h
        ${_BASE_DIR}/game/widget/Hero.cpp

        ${_BASE_DIR}/manager_utils/DrawMgr.h
        ${_BASE_DIR}/manager_utils/DrawMgr.cpp
        ${_BASE_DIR}/manager_utils/RsrcMgr.h
        ${_BASE_DIR}/manager_utils/RsrcMgr.cpp
        ${_BASE_DIR}/manager_utils/MgrHandler.h
        ${_BASE_DIR}/manager_utils/MgrHandler.cpp

        ${_BASE_DIR}/main.cpp
)

set_target_cpp_standard(${PROJECT_NAME} 17)
enable_target_warnings(${PROJECT_NAME})

target_include_directories(
    ${PROJECT_NAME}
        PRIVATE 
            ${_BASE_DIR}
)

target_link_libraries(
    ${PROJECT_NAME}
        PRIVATE
            sdl_wrapper
)

add_subdirectory(utils)
add_subdirectory(sdl_wrapper)

