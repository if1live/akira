#include "akira/AKTest.h"
#include "akira/AKValueType.h"

using std::string;
using namespace testing;

class TmpTest {
	
};

TEST(ValueTypeTest, toString)
{
	string result;
	int a = 1;
	result = toString(a);
	EXPECT_STREQ("1", result.c_str());
	result = toString(1);
	EXPECT_STREQ("1", result.c_str());
	result = toString(&a);

	char b = 'b';
	result = toString(b);
	EXPECT_STREQ("b", result.c_str());
	result = toString('b');
	EXPECT_STREQ("b", result.c_str());

	float c = 1.0f;
	toString(c);
	toString(1.0f);

	double d = 1.0;
	toString(d);
	toString(1.0);

	const char *e = "asd";
	result = toString(e);
	EXPECT_STREQ("asd", result.c_str());
	result = toString("asd");
	EXPECT_STREQ("asd", result.c_str());

	string f("asd");
	EXPECT_STREQ("asd", result.c_str());toString(f);

	std::auto_ptr<int> g(new int(2));
	toString(g);

	TmpTest *t = new TmpTest();
	result = toString(t);
	//result = toString(*t); class&형은 쓰지 않는다
	delete(t);
}