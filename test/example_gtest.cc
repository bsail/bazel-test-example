#include "gtest/gtest.h"
#include "src/example.h"
#include "fff.h"

TEST(HelloTest, GetGreet) {
  EXPECT_EQ(example_func(), 0);
}
