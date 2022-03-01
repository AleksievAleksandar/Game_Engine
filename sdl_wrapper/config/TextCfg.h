#ifndef TEXT_CFG_H
#define TEXT_CFG_H

#include <string>
#include <vector>

struct TextCfg
{
	static std::vector<std::string> getTextPaths();
	static int32_t getTextSize();
};

#endif // !TEXT_CFG_H

