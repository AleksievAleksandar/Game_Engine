#include "utils/time_measurement/Time.h"

Time& Time::getElapsed()
{
	this->_elapsedLastCall = this->_now;
	this->_now = std::chrono::steady_clock::now();

	return *this;
}

int64_t Time::toSeconds() const
{
	return std::chrono::duration_cast<std::chrono::seconds>(this->_now - this->_elapsedLastCall).count();
}

int64_t Time::toMilliseconds() const
{
	return std::chrono::duration_cast<std::chrono::milliseconds>(this->_now - this->_elapsedLastCall).count();
}

int64_t Time::toMicroseconds() const
{
	return std::chrono::duration_cast<std::chrono::microseconds>(this->_now - this->_elapsedLastCall).count();
}

int64_t Time::toNanoseconds() const
{
	return std::chrono::duration_cast<std::chrono::nanoseconds>(this->_now - this->_elapsedLastCall).count();
}
