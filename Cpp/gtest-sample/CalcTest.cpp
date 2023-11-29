#include <gtest/gtest.h>
#include "Calc.h"
#include <iostream>

//externC sum(int , int);

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(CalcTest, testSum)
{
    int a = 10;
    int b = 20;

    EXPECT_EQ(sum(a, b), 30) << " Failed here";
}

TEST(CalcTest, testDiff)
{
    int a = 10;
    int b = 20;

    ASSERT_EQ(diff(a, b), -10);
}

TEST(CalcTest, testMul)
{
    int a = 10;
    int b = 20;

    ASSERT_EQ(mul(a, b), 200);
}

TEST(CalcTest, testDiv)
{
    int a = 10;
    int b = 20;

    ASSERT_EQ(divide(a, b), 0);
}
