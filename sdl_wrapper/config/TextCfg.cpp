#include "TextCfg.h"

namespace
{
	int32_t ANGELIN_VINTAGE_FONT_SIZE_40 = 40;
}

std::vector<std::string> TextCfg::getTextPaths()
{
	std::vector<std::string> paths;
	paths.push_back("../resources/fonts/AngelineVintage.ttf");

	return paths;
}

int32_t TextCfg::getTextSize()
{
	return ANGELIN_VINTAGE_FONT_SIZE_40;
}
