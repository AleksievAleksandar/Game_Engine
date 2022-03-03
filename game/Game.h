#ifndef GAME_H
#define GAME_H

#include "../utils/drawing/DrawParams.h"
#include "../utils/drawing/Rectangle.h"

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
	std::vector<int32_t> imagesForDrawingByRcrsId() const;

private:
	DrawParams _layer_2_image;
	DrawParams _press_keys_image;
	DrawParams _text;
};

#endif // !GAME_H

