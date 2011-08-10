// Ŭnicode please
#pragma once

#include "akira/AKTestMacro.h"
#include <cstdlib>
#include <string>

namespace testing
{
	class TestSuite;
	class Test;
	class FunctionTestCase;

	class Test {
	public:
		Test() : passCount_(0), failCount_(0) {}
		Test(const char *name, const char *method) : name_(name), method_(method), passCount_(0), failCount_(0) {}
		virtual ~Test() {}
		virtual void __run();

		const char *name() const { return name_.c_str(); }
		const char *method() const { return method_.c_str(); }

		int pass() const { return passCount_; }
		int fail() const { return failCount_; }

	protected:
		virtual void SetUp() {}
		virtual void TearDown() {}

		virtual void __test() {}

		std::string name_;
		std::string method_;
		int passCount_;
		int failCount_;
	};

	///@brief impl TEST(A, B) macro
	class FunctionTestCase : public Test {
	public:
		FunctionTestCase(const std::string &testcase, const std::string &testmethod, void (*func)());
		FunctionTestCase(const char *testcase, const char *testmethod, void (*func)());
		virtual ~FunctionTestCase();
		virtual void __run();
	private:
		void (*func_)();
	};
}

//template method impl
#include "AKTestCase.hpp"