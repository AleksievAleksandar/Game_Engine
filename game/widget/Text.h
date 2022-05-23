#ifndef TEXT_H
#define TEXT_H

#include "game/widget/Widget.h"
#include "utils/drawing/Color.h"
#include "../../common_defines/Common_Defines.h"

#include <cstdint>
#include <string>

class Text : public Widget
{
public:
	int32_t create(const std::string& text, const Fonts::FontType& fontType = Fonts::YAGORA_FONT, const Color& color = Colors::GREEN);
	void draw() const override;

	void reloadContent(const std::string& newText);
	void setTextWidth(int32_t wParam);
	void setTextHeight(int32_t hParam);

private:
	bool _firstTimeCreateContent = true;
	Color _color = Colors::GREEN;
};

#endif // !TEXT_H

