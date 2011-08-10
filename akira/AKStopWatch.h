// Ŭnicode please 
#pragma once

#include <ctime>

namespace testing
{
	class StopWatch {
	public:
		StopWatch();
		~StopWatch();
		void start();
		void stop();
		float getTimeSecond() const;
		int getTimeMillisecond() const;
	private:
		clock_t startTime_;
		clock_t endTime_;
	};
}