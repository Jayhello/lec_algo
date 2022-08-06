//
// Created by wenwen on 2022/8/1.
//

#include <iostream>
#include <gtest/gtest.h>
#include "src/al_dp.h"

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    testing::FLAGS_gtest_filter = "maxProfit122*";
    return RUN_ALL_TESTS();

    return 0;
}

TEST(maxProfit122, basic) {
    EXPECT_EQ(maxProfit122({1}), 0);
    EXPECT_EQ(maxProfit122({1, 2}), 1);
    EXPECT_EQ(maxProfit122({1, 2, 3}), 2);
    EXPECT_EQ(maxProfit122({1, 3, 2, 4}), 4);
    EXPECT_EQ(maxProfit122({1, 5, 1, 2, 4}), 7);
    EXPECT_EQ(maxProfit122({6, 5, 8, 2, 4}), 5);

    EXPECT_EQ(maxProfit122({2, 1}), 0);
    EXPECT_EQ(maxProfit122({3, 2, 1}), 0);
};

TEST(maxProfit, basic) {
    EXPECT_EQ(maxProfit({1}), 0);
    EXPECT_EQ(maxProfit({1, 2}), 1);
    EXPECT_EQ(maxProfit({1, 2, 3}), 2);
    EXPECT_EQ(maxProfit({1, 3, 2, 4}), 3);
    EXPECT_EQ(maxProfit({3, 2, 1}), 0);
    EXPECT_EQ(maxProfit({3, 1}), 0);
};

TEST(rob2, basic) {
    EXPECT_EQ(rob2({1}), 1);
    EXPECT_EQ(rob2({1, 2}), 2);
    EXPECT_EQ(rob2({1, 3, 1}), 3);
    EXPECT_EQ(rob2({1, 3, 3, 1}), 4);
    EXPECT_EQ(rob2({200, 3, 140, 20, 10}), 340);
};

TEST(rob, basic) {
    EXPECT_EQ(rob({1}), 1);
    EXPECT_EQ(rob({1, 2}), 2);
    EXPECT_EQ(rob({1, 3, 1}), 3);
    EXPECT_EQ(rob({1, 3, 3, 1}), 4);
    EXPECT_EQ(rob({1, 3, 3, 3}), 6);
    EXPECT_EQ(rob({5, 3, 3, 7}), 12);
};


TEST(maxSubArray, basic) {
    EXPECT_EQ(maxSubArray({1}), 1);
    EXPECT_EQ(maxSubArray({1, 0}), 1);
    EXPECT_EQ(maxSubArray({1, 0, 1}), 2);

    EXPECT_EQ(maxSubArray({1, -1, 1}), 1);
    EXPECT_EQ(maxSubArray({2, -1, 1}), 2);
    EXPECT_EQ(maxSubArray({2, -1, 2}), 3);
    EXPECT_EQ(maxSubArray({2, -1, 2, -1, 1}), 3);
    EXPECT_EQ(maxSubArray({2, -1, 2, -1, 2}), 4);
};