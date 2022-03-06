#include "TextCfg.h"

namespace
{
	int32_t ANGELIN_VINTAGE_FONT_SIZE_40 = 40;
}

std::vector<std::pair<std::string, int32_t> > TextCfg::getTextPaths()
{
	std::vector<std::pair<std::string, int32_t> > paths;
	paths.push_back(std::make_pair("../resources/fonts/AngelineVintage.ttf", ANGELIN_VINTAGE_FONT_SIZE_40));

	return paths;
}
