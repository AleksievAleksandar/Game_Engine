#ifndef THREAD_UTILS_H
#define THREAD_UTILS_H

#include <cstdint>

class ThreadUtil
{
public:
	ThreadUtil() = delete;
	static void sleepFor(int64_t microseconds);
};

#endif // !THREAD_UTILS_H

