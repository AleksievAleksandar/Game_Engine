#ifndef TEXT_H
#define TEXT_H

#include "game/widget/Widget.h"
#include "../../common_defines/Common_Defines.h"

#include <cstdint>
#include <string>

class Text : public Widget
{
public:
	int32_t create(const Fonts::FontType& fontType);
	void draw() const override;

	void createContent(const std::string& text);
	void reloadContent(const std::string& newText);
	void setTextWidth(int32_t wParam);
	void setTextHeight(int32_t hParam);

private:
	bool firstTimeCreateContent = true;
};

#endif // !TEXT_H

