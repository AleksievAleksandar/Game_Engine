#ifndef MGR_HANDLER_H
#define MGR_HANDLER_H

#include <cstdint>

class MgrHandler
{
public:
	MgrHandler() = default;

	//forbid the copy and move constructors
	MgrHandler(const MgrHandler& other) = delete;
	MgrHandler(MgrHandler&& other) = delete;

	//forbid the copy and move assignment operators
	MgrHandler& operator=(const MgrHandler& other) = delete;
	MgrHandler& operator=(MgrHandler&& other) = delete;

	int32_t init();
	void deinit();
};

#endif // !MGR_HANDLER_H

