// Ŭnicode please
#pragma once

#include <memory>
#include <sstream>
//#if _IPHONE_
//#include <tr1/memory>
//#endif

namespace testing
{
	template<typename T>
	std::string toString(T *a)
	{
		std::ostringstream oss;
		oss << a;
		return oss.str();
	}

	template<typename T>
	std::string toString(std::auto_ptr<T> a)
	{
		T* ptr = a.get();
		return toString(ptr);
	}
	/*
	template<typename T>
	std::string toString(std::tr1::shared_ptr<T> a)
	{
		T* ptr = a.get();
		return toString(ptr);
	}
	*/

	template<typename T>
	std::string toString(T a)
	{
		std::ostringstream oss;
		oss << a;
		return oss.str();
	}
}
