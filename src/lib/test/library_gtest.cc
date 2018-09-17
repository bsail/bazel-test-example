#include "gtest/gtest.h"
#include "library.h"
// #include "fff.h"

// DEFINE_FFF_GLOBALS;
// FAKE_VALUE_FUNC(int, library_func, int);
// FAKE_VOID_FUNC(another_func, int);

TEST(example, behaviour)
{
	EXPECT_EQ(library_func(0),0);
	EXPECT_EQ(library_func(1),1);
	EXPECT_EQ(library_func(0),1);
	EXPECT_EQ(library_func(5),6);
}
