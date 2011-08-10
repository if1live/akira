// Ŭnicode please
#include <map>
#include <string>
#include "akira/AKTestSuite.h"
#include "akira/AKStopWatch.h"
#include "akira/AKTestCase.h"

using namespace std;

namespace testing
{
	TestSuite::TestSuite()
	{

	}
	TestSuite::~TestSuite()
	{
		TestListType::iterator it = testList_.begin();
		TestListType::iterator endit = testList_.end();
		for( ; it != endit ; it++) 
		{
			delete(*it);
		}
	}
	bool TestSuite::add(Test *test)
	{
		testList_.push_back(test);
		return true;
	}

	TestSuite &TestSuite::global()
	{
		static TestSuite c;
		return c;
	}
	int TestSuite::runAllTest(const char *file)
	{
		///@TODO testList를 이름순으로 적절히 정렬하기

		StopWatch stopwatch;
		stopwatch.start();

		if(file != NULL)
		{
			LOG("Running main() from %s", file);
		}
		LOG("[==========] Running %d tests from %d test case.", testCount(), testcaseCount());
		LINE_LOG("[----------] Global test environment set-up.");

		//테스트 케이스로 등록한거 처리
		TestListType::iterator it = testList_.begin();
		TestListType::iterator endit = testList_.end();
		for( ; it != endit ; it++)
		{
			Test* test = *it;
			test->__run();
		}

		stopwatch.stop();
		int ms = stopwatch.getTimeMillisecond();

		LINE_LOG("[----------] Global test environment tear-down");

		//fail도 받아서 여기에서 보여줘야됨
		LOG("[==========] %d tests from %d test case ran. (%d ms total)", testCount(), testcaseCount(), ms);
		LOG("[  PASSED  ] %d test.", passCount());

		vector<Test*> failList = getFailList();
		if(failList.size() > 0)
		{
			LOG("[  FAILED  ] %d test, listed below:", (int)failList.size());
			vector<Test*>::iterator failIter;
			for(failIter = failList.begin() ; failIter != failList.end() ; failIter++)
			{
				Test* test = *failIter;
				LOG("[  FAILED  ] %s.%s", test->name(), test->method());
			}
		}
		return 0;
	}
	int TestSuite::passCount() const
	{
		int pass = 0;
		TestListType::const_iterator it = testList_.begin();
		TestListType::const_iterator endit = testList_.end();
		for( ; it != endit ; it++)
		{
			if((*it)->fail() == 0)
			{
				pass++;
			}
		}
		return pass;
	}
	std::vector<Test*> TestSuite::getFailList() const
	{
		vector<Test*> failList;
		TestListType::const_iterator it = testList_.begin();
		TestListType::const_iterator endit = testList_.end();
		for( ; it != endit ; it++)
		{
			if((*it)->fail() > 0)
			{
				failList.push_back(*it);
			}
		}
		return failList;
	}

	int TestSuite::testCount() const
	{
		//같은 이름인것은 세지 않는다
		int num = 0;
		string prevName;
		TestListType::const_iterator it = testList_.begin();
		TestListType::const_iterator endit = testList_.end();
		for( ; it != endit ; it++)
		{
			string currName((*it)->name());
			if(prevName != currName)
			{
				num++;
			}
			prevName = currName;
		}
		return num;
	}

	int TestSuite::testcaseCount() const
	{
		return testList_.size();
	}
}