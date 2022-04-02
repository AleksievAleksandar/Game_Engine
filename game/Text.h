#ifndef TEXT_H
#define TEXT_H

#include "game/Widget.h"
#include "../common_defines/Common_Defines.h"

#include <cstdint>
#include <string>

class Text : public Widget
{
public:
	int32_t create(const Fonts::FontType& fontType);
	void draw() const override;

	void createContent(const std::string& text);
	void setTextWidth(int32_t wParam);
	void setTextHeight(int32_t hParam);
};

#endif // !TEXT_H

