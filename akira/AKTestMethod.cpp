// Ŭnicode please

#include "akira/AKTestMacro.h"
#include "akira/AKTestMethod.h"

namespace testing
{
	void showFailMsg(const char *expected, const char *actual, const char *file, int line)
	{
		// ..\user_sqrt.cpp (6854): error: Value of: sqrt (2533.310224)
		//Actual: 50.332
		//Expected: 50.3321
		LOG("%s (%d) error", file, line);
		LOG("Expected: %s", expected);
		LOG("Actual: %s", actual);
	}

	bool isEquals(const char* a, const char *b, const char *file, int line)
	{
		bool result = false;
		if(a == NULL && b != NULL)
		{
			result = false;
		}
		else if(a != NULL && b == NULL)
		{
			result = false;
		}
		else if(a == NULL && b == NULL)
		{
			result = true;
		}
		else
		{
			//a, b둘가 문자열인 경우
			std::string expected(a);
			std::string actual(b);
			if(expected == actual)
				result = true;
			else
				result = false;
		}

		if(result == true)
		{
			//LOG("[ PASSED ] %s.%s", test, method);
			return true;
		}
		else
		{
			std::string expected;
			std::string actual;
			if(a == NULL)
				expected = "NULL";
			else
				expected = a;

			if(b == NULL)
				actual = "NULL";
			else
				actual = b;

			showFailMsg(expected.c_str(), actual.c_str(), file, line);
			return false;
		}

	}
}
