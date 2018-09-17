#include "unity.h"
#include "unity_fixture.h"
#include "src/example.h"

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
	TEST_ASSERT_EQUAL(0, example_func());
}
