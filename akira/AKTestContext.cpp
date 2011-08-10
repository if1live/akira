// Ŭnicode please

#include "akira/AKTestContext.h"
#include "akira/AKTestMacro.h"

using namespace std;

namespace testing
{
	void TestContext::setTest(const char *testcase, const char *method)
	{
		testcase_ = testcase;
		testmethod_ = method;
		failCnt_ = 0;
		successCnt_ = 0;
	}
	int TestContext::failCount() const
	{
		return failCnt_;
	}
	int TestContext::successCount() const
	{
		return successCnt_;
	}
	const std::string &TestContext::getTestCase() const 
	{
		return testcase_;
	}
	const std::string &TestContext::getTestMethod() const 
	{ 
		return testmethod_;
	}

	TestContext &TestContext::getInstance() { static TestContext ctx; return ctx; }

	TestContext::TestContext() {}
	TestContext::~TestContext() {}
	
	bool TestContext::isTestSuccess() const
	{
		return (failCnt_ == 0);
	}

	void TestContext::showFailMsg(const std::string &expected, const std::string &actual, const char *file, int line)
	{
		// ..\user_sqrt.cpp (6854): error: Value of: sqrt (2533.310224)
		//Actual: 50.332
		//Expected: 50.3321
		LOG("%s (%d) error", file, line);
		LOG("Expected: %s", expected.c_str());
		LOG("Actual: %s", actual.c_str());
	}
	void TestContext::expectStrEq(const char *expected, const char *actual, bool ignoreCase, const char *file, int line, bool enableAssert)
	{
		if(isEqualString(expected, actual, ignoreCase) == false)
		{
			showFailMsg(string(expected), string(actual), file, line);
			failCnt_++;
		}
		else
		{
			successCnt_++;
		}
	}
	void TestContext::expectStrNotEq(const char *expected, const char *actual, bool ignoreCase, const char *file, int line, bool enableAssert)
	{
		if(isEqualString(expected, actual, ignoreCase) == true)
		{
			failOccur(expected, actual, file, line, enableAssert);
		}
		else
		{
			successCnt_++;
		}
	}
	
	void TestContext::expectFloatEq(float expected, float actual, const char *file, int line, bool enableAssert)
	{
		if(isRelErrorEqual(expected, actual, 0.001f))
		{
			successCnt_++;
		}
		else
		{
			failOccur(expected, actual, file, line, enableAssert);
		}
	}
	void TestContext::expectDoubleEq(double expected, double actual, const char *file, int line, bool enableAssert)
	{
		if(isRelErrorEqual(expected, actual, 0.001))
		{
			successCnt_++;
		}
		else
		{
			failOccur(expected, actual, file, line, enableAssert);
		}
	}
}