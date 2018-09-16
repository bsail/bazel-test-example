#include "unity.h"
#include "unity_fixture.h"
#include "src/example.h"

void setUp()
{
}

void tearDown()
{
}

void test_example(void)
{
	TEST_ASSERT_EQUAL(0, example_func());
}
