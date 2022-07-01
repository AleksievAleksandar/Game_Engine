#include "manager_utils/MgrHandler.h"

#include "manager_utils/DrawMgr.h"
#include "manager_utils/RsrcMgr.h"

#include <iostream>

int32_t MgrHandler::init()
{
	gDrawMgr = new DrawMgr();
	if (nullptr == gDrawMgr)
	{
		std::cerr << "ERROR -> Failed for memory alloc for gDrawMgr. " << std::endl;
		return EXIT_FAILURE;
	}
	if (EXIT_SUCCESS != gDrawMgr->init())
	{
		std::cerr << "ERROR -> gDrawMgr->init()" << std::endl;
		return EXIT_FAILURE;
	}

	gRsrcMgr = new RsrcMgr();
	if (nullptr == gRsrcMgr)
	{
		std::cerr << "ERROR -> Failed for memory alloc for gRsrcMgr. " << std::endl;
		return EXIT_FAILURE;
	}
	if (EXIT_SUCCESS != gRsrcMgr->init())
	{
		std::cerr << "ERROR -> gRsrcMgr->init()" << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

void MgrHandler::deinit()
{
	gRsrcMgr->deinit();
	delete gRsrcMgr;
	gRsrcMgr = nullptr;

	gDrawMgr->deinit();
	delete gDrawMgr;
	gDrawMgr = nullptr;
}
