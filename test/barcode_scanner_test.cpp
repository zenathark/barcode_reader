#include <gtest/gtest.h>

TEST(SampleTest, AssertionTrue) {
	ASSERT_EQ(1, 1);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  RUN_ALL_TESTS();
  return 0;
}
