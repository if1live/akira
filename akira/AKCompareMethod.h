// Ŭnicode please 
#pragma once

#include <string>

namespace testing
{
	//template version equal
	template<typename T1, typename T2>
	bool isEqual(const T1 &a, const T2 &b);
	template<typename T>
	bool isEqual(const T &a, const T &b);

	//lt
	template<typename T>
	bool isLessThan(const T &a, const T &b);

	//le
	template<typename T>
	bool isLessEqual(const T &a, const T &b);

	//gt
	template<typename T>
	bool isGreaterThan(const T &a, const T &b);

	//ge
	template<typename T>
	bool isGreaterEqual(const T &a, const T &b);

	bool isEqualString(const char *a, const char *b, bool ignoreCase);
	bool isEqualString(const std::string &a, const std::string &b, bool ignoreCase);

	//부동소수점 오차 고려해서 비교
	template<typename T>
	bool isAbsErrorEqual(T a, T b, T absError);
	template<typename T>
	bool isRelErrorEqual(T a, T b, T relError);
}
#include "akira/AKCompareMethod.hpp"