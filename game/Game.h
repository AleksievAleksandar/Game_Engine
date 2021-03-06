#ifndef GAME_H
#define GAME_H

#include "utils/drawing/DrawParams.h"
#include "utils/drawing/Rectangle.h"
#include "game/widget/Hero.h"
#include "game/widget/Text.h"

#include <cstdint>
#include <unordered_map>
#include <vector>

//Forword Declarations
struct InputEvent;

using Frames = std::vector<Rectangle>;

class Game
{
public:
	int32_t init();
	void deinit();
	bool handleEvent(InputEvent& event);

	void draw() const;

private:
	Image _layer_2;
	Image _press_keys;

	Hero _running_girl;

	Text _text;
	Text _secondText;
};

#endif // !GAME_H

