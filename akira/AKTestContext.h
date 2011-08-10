// Ŭnicode please
#pragma once

#include "akira/AKCompareMethod.h"
#include "akira/AKValueType.h"
#include <cassert>

namespace testing
{
	class TestContext {
	public:
		const std::string &getTestCase() const;
		const std::string &getTestMethod() const;
		//새로운 테스트를 시작하기 위한 정보를 등록할떄 사용i
		void setTest(const char *testcase, const char *method);	
		static TestContext &getInstance();

		int failCount() const;
		int successCount() const;

		//macro function interface
		template<typename T1, typename T2>
		void expectEq(const T1 &expected, const T2 &actual, const char *file, int line, bool enableAssert);
	
		void expectStrEq(const char *expected, const char *actual, bool ignoreCase, const char *file, int line, bool enableAssert);
		void expectStrNotEq(const char *expected, const char *actual, bool ignoreCase, const char *file, int line, bool enableAssert);

		template<typename T1, typename T2>
		void expectNotEq(const T1 &expected, const T2 &actual, const char *file, int line, bool enableAssert);

		template<typename T>
		void expectLessThan(const T &expected, const T &actual, const char *file, int line, bool enableAssert);
		template<typename T>
		void expectLessEqual(const T &expected, const T &actual, const char *file, int line, bool enableAssert);
		template<typename T>
		void expectGreaterThan(const T &expected, const T &actual, const char *file, int line, bool enableAssert);
		template<typename T>
		void expectGreaterEqual(const T &expected, const T &actual, const char *file, int line, bool enableAssert);

		template<typename T, typename Comparator>
		void expectComparator(const T &expected, const T &actual, const Comparator &comp, const char *file, int line, bool enableAssert);

		void expectFloatEq(float expected, float actual, const char *file, int line, bool enableAssert);
		void expectDoubleEq(double expected, double actual, const char *file, int line, bool enableAssert);
		template<typename T>
		void expectNearEq(T expected, T actual, T absError, const char *file, int line, bool enableAssert);

		bool isTestSuccess() const;

		void showFailMsg(const std::string &expected, const std::string &actual, const char *file, int line);

		template<typename T1, typename T2>
		void failOccur(const T1 &expected, const T2 &actual, const char *file, int line, bool enableAssert);
	private:
		TestContext();
		~TestContext();

		std::string testcase_;
		std::string testmethod_;
		int failCnt_;
		int successCnt_;
	};
}
//template impl
namespace testing
{
	template<typename T1, typename T2>
	void TestContext::expectEq(const T1 &expected, const T2 &actual, const char *file, int line, bool enableAssert)
	{
		bool result = isEqual(expected, actual);
		if(result == false)	
		{
			failOccur(expected, actual, file, line, enableAssert);
		}
		else
		{
			successCnt_++;
		}
	}
	template<typename T1, typename T2>
	void TestContext::expectNotEq(const T1 &expected, const T2 &actual, const char *file, int line, bool enableAssert)
	{
		bool result = isEqual(expected, actual);
		if(result == true)	
		{
			failOccur(expected, actual, file, line, enableAssert);
		}
		else
		{
			successCnt_++;
		}
	}
	template<typename T>
	void TestContext::expectLessThan(const T &expected, const T &actual, const char *file, int line, bool enableAssert)
	{
		static std::less<T> functor;
		expectComparator(expected, actual, functor, file, line);
	}
	template<typename T>
	void TestContext::expectLessEqual(const T &expected, const T &actual, const char *file, int line, bool enableAssert)
	{
		static std::less_equal<T> functor;
		expectComparator(expected, actual, functor, file, line);
	}
	template<typename T>
	void TestContext::expectGreaterThan(const T &expected, const T &actual, const char *file, int line, bool enableAssert)
	{
		static std::greater<T> functor;
		expectComparator(expected, actual, functor, file, line);
	}
	template<typename T>
	void TestContext::expectGreaterEqual(const T &expected, const T &actual, const char *file, int line, bool enableAssert)
	{
		static std::greater_equal<T> functor;
		expectComparator(expected, actual, functor, file, line);
	}
	template<typename T, typename Comparator>
	void TestContext::expectComparator(const T &expected, const T &actual, const Comparator &comp, const char *file, int line, bool enableAssert)
	{
		if(comp(expected, actual))
		{
			successCnt_++;
		}
		else
		{
			failOccur(expected, actual, file, line, enableAssert);
		}
	}
	template<typename T>
	void TestContext::expectNearEq(T expected, T actual, T absError, const char *file, int line, bool enableAssert)
	{
		if(isAbsErrorEqual(expected, actual, absError))
		{
			successCnt_++;
		}
		else
		{
			failOccur(expected, actual, file, line, enableAssert);
		}
	}
	//////////////////////////////////
	template<typename T1, typename T2>
	void TestContext::failOccur(const T1 &expected, const T2 &actual, const char *file, int line, bool enableAssert)
	{
		std::string str1 = toString(expected);
		std::string str2 = toString(actual);
		showFailMsg(str1, str2, file, line);
		failCnt_++;

		if(enableAssert)
		{
			assert(false);
		}
	}
}