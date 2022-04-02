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

	void createText(const std::string& text, int32_t& outTextWidth, int32_t& outTextHeight);
	std::unordered_map<int32_t, Rectangle> getImageDimensions();
	void collectImagesForDrawing(std::vector<SDL_Texture*>& outCollection, const std::vector<DrawParams>& drawParams);
	void collectTextsForDrawing(std::vector<SDL_Texture*>& outCollection, const std::vector<DrawParams>& drawParams);

private:
	Image_Handler _imageHandler;
	Text_Handler _textHandler;
};

extern RsrcMgr* gRsrcMgr;

#endif // !RSRC_MGR

