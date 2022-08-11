//
// Created by wenwen on 2022/8/1.
//

#include <iostream>
#include <gtest/gtest.h>
#include "src/al_dp.h"

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    testing::FLAGS_gtest_filter = "numSquares*";
    return RUN_ALL_TESTS();
}

TEST(numSquares, basic) {
    EXPECT_EQ(numSquares(1), 1);
    EXPECT_EQ(numSquares(2), 2);
    EXPECT_EQ(numSquares(3), 3);
    EXPECT_EQ(numSquares(4), 1);
    EXPECT_EQ(numSquares(8), 2);
    EXPECT_EQ(numSquares(9), 1);
    EXPECT_EQ(numSquares(12), 3);
    EXPECT_EQ(numSquares(5673), 3);
};

TEST(canPartition416, basic){
    EXPECT_EQ(canPartition416({2, 1}), false);
    EXPECT_EQ(canPartition416({2, 3}), false);

    EXPECT_EQ(canPartition416({2, 1, 3}), true);
    EXPECT_EQ(canPartition416({1, 1}), true);
    EXPECT_EQ(canPartition416({1, 1, 2}), true);
    EXPECT_EQ(canPartition416({1, 1, 2, 4}), true);
    EXPECT_EQ(canPartition416({1,5,11,5}), true);
    EXPECT_EQ(canPartition416({1,5,3,1}), true);
};

TEST(knapsack01, basic){
    EXPECT_EQ(knapsack01(1, {2, 1, 3}, {4, 2, 3}), 2);
    EXPECT_EQ(knapsack01(2, {2, 1, 3}, {4, 2, 3}), 4);
    EXPECT_EQ(knapsack01(3, {2, 1, 3}, {4, 2, 3}), 6);
    EXPECT_EQ(knapsack01(4, {2, 1, 3}, {4, 2, 3}), 6);
    EXPECT_EQ(knapsack01(5, {2, 1, 3}, {4, 2, 3}), 7);
    EXPECT_EQ(knapsack01(6, {2, 1, 3}, {4, 2, 3}), 9);
};


TEST(change518, baisc) {
    EXPECT_EQ(change518(5, {1}), 1);
    EXPECT_EQ(change518(1, {1, 2, 5}), 1);
    EXPECT_EQ(change518(2, {1, 2, 5}), 2);
    EXPECT_EQ(change518(3, {1, 2, 5}), 2);
    EXPECT_EQ(change518(4, {1, 2, 5}), 3);
    EXPECT_EQ(change518(5, {1, 2, 5}), 4);
};

TEST(coinChange, baisc){
    EXPECT_EQ(coinChange({1}, 5), 5);
    EXPECT_EQ(coinChange({1, 5, 10}, 5), 1);
    EXPECT_EQ(coinChange({1, 5, 10}, 4), 4);
    EXPECT_EQ(coinChange({1, 5, 10}, 15), 2);
    EXPECT_EQ(coinChange({1, 5, 11}, 15), 3);
    EXPECT_EQ(coinChange({1, 5, 11}, 11), 1);
    EXPECT_EQ(coinChange({1, 5, 11}, 12), 2);
};

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