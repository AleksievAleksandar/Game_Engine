#ifndef RSRC_MGR
#define RSRC_MGR

#include "sdl_wrapper/containers/Image_Handler.h"
#include "sdl_wrapper/containers/Text_Handler.h"

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
private:
	Image_Handler _imageHandler;
	Text_Handler _textHandler;
};

extern RsrcMgr* gRsrcMgr;

#endif // !RSRC_MGR

