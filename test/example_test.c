#include "unity.h"
#include "unity_fixture.h"
#include "src/example.h"
#include "src/lib/inc/mock_library.h"

int GlobalVerifyOrder = 0;
int GlobalExpectCount = 0;

void setUp()
{
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
	library_func_Expect(0);
	library_func_Expect(1);
	library_func_Expect(2);
	library_func_Expect(3);
	library_func_Expect(4);
	TEST_ASSERT_EQUAL(0, example_func());
}
