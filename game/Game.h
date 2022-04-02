#ifndef GAME_H
#define GAME_H

#include "utils/drawing/DrawParams.h"
#include "utils/drawing/Rectangle.h"
#include "game/Image.h"

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

	DrawParams _text;

private:
	Image _layer_2;
	Image _press_keys;
};

#endif // !GAME_H

