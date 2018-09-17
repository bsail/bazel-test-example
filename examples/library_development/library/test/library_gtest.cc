#include "gtest/gtest.h"
#include "library.h"

TEST(example, behaviour)
{
	EXPECT_EQ(library_func(0),0);
	EXPECT_EQ(library_func(1),1);
	EXPECT_EQ(library_func(0),1);
	EXPECT_EQ(library_func(5),6);
}
