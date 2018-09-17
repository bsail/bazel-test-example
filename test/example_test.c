#include "unity.h"
#include "unity_fixture.h"
#include "src/example.h"
#include "mock_library.h"
#include "mock_another.h"

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

void test_example(void)
{
	another_func_Expect(55);
	library_func_ExpectAndReturn(0,0);
	library_func_ExpectAndReturn(1,0);
	library_func_ExpectAndReturn(2,0);
	library_func_ExpectAndReturn(3,0);
	library_func_ExpectAndReturn(4,0);
	TEST_ASSERT_EQUAL(0, example_func());
}
