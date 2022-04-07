#include "game/widget/Text.h"

#include "manager_utils/RsrcMgr.h"

#include <iostream>

int32_t Text::create(const Fonts::FontType& fontType)
{
	this->_drawParams.widgetType = WidgetType::TEXT;
	this->_drawParams.rsrcId = fontType;
	this->_drawParams.pos = Point::ZERO;

	return EXIT_SUCCESS;
}

void Text::draw() const
{
	//TODO
}

void Text::createContent(const std::string& text)
{
	if (this->firstTimeCreateContent)
	{
		gRsrcMgr->createText(text, this->_drawParams.w, this->_drawParams.h);
		this->firstTimeCreateContent = false;
	}
}

void Text::reloadContent(const std::string& newText)
{
	if (!this->firstTimeCreateContent)
	{
		gRsrcMgr->reloadText(newText, this->_drawParams.w, this->_drawParams.h);
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
