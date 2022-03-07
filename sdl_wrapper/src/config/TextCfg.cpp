#include "sdl_wrapper/config/TextCfg.h"

namespace
{
	int32_t ANGELIN_VINTAGE_FONT_SIZE_36 = 36;
	int32_t YAGORA_FONT_SIZE_36 = 36;
}

std::vector<std::pair<std::string, int32_t> > TextCfg::getTextPaths()
{
	std::vector<std::pair<std::string, int32_t> > paths;
	paths.push_back(std::make_pair("../resources/fonts/AngelineVintage.ttf", ANGELIN_VINTAGE_FONT_SIZE_36));
	paths.push_back(std::make_pair("../resources/fonts/Yagora.ttf", YAGORA_FONT_SIZE_36));

	return paths;
}
