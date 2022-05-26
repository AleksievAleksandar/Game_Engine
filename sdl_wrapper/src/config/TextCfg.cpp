#include "sdl_wrapper/config/TextCfg.h"

namespace 
{
	constexpr auto YAGORA_FONT_LOCATION = "../resources/fonts/Yagora.ttf";
	constexpr auto ANGELINE_VINTAGE_FONT_LOCATION = "../resources/fonts/AngelineVintage.ttf";
}

namespace 
{
	constexpr auto YAGORA_FONT_SIZE_36 = 36;
	constexpr auto ANGELIN_VINTAGE_FONT_SIZE_36 = 36;
}

std::vector<std::pair<std::string, int32_t> > TextCfg::getFontsPaths()
{
	std::vector<std::pair<std::string, int32_t> > paths;
	paths.push_back(std::make_pair(YAGORA_FONT_LOCATION, YAGORA_FONT_SIZE_36));
	paths.push_back(std::make_pair(ANGELINE_VINTAGE_FONT_LOCATION, ANGELIN_VINTAGE_FONT_SIZE_36));

	return paths;
}
