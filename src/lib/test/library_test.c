#include "unity.h"
#include "unity_fixture.h"
#include "library.h"

int GlobalVerifyOrder = 0;
int GlobalExpectCount = 0;

void setUp()
{
	GlobalVerifyOrder = 0;
	GlobalExpectCount = 0;
}

void tearDown()
{
}

void test_always_pass(void)
{
	TEST_ASSERT(1==1);
}

void test_library_1(void)
{
	TEST_ASSERT_EQUAL(0,library_func(0));
	TEST_ASSERT_EQUAL(1,library_func(1));
	TEST_ASSERT_EQUAL(1,library_func(0));
	TEST_ASSERT_EQUAL(6,library_func(5));
}

