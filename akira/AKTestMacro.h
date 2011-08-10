// Ŭnicode please 
#pragma once

#include "akira/AKTestCase.h"

//http://decoder.tistory.com/559같은 연출 보여주기 
//http://www.ibm.com/developerworks/kr/library/au-googletestingframework.html 

//NOTE : 변수할당을 바로 시키면 중간에 뜬금없는 코드 실행이 가능하다 

//함수단위의 테스트 -> {}구문을 함수로만들고 함수포인터써서 적절히 실행하기.
//클래스로 만들경우, 구조가 복잡해지더라 
#define TEST(TESTCASE, TESTMETHOD)	\
	void test_##TESTCASE##TESTMETHOD();	\
	bool run_##TESTCASE##TESTMETHOD = testing::TestSuite::global().add(new testing::FunctionTestCase(#TESTCASE, #TESTMETHOD, test_##TESTCASE##TESTMETHOD));	\
	void test_##TESTCASE##TESTMETHOD()

//클래스 단위의 단위테스트
//TESTCASE는 testing::Test를 상속받은 상태일것이다
//각각의 함수는 testing::Test에 다시 들어간다
#define TEST_F(TESTCASE, TESTMETHOD)	\
class testf_##TESTCASE##TESTMETHOD : public TESTCASE { \
public:	\
testf_##TESTCASE##TESTMETHOD(const char *name, const char *method)	\
: TESTCASE()	\
{	\
name_ = name;	\
method_ = method;	\
}	\
protected:	\
virtual void __test();	\
};	\
bool runf_##TESTCASE##TESTMETHOD = testing::TestSuite::global().add(new testf_##TESTCASE##TESTMETHOD(#TESTCASE, #TESTMETHOD));	\
void testf_##TESTCASE##TESTMETHOD::__test()

//all in one macro, like google test
#define RUL_ALL_TESTS()	testing::TestSuite::global().runAllTest(__FILE__)

#define LOG(fmt, ...) { printf(fmt"\n", __VA_ARGS__); }
#define LINE_LOG(msg) { printf(msg"\n"); }
