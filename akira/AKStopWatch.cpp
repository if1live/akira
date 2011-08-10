// Ŭnicode please 

#include "akira/AKStopWatch.h"

namespace testing
{
	StopWatch::StopWatch()
		: startTime_(0), endTime_(0)
	{
	}
	StopWatch::~StopWatch()
	{
	}
	void StopWatch::start()
	{
		startTime_ = clock();
		endTime_ = startTime_;
	}
	void StopWatch::stop()
	{
		endTime_ = clock();
	}
	float StopWatch::getTimeSecond() const
	{
		int ms = getTimeMillisecond();
		return ms / 1000.0f;
	}
	int StopWatch::getTimeMillisecond() const
	{
		//in window, clocks_per_sec=1000
		int ms = (endTime_ - startTime_) / CLOCKS_PER_SEC * 1000;
		return ms;
	}
}