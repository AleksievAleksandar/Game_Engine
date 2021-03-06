#ifndef RSRC_MGR
#define RSRC_MGR

#include "sdl_wrapper/containers/Image_Handler.h"
#include "sdl_wrapper/containers/Text_Handler.h"

#include <string>

//Forward Declarations
struct DrawParams;

using Frames = std::vector<Rectangle>;

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

	std::unordered_map<int32_t, Frames> getImageDimensions() const;

	void getTextureForDrawing(SDL_Texture*& outTexture, const DrawParams& drawParams);

private:
	Image_Handler _imageHandler;
	Text_Handler _textHandler;
};

extern RsrcMgr* gRsrcMgr;

#endif // !RSRC_MGR

