#include "gtest/gtest.h"
#include "src/example.h"
#include "fff.h"

DEFINE_FFF_GLOBALS;
FAKE_VALUE_FUNC(int, library_func, int);
FAKE_VOID_FUNC(another_func, int);

TEST(example, behaviour)
{
	EXPECT_EQ(example_func(), 0);

	ASSERT_EQ(another_func_fake.call_count, 1);
	ASSERT_EQ(55, another_func_fake.arg0_history[0]);


	ASSERT_EQ(library_func_fake.call_count, 5);

	ASSERT_EQ(0, library_func_fake.arg0_history[0]);
	ASSERT_EQ(1, library_func_fake.arg0_history[1]);
	ASSERT_EQ(2, library_func_fake.arg0_history[2]);
	ASSERT_EQ(3, library_func_fake.arg0_history[3]);
	ASSERT_EQ(4, library_func_fake.arg0_history[4]);
}
