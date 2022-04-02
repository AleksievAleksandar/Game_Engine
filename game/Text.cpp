#include "Text.h"

#include <iostream>

int32_t Text::create(const Fonts::FontType& fontType)
{
	this->_drawParams.widgetType = WidgetType::TEXT;
	//this->_drawParams.rsrcId = fontType;
	this->_drawParams.rsrcId = fontType;
	this->_drawParams.pos = Point::ZERO;

	return EXIT_SUCCESS;
}

void Text::draw() const
{
	//TODO
}

void Text::setTextWidth(int32_t wParam)
{
	this->_drawParams.w = wParam;
}

void Text::setTextHeight(int32_t hParam)
{
	this->_drawParams.h = hParam;
}
