#include "manager_utils/RsrcMgr.h"

#include <iostream>
#include <cstdint>

RsrcMgr* gRsrcMgr = nullptr;

int32_t RsrcMgr::init()
{
	if (EXIT_SUCCESS != this->_imageHandler.loadRsrc())
	{
		std::cerr << "ERROR -> _imageHandler.loadRsrc()" << std::endl;
		return EXIT_FAILURE;
	}

	if (EXIT_SUCCESS != this->_textHandler.loadRsrc())
	{
		std::cerr << "ERROR -> _textHandler.loadRsrc()" << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_FAILURE;
}

void RsrcMgr::deinit()
{
	this->_textHandler.deinit();
	this->_imageHandler.deinit();
}
