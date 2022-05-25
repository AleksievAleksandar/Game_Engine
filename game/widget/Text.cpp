#include "game/widget/Text.h"

#include "manager_utils/RsrcMgr.h"

#include <iostream>

int32_t Text::create(const std::string& text, const Fonts::FontType& fontType, const Color& color, const Point& position)
{
	if (this->_createForTheFirstTime)
	{
		this->_drawParams.widgetType = WidgetType::TEXT;
		this->_drawParams.rsrcId = fontType;
		this->_drawParams.pos = position;
		this->_color = color;

		gRsrcMgr->createText(text, fontType, color, this->_drawParams.w, this->_drawParams.h);
		this->_createForTheFirstTime = false;

		return EXIT_SUCCESS;
	}

	return EXIT_FAILURE;
}

void Text::reloadContent(const std::string& newText)
{
	if (!this->_createForTheFirstTime)
	{
		gRsrcMgr->reloadText(newText, this->_drawParams.rsrcId, this->_color, this->_drawParams.w, this->_drawParams.h);
	}
}

void Text::setTextWidth(int32_t wParam)
{
	this->_drawParams.w = wParam;
}

void Text::setTextHeight(int32_t hParam)
{
	this->_drawParams.h = hParam;
}
