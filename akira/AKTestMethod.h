// Ŭnicode please
#pragma once

#include "akira/AKTestContext.h"

#define EXPECT_EQ(expected, actual)	\
	{ testing::TestContext::getInstance().expectEq(expected, actual, __FILE__, __LINE__, false); }
#define EXPECT_NE(v1, v2)	\
	{ testing::TestContext::getInstance().expectNotEq(expected, actual, __FILE__, __LINE__, false); }
#define EXPECT_LT(v1, v2)	\
	{ testing::TestContext::getInstance().expectLessThan(expected, actual, __FILE__, __LINE__, false); }
#define EXPECT_LE(v1, v2)	\
	{ testing::TestContext::getInstance().expectLessEqual(expected, actual, __FILE__, __LINE__, false); }
#define EXPECT_GT(v1, v2)	\
	{ testing::TestContext::getInstance().expectGreaterThan(expected, actual, __FILE__, __LINE__, false); }
#define EXPECT_GE(v1, v2)	\
	{ testing::TestContext::getInstance().expectGreaterEqual(expected, actual, __FILE__, __LINE__, false); }

#define EXPECT_TRUE(actual)	\
	{ testing::TestContext::getInstance().expectEq(true, actual, __FILE__, __LINE__, false); }
#define EXPECT_FALSE(actual)	\
	{ testing::TestContext::getInstance().expectEq(false, actual, __FILE__, __LINE__, false); }

#define EXPECT_STREQ(expected, actual)	\
	{ testing::TestContext::getInstance().expectStrEq(expected, actual, false, __FILE__, __LINE__, false); }
#define EXPECT__STRNE(s1, s2)	\
	{ testing::TestContext::getInstance().expectStrNotEq(expected, actual, false, __FILE__, __LINE__, false); }
#define EXPECT_STRCASEEQ(s1, s2)	\
	{ testing::TestContext::getInstance().expectStrEq(expected, actual, true, __FILE__, __LINE__, false); }
#define EXPECT_STRCASENE(s1, s2)	\
	{ testing::TestContext::getInstance().expectStrNotEq(expected, actual, true, __FILE__, __LINE__, false); }

#define EXPECT_FLOAT_EQ(expected, actual)	\
	{ testing::TestContext::getInstance().expectFloatEq(expected, actual, true, __FILE__, __LINE__, false); }
#define EXPECT_DOUBLE_EQ(expected, actual)	\
	{ testing::TestContext::getInstance().expectDoubleEq(expected, actual, true, __FILE__, __LINE__, false); }
#define EXPECT_NEAR(v1, v2, abs_error)	\
	{ testing::TestContext::getInstance().expectNearEq(expected, actual, abs_error, true, __FILE__, __LINE__, false); }

//////////////////////////////////////////////////
#define ASSERT_EQ(expected, actual)	\
	{ testing::TestContext::getInstance().expectEq(expected, actual, __FILE__, __LINE__, true); }
#define ASSERT_NE(v1, v2)	\
	{ testing::TestContext::getInstance().expectNotEq(expected, actual, __FILE__, __LINE__, true); }
#define ASSERT_LT(v1, v2)	\
	{ testing::TestContext::getInstance().expectLessThan(expected, actual, __FILE__, __LINE__, true); }
#define ASSERT_LE(v1, v2)	\
	{ testing::TestContext::getInstance().expectLessEqual(expected, actual, __FILE__, __LINE__, true); }
#define ASSERT_GT(v1, v2)	\
	{ testing::TestContext::getInstance().expectGreaterThan(expected, actual, __FILE__, __LINE__, true); }
#define ASSERT_GE(v1, v2)	\
	{ testing::TestContext::getInstance().expectGreaterEqual(expected, actual, __FILE__, __LINE__, true); }

#define ASSERT_TRUE(actual)	\
	{ testing::TestContext::getInstance().expectEq(true, actual, __FILE__, __LINE__, true); }
#define ASSERT_FALSE(actual)	\
	{ testing::TestContext::getInstance().expectEq(false, actual, __FILE__, __LINE__, true); }

#define ASSERT_STREQ(expected, actual)	\
	{ testing::TestContext::getInstance().expectStrEq(expected, actual, false, __FILE__, __LINE__, true); }
#define ASSERT__STRNE(s1, s2)	\
	{ testing::TestContext::getInstance().expectStrNotEq(expected, actual, false, __FILE__, __LINE__, true); }
#define ASSERT_STRCASEEQ(s1, s2)	\
	{ testing::TestContext::getInstance().expectStrEq(expected, actual, true, __FILE__, __LINE__, true); }
#define ASSERT_STRCASENE(s1, s2)	\
	{ testing::TestContext::getInstance().expectStrNotEq(expected, actual, true, __FILE__, __LINE__, true); }

#define ASSERT_FLOAT_EQ(expected, actual)	\
	{ testing::TestContext::getInstance().expectFloatEq(expected, actual, true, __FILE__, __LINE__, true); }
#define ASSERT_DOUBLE_EQ(expected, actual)	\
	{ testing::TestContext::getInstance().expectDoubleEq(expected, actual, true, __FILE__, __LINE__, true); }
#define ASSERT_NEAR(v1, v2, abs_error)	\
	{ testing::TestContext::getInstance().expectNearEq(expected, actual, abs_error, true, __FILE__, __LINE__, true); }

//required api
// Macros for testing equalities and inequalities.
//
//    * {ASSERT|EXPECT}_EQ(expected, actual): Tests that expected == actual
//    * {ASSERT|EXPECT}_NE(v1, v2):           Tests that v1 != v2
//    * {ASSERT|EXPECT}_LT(v1, v2):           Tests that v1 < v2
//    * {ASSERT|EXPECT}_LE(v1, v2):           Tests that v1 <= v2
//    * {ASSERT|EXPECT}_GT(v1, v2):           Tests that v1 > v2
//    * {ASSERT|EXPECT}_GE(v1, v2):           Tests that v1 >= v2
//
// When they are not, Google Test prints both the tested expressions and
// their actual values.  The values must be compatible built-in types,
// or you will get a compiler error.  By "compatible" we mean that the
// values can be compared by the respective operator.
//
// Note:
//
//   1. It is possible to make a user-defined type work with
//   {ASSERT|EXPECT}_??(), but that requires overloading the
//   comparison operators and is thus discouraged by the Google C++
//   Usage Guide.  Therefore, you are advised to use the
//   {ASSERT|EXPECT}_TRUE() macro to assert that two objects are
//   equal.
//
//   2. The {ASSERT|EXPECT}_??() macros do pointer comparisons on
//   pointers (in particular, C strings).  Therefore, if you use it
//   with two C strings, you are testing how their locations in memory
//   are related, not how their content is related.  To compare two C
//   strings by content, use {ASSERT|EXPECT}_STR*().
//
//   3. {ASSERT|EXPECT}_EQ(expected, actual) is preferred to
//   {ASSERT|EXPECT}_TRUE(expected == actual), as the former tells you
//   what the actual value is when it fails, and similarly for the
//   other comparisons.
//
//   4. Do not depend on the order in which {ASSERT|EXPECT}_??()
//   evaluate their arguments, which is undefined.
//
//   5. These macros evaluate their arguments exactly once.
//
// Examples:
//
//   EXPECT_NE(5, Foo());
//   EXPECT_EQ(NULL, a_pointer);
//   ASSERT_LT(i, array_size);
//   ASSERT_GT(records.size(), 0) << "There is no record left.";

// C String Comparisons.  All tests treat NULL and any non-NULL string
// as different.  Two NULLs are equal.
//
//    * {ASSERT|EXPECT}_STREQ(s1, s2):     Tests that s1 == s2
//    * {ASSERT|EXPECT}_STRNE(s1, s2):     Tests that s1 != s2
//    * {ASSERT|EXPECT}_STRCASEEQ(s1, s2): Tests that s1 == s2, ignoring case
//    * {ASSERT|EXPECT}_STRCASENE(s1, s2): Tests that s1 != s2, ignoring case
//
// For wide or narrow string objects, you can use the
// {ASSERT|EXPECT}_??() macros.
//
// Don't depend on the order in which the arguments are evaluated,
// which is undefined.
//
// These macros evaluate their arguments exactly once.

// Macros for comparing floating-point numbers.
//
//    * {ASSERT|EXPECT}_FLOAT_EQ(expected, actual):
//         Tests that two float values are almost equal.
//    * {ASSERT|EXPECT}_DOUBLE_EQ(expected, actual):
//         Tests that two double values are almost equal.
//    * {ASSERT|EXPECT}_NEAR(v1, v2, abs_error):
//         Tests that v1 and v2 are within the given distance to each other.
//
// Google Test uses ULP-based comparison to automatically pick a default
// error bound that is appropriate for the operands.  See the
// FloatingPoint template class in gtest-internal.h if you are
// interested in the implementation details.
