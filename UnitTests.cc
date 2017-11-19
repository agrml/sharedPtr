#include <gtest/gtest.h>
#include "sharedPtr.hpp"


TEST(Internals, defaultConstructor)
{
    auto a = SharedPtr<int>();
    EXPECT_EQ(a.pVal_, nullptr);
    EXPECT_EQ(a.pCnt_, nullptr);
}

TEST(Internals, fromPtr)
{
    constexpr int val = 32;
    auto a = SharedPtr<int>{new int{val}};
    ASSERT_NE(a.pVal_, nullptr);
    ASSERT_NE(a.pCnt_, nullptr);
    EXPECT_EQ(*a.pCnt_, 1);
    EXPECT_EQ(*a.pVal_, val);

    EXPECT_EQ(*a, val);
    ++*a;
    EXPECT_EQ(*a, val + 1);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}