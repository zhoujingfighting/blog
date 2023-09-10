#include "first_test.h"
#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

TEST(FACTOR, IsrightOrnot) {
  EXPECT_EQ(fac(3), 6);
  EXPECT_EQ(fac(4), 24);
}

TEST(Validate, isValidDormitoryRoom) {
  EXPECT_EQ(isValidDormitoryRoom("zhoujing@zisong.10.315.4"), true);
  EXPECT_EQ(isValidDormitoryRoom("zhoujing@zisong.10.315"),false);
  EXPECT_EQ(isValidDormitoryRoom("zhoujing@zisong.10.315.2323.323"),false);
  EXPECT_EQ(isValidDormitoryRoom("zhoujing@zisong.d.315.4"),false);
  EXPECT_EQ(isValidDormitoryRoom("zhoujing@zisong.10.315."),false);
}