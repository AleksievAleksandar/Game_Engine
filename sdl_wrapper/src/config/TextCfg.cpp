#include "sdl_wrapper/config/TextCfg.h"

#include "../../common_defines/Common_Defines.h"

std::vector<std::pair<std::string, int32_t> > TextCfg::getFontsPaths()
{
	std::vector<std::pair<std::string, int32_t> > paths;
	paths.push_back(std::make_pair("../resources/fonts/Yagora.ttf", Fonts::Size::YAGORA_FONT_SIZE_36));
	paths.push_back(std::make_pair("../resources/fonts/AngelineVintage.ttf", Fonts::Size::ANGELIN_VINTAGE_FONT_SIZE_36));

	return paths;
}
