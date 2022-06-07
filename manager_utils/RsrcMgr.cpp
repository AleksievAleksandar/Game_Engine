#include "manager_utils/RsrcMgr.h"

#include <iostream>
#include <cstdint>

#include "utils/drawing/Color.h"
#include "../common_defines/Common_Defines.h"

RsrcMgr* gRsrcMgr = nullptr;

int32_t RsrcMgr::init()
{
	if (EXIT_SUCCESS != this->_imageHandler.loadRsrc())
	{
		std::cerr << "ERROR -> _imageHandler.loadRsrc()" << std::endl;
		return EXIT_FAILURE;
	}

	if (EXIT_SUCCESS != this->_textHandler.loadRsrc())
	{
		std::cerr << "ERROR -> _textHandler.loadRsrc()" << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_FAILURE;
}

void RsrcMgr::deinit()
{
	this->_textHandler.deinit();
	this->_imageHandler.deinit();
}

void RsrcMgr::createText(const std::string& text, const int32_t fontTypeId, const Color& color, int32_t& outTextWidth, int32_t& outTextHeight)
{
	this->_textHandler.createText(fontTypeId, text, color, outTextWidth, outTextHeight);
}

void RsrcMgr::reloadText(const std::string& text, const int32_t fontTypeId, const Color& color, int32_t& outTextWidth, int32_t& outTextHeight)
{
	this->_textHandler.reloadText(fontTypeId, text, color, outTextWidth, outTextHeight);
}

std::unordered_map<int32_t, Frames> RsrcMgr::getImageDimensions() const
{
	return this->_imageHandler.getTexturesDimensions();
}

void RsrcMgr::collectImageForDrawing(SDL_Texture*& outCollection, const DrawParams& drawParams)
{
	outCollection = nullptr;

	switch (drawParams.widgetType)
	{
	case WidgetType::IMAGE:
		this->_imageHandler.collectSingleTextureForDrawing(outCollection, drawParams);
		break;

	case WidgetType::TEXT:
		this->_textHandler.collectSingleTextureForDrawing(outCollection, drawParams);
		break;

	case WidgetType::UNKNOWN:
		std::cerr << "ERROR-> trying to collect UNKNOWN WidgetType with RsrcMgr::collectImageForDrawing()" << std::endl;
		break;

	default:
		std::cerr << "ERROR-> trying to collect unsupported WidgetType: " 
			      << static_cast<uint8_t>(drawParams.widgetType) 
			      << " with RsrcMgr::collectImageForDrawing()" << std::endl;
		break;
	}	
}
