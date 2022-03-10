#ifndef TEXT_CFG_H
#define TEXT_CFG_H

#include <string>
#include <vector>

struct TextCfg
{
	static std::vector<std::pair<std::string, int32_t> > getFontsPaths();
};

#endif // !TEXT_CFG_H

