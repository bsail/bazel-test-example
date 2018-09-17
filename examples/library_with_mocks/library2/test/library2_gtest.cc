#include "gtest/gtest.h"
#include "library2.h"
#include "library1.h"
#include "fff.h"

DEFINE_FFF_GLOBALS;
FAKE_VALUE_FUNC(int, library1_func, int);

TEST(example, behaviour)
{
	EXPECT_EQ(library2_func(0),0);
	EXPECT_EQ(library2_func(1),1);
	EXPECT_EQ(library2_func(0),1);
	EXPECT_EQ(library2_func(5),6);

	ASSERT_EQ(library1_func_fake.call_count, 4);

	ASSERT_EQ(0, library1_func_fake.arg0_history[0]);
	ASSERT_EQ(0, library1_func_fake.arg0_history[1]);
	ASSERT_EQ(0, library1_func_fake.arg0_history[2]);
	ASSERT_EQ(0, library1_func_fake.arg0_history[3]);
}
