// Ŭnicode please
#pragma once

#include <list>
#include <vector>
#include <string>

namespace testing
{
	class Test;

	//테스트 메소드가 등록되는 클래스
	class TestSuite {
	public:
		typedef std::list<Test*> TestListType;
	public:
		bool add(Test *test);
		static TestSuite &global();
		int runAllTest(const char *file);

	protected:
		TestSuite();
		~TestSuite();

		int testCount() const;
		int testcaseCount() const;

		int passCount() const;
		std::vector<Test*> getFailList() const;

		TestListType testList_;
	};
}