#include "akira/AKTest.h"
#include "akira/AKCompareMethod.h"
#include <memory>
#include <cmath>

using namespace std;
using namespace testing;

class TestObject {
public:
	TestObject(int a) : value(a) {}
	bool operator==(const TestObject &o) const { return (value == o.value); }
	bool operator!=(const TestObject &o) const { return (value != o.value); }
	bool operator>(const TestObject &o) const { return (value > o.value); }
	bool operator>=(const TestObject &o) const { return (value >= o.value); }
	bool operator<(const TestObject &o) const { return (value < o.value); }
	bool operator<=(const TestObject &o) const { return (value <= o.value); }
	int value;
};

TEST(Compare, isEqual)
{
	//int type
	EXPECT_EQ(true, isEqual((int)1, (int)1));
	EXPECT_EQ(true, isEqual((int)1, (unsigned int)1));
	EXPECT_EQ(true, isEqual((int)1, (short)1));
	//int type+false
	EXPECT_EQ(false, isEqual((int)2, (int)1));
	EXPECT_EQ(false, isEqual((int)2, (unsigned int)1));
	EXPECT_EQ(false, isEqual((int)2, (short)1));

	//pointer
	int a = 1;
	int b = 1;
	int c = 2;
	EXPECT_EQ(true, isEqual(a, b));
	EXPECT_EQ(true, isEqual(&a, &a));
	EXPECT_EQ(false, isEqual(&a, &b));
	EXPECT_EQ(false, isEqual(&a, &c));

	//object
	TestObject o1(1);
	TestObject o2(1);
	TestObject o3(2);
	EXPECT_EQ(true, o1 == o2);
	EXPECT_EQ(true, isEqual(o1, o2));
	EXPECT_EQ(false, isEqual(o1, o3));

	//auto_ptr
	auto_ptr<TestObject> p1(new TestObject(1));
	auto_ptr<TestObject> p2(new TestObject(1));
	auto_ptr<TestObject> p3(new TestObject(2));
	EXPECT_EQ(true, isEqual(*p1, *p2));
	EXPECT_EQ(false, isEqual(*p1, *p3));
	EXPECT_EQ(false, isEqual(p1.get(), p2.get()));
}

TEST(Compare, isEqualString)
{
	//null test
	EXPECT_EQ(true, isEqualString(NULL, NULL, true));
	EXPECT_EQ(true, isEqualString(NULL, NULL, false));
	EXPECT_EQ(false, isEqualString(NULL, "asdf", true));
	EXPECT_EQ(false, isEqualString("fsd", NULL, false));

	//normal 
	EXPECT_EQ(true, isEqualString("asdf", "asdf", false));
	EXPECT_EQ(false, isEqualString("asdf", "asdffs", false));

	//case test
	EXPECT_EQ(true, isEqualString("asdf", "ASDF", true));
	EXPECT_EQ(false, isEqualString("asdf", "ASDF", false));
}

TEST(Compare, le_lt_gt_ge)
{
	TestObject a1(1);
	TestObject a2(2);
	//lt
	EXPECT_EQ(true, isLessThan(a1, a2));
	EXPECT_EQ(false, isLessThan(a1, a1));
	EXPECT_EQ(false, isLessThan(a2, a1));

	//le
	EXPECT_EQ(true, isLessEqual(a1, a2));
	EXPECT_EQ(true, isLessEqual(a1, a1));
	EXPECT_EQ(false, isLessEqual(a2, a1));

	//gt
	EXPECT_EQ(false, isGreaterThan(a1, a2));
	EXPECT_EQ(false, isGreaterThan(a1, a1));
	EXPECT_EQ(true, isGreaterThan(a2, a1));

	//ge
	EXPECT_EQ(false, isGreaterEqual(a1, a2));
	EXPECT_EQ(true, isGreaterEqual(a1, a1));
	EXPECT_EQ(true, isGreaterEqual(a2, a1));
}

TEST(Compare, ErrorEqual)
{
	EXPECT_EQ(true, isRelErrorEqual(2.0f, sqrtf(4.0f), 0.0001f));
	EXPECT_EQ(true, isRelErrorEqual(23.3333f, sqrtf(544.44444f), 0.0001f));
	EXPECT_EQ(true, isRelErrorEqual(2.0, sqrt(4.0), 0.0001));
	EXPECT_EQ(true, isRelErrorEqual(23.33333333333333, sqrt(544.44444444444444), 0.0001));
	// the above succeeds
	EXPECT_EQ(true, isEqual(2.0, sqrt(4.0)));
	// the above fails
	EXPECT_EQ(false, isEqual(23.33333333333333, sqrt(544.44444444444444)));
}