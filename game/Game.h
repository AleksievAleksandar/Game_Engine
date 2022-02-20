#ifndef GAME_H
#define GAME_H

#include "../utils/drawing/DrawParams.h"
#include "../utils/drawing/Rectangle.h"

#include <cstdint>
#include <unordered_map>
#include <vector>

class Game
{
public:
	int32_t init(const std::unordered_map<int32_t, Rectangle>& _textureDimensions);
	void deinit();
	std::vector<int32_t> imagesForDrawing() const;

private:
	DrawParams _layer_2_image;
	DrawParams _press_keys_image;
};

#endif // !GAME_H
