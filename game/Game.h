#ifndef GAME_H
#define GAME_H

#include "utils/drawing/DrawParams.h"
#include "utils/drawing/Rectangle.h"
#include "game/widget/Image.h"
#include "game/widget/Text.h"

#include <cstdint>
#include <unordered_map>
#include <vector>

//Forword Declarations
struct InputEvent;

class Game
{
public:
	int32_t init(const std::unordered_map<int32_t, Rectangle>& _textureDimensions);
	void deinit();
	bool handleEvent(InputEvent& event);
	std::vector<DrawParams> imagesForDrawing() const;
	void setTextDimmensions(const int32_t param_w, const int32_t param_h);

private:
	Image _layer_2;
	Image _press_keys;
	Text _text;
	Text _secondText;
};

#endif // !GAME_H

