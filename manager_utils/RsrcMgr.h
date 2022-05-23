#ifndef RSRC_MGR
#define RSRC_MGR

#include "sdl_wrapper/containers/Image_Handler.h"
#include "sdl_wrapper/containers/Text_Handler.h"

#include <string>

class RsrcMgr
{
public:
	RsrcMgr() = default;

	//forbid the copy and move constructors
	RsrcMgr(const RsrcMgr& other) = delete;
	RsrcMgr(RsrcMgr&& other) = delete;

	//forbid the copy and move assignment operators
	RsrcMgr& operator=(const RsrcMgr& other) = delete;
	RsrcMgr& operator=(RsrcMgr&& other) = delete;

	int32_t init();
	void deinit();

	void createText(const std::string& text, const int32_t fontTypeId, const Color& color, int32_t& outTextWidth, int32_t& outTextHeight);
	void reloadText(const std::string& text, const int32_t fontTypeId, const Color& color, int32_t& outTextWidth, int32_t& outTextHeight);
	void collectImagesForDrawing(std::vector<SDL_Texture*>& outCollection, const std::vector<DrawParams>& drawParams);
	void collectTextsForDrawing(std::vector<SDL_Texture*>& outCollection, const std::vector<DrawParams>& drawParams);
	std::unordered_map<int32_t, Rectangle> getImageDimensions();

private:
	Image_Handler _imageHandler;
	Text_Handler _textHandler;
};

extern RsrcMgr* gRsrcMgr;

#endif // !RSRC_MGR

