#include <gtest/gtest.h>
#include "sharedPtr.hpp"


TEST(Internals, defaultConstructor)
{
    SharedPtr<int> a{};
    EXPECT_EQ(a.pVal_, nullptr);
    EXPECT_EQ(a.pCnt_, nullptr);
}

TEST(Internals, fromPtr)
{
    constexpr int val = 32;

    SharedPtr<int> a{new int{val}};
    ASSERT_NE(a.pVal_, nullptr);
    ASSERT_NE(a.pCnt_, nullptr);
    EXPECT_EQ(*a.pCnt_, 1);
    EXPECT_EQ(*a.pVal_, val);

    EXPECT_EQ(*a, val);
    ++*a;
    EXPECT_EQ(*a, val + 1);
}

TEST(API, fromClass)
{
    SharedPtr<std::pair<int, int>> a{new std::pair<int, int>{1, 2}};

    EXPECT_EQ(a->first, 1);
    EXPECT_EQ(a->second, 2);
    EXPECT_EQ((*a).first, 1);
    auto tmp = std::pair<int, int>{1, 2};
    EXPECT_EQ(*a, tmp);
}

TEST(API, comparision)
{

    SharedPtr<int> a{new int{0}};
    SharedPtr<int> b{new int{0}};
    ASSERT_FALSE(a == b);
}

TEST(API, assignment)
{
    SharedPtr<int> a{new int{0}};
    SharedPtr<int> b{new int{0}};
    a = b;
    ASSERT_EQ(*a, *b);
}

//TEST(INTERNALS, nullptrCase)
//{
//    SharedPtr<int> a{nullptr};
//    ASSERT_EQ(a.count(), 0);
//    ASSERT_EQ(a.get(), nullptr);
//}

TEST(Internals, multipleOwnership)
{
    auto p = new int{0};
    SharedPtr<int> a{p};
    {
        SharedPtr<int> b{p};
        EXPECT_EQ(*a, *b);
        EXPECT_EQ(*a.pCnt_, 1);
        EXPECT_EQ(*b.pCnt_, 1);
    }
    EXPECT_EQ(*a.pCnt_, 1);
    --*a.pCnt_;
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}