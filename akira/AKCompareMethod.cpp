// Ŭnicode please 

#include "AKCompareMethod.h"

namespace testing
{
	bool isEqualString(const char *a, const char *b, bool ignoreCase)
	{
		if(a == NULL && b == NULL)
		{
			return true;
		}
		if((a == NULL && b != NULL) || (a != NULL && b == NULL))
		{
			return false;
		}
		return isEqualString(std::string(a), std::string(b), ignoreCase);
	}
	bool isEqualString(const std::string &a, const std::string &b, bool ignoreCase)
	{
		if(ignoreCase == false)
		{
			return (a == b);
		}
		else
		{
			char *str1 = new char[a.size()+1];
			char *str2 = new char[b.size()+1];
			
			strcpy(str1, a.c_str());
			strcpy(str2, b.c_str());
			for(std::size_t i = 0 ; i < a.size() ; i++)
			{
				str1[i] = tolower(str1[i]);
			}
			for(std::size_t i = 0 ; i < b.size() ; i++)
			{
				str2[i] = tolower(str2[i]);
			}

			bool result = (strcmp(str1, str2) == 0) ? true : false;

			delete[](str1);
			delete[](str2);
			
			return result;
		}
	}
}