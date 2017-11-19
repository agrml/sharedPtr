#include <gtest/gtest.h>
#include "sharedPtr.hpp"


TEST(SharedPtr, Internal)
{
    auto a = SharedPtr<int>();
    ASSERT_EQ(a.pVal_, nullptr);
    ASSERT_EQ(a.pCnt_, nullptr);
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}