// Ŭnicode please
#include <vector>
#include <map>

#include "akira/AKTestCase.h"
#include "akira/AKTestMethod.h"
#include "akira/AKStopWatch.h"
#include "akira/AKTestMacro.h"
#include "akira/AKTestContext.h"

using namespace std;

namespace testing
{
	FunctionTestCase::FunctionTestCase(const std::string &testcase, const std::string &testmethod, void (*func)())
		: Test(testcase.c_str(), testmethod.c_str()), func_(func)
	{
	}
	FunctionTestCase::FunctionTestCase(const char *testcase, const char *testmethod, void (*func)())
		: Test(testcase, testmethod), func_(func)
	{
	}
	FunctionTestCase::~FunctionTestCase()
	{
	}
	void FunctionTestCase::__run()
	{
		//start...
		LOG("[ RUN      ] %s.%s", name(), method());

		//run test...
		StopWatch stopwatch;
		stopwatch.start();

		TestContext &ctx = TestContext::getInstance();
		ctx.setTest(name(), method());
		func_();

		stopwatch.stop();
		int ms = stopwatch.getTimeMillisecond();

		//end...
		if(ctx.isTestSuccess())
		{
			LOG("[       OK ] %s.%s (%d ms)", name(), method(), ms);
			passCount_ = 1;
			failCount_ = 0;
		}
		else
		{
			LOG("[  FAILED  ] %s.%s (%d ms)", name(), method(), ms);
			passCount_ = 0;
			failCount_ = 1;
		}
	}
	

	void Test::__run()
	{
		LOG("[ RUN      ] %s.%s", name(), method());
		SetUp();

		TestContext &ctx = TestContext::getInstance();
		ctx.setTest(name(), method());

		StopWatch stopwatch;
		stopwatch.start();
		__test();
		stopwatch.stop();
		int ms = stopwatch.getTimeMillisecond();

		passCount_ = ctx.successCount();
		failCount_ = ctx.failCount();

		if(fail() == 0)
		{
			LOG("[       OK ] %s.%s (%d ms)", name(), method(), ms);
		}
		else
		{
			LOG("[  FAILED  ] %s.%s (%d ms)", name(), method(), ms);
		}

		TearDown();
	}
}
