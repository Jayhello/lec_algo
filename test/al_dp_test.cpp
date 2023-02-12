//
// Created by wenwen on 2022/8/1.
//

#include <iostream>
#include <gtest/gtest.h>
#include "src/al_dp.h"

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
//    testing::FLAGS_gtest_filter = "findLength*";
    testing::FLAGS_gtest_filter = "maxSubArray*";
    return RUN_ALL_TESTS();
}

TEST(maxProduct, basic) {
    EXPECT_EQ(maxProduct({1}), 1);
    EXPECT_EQ(maxProduct({1, 1}), 1);
    EXPECT_EQ(maxProduct({2,3,-2,4}), 6);
    EXPECT_EQ(maxProduct({-2,0,-1}), 0);
    EXPECT_EQ(maxProduct({-2,-3,-1}), 6);
    EXPECT_EQ(maxProduct({-2,3,-1}), 6);
    EXPECT_EQ(maxProduct({-2,3,-1, -3}), 9);
    EXPECT_EQ(maxProduct({0, -2, -3}), 6);
};

TEST(maximalSquare, basic) {
    EXPECT_EQ(maximalSquare({{'1','0','1','0','0'},{'1','0','1','1','1'},
                             {'1','1','1','1','1'}, {'1','0','0','1','0'}}), 4);

    EXPECT_EQ(maximalSquare({{'1','1','1','1','1'},{'1','1','1','1','1'},
                             {'1','1','1','1','1'}, {'1','0','0','1','0'}}), 9);
};

TEST(minPathSum, basic) {
    EXPECT_EQ(minPathSum({{1,3,1},{1,5,1}, {4,2,1}}), 7);
    EXPECT_EQ(minPathSum({{1,2,3},{4,5,6}}), 12);
};

TEST(uniquePathsWithObstacles, basic) {
    EXPECT_EQ(uniquePathsWithObstacles({{0,0,0},{0,1,0}, {0,0,0}}), 2);
};

TEST(uniquePaths, basic) {
    EXPECT_EQ(uniquePaths(7, 3), 28);
    EXPECT_EQ(uniquePaths(3, 7), 28);
    EXPECT_EQ(uniquePaths(3, 3), 6);
    EXPECT_EQ(uniquePaths(3, 2), 3);
};

TEST(wordBreak, basic) {
    EXPECT_EQ(wordBreak("a", {"a", "b"}), true);
    EXPECT_EQ(wordBreak("a", {"c", "b"}), false);
    EXPECT_EQ(wordBreak("a", {"c", "aa"}), false);
    EXPECT_EQ(wordBreak("ab", {"a", "b"}), true);
    EXPECT_EQ(wordBreak("acb", {"a", "b"}), false);
    EXPECT_EQ(wordBreak("acb", {"ca", "b"}), false);
    EXPECT_EQ(wordBreak("leetcode", {"leet", "code"}), true);
    EXPECT_EQ(wordBreak("applepenapple", {"apple", "pen"}), true);
    EXPECT_EQ(wordBreak("catsandog", {"cats", "dog", "sand", "and", "cat"}), false);
};

TEST(longestPalindromeSubseq, basic) {
    EXPECT_EQ(longestPalindromeSubseq("a"), 1);
    EXPECT_EQ(longestPalindromeSubseq("aa"), 2);
    EXPECT_EQ(longestPalindromeSubseq("aaa"), 3);
    EXPECT_EQ(longestPalindromeSubseq("bbbab"), 4);
    EXPECT_EQ(longestPalindromeSubseq("cbbd"), 2);
    EXPECT_EQ(longestPalindromeSubseq("cbbdb"), 3);
    EXPECT_EQ(longestPalindromeSubseq("cbbdbc"), 5);

};

TEST(longestPalindrome, basic) {
    EXPECT_EQ(longestPalindrome("a"), "a");
    EXPECT_EQ(longestPalindrome("aa"), "aa");
    EXPECT_EQ(longestPalindrome("aaa"), "aaa");
    EXPECT_EQ(longestPalindrome("cbbd"), "bb");
    EXPECT_EQ(longestPalindrome("cbbc"), "cbbc");
    EXPECT_EQ(longestPalindrome("cbabc"), "cbabc");
};

TEST(countSubstrings, basic) {
    EXPECT_EQ(countSubstrings("a"), 1);
    EXPECT_EQ(countSubstrings("abc"), 3);
    EXPECT_EQ(countSubstrings("aaaaa"), 15);
    EXPECT_EQ(countSubstrings("aaa"), 6);
};

TEST(findLength, basic) {
    EXPECT_EQ(findLength({1}, {1}), 1);
    EXPECT_EQ(findLength({1}, {0}), 0);
    EXPECT_EQ(findLength({0}, {1}), 0);
    EXPECT_EQ(findLength({1}, {1, 1}), 1);
    EXPECT_EQ(findLength({1, 1}, {1}), 1);
    EXPECT_EQ(findLength({1, 1}, {1, 1}), 2);
    EXPECT_EQ(findLength({1, 1}, {1, 1, 1}), 2);
    EXPECT_EQ(findLength({1, 1, 1}, {1, 1, 1}), 3);
    EXPECT_EQ(findLength({1,2,3,2,1}, {3,2,1,4,7}), 3);
    EXPECT_EQ(findLength({1,2,3,2,1, 3, 4}, {1,2,3,4,2, 1, 3 ,4}), 4);
    EXPECT_EQ(findLength({1,2,3,2,1}, {3,2,1,4}), 3);
};

TEST(minDistance, basic) {
    EXPECT_EQ(minDistance("a", "a"), 0);
    EXPECT_EQ(minDistance("sea", "eat"), 2);
    EXPECT_EQ(minDistance("leetcode", "etco"), 4);
    EXPECT_EQ(minDistance("aa", "aa"), 0);
    EXPECT_EQ(minDistance("aa", "a"), 1);
    EXPECT_EQ(minDistance("a", "aa"), 1);

    EXPECT_EQ(minDistance("abc", "ade"), 4);
    EXPECT_EQ(minDistance("abc", "a"), 2);
    EXPECT_EQ(minDistance("a", "ab"), 1);
    EXPECT_EQ(minDistance("a", "cd"), 3);
};

TEST(minimumDeleteSum, basic) {
    EXPECT_EQ(minimumDeleteSum("a", "a"), 0);
    EXPECT_EQ(minimumDeleteSum("sea", "eat"), 231);
    EXPECT_EQ(minimumDeleteSum("delete", "leet"), 403);
    EXPECT_EQ(minimumDeleteSum("az", "za"), 194);
};

TEST(longestCommonSubsequence, basic) {
    EXPECT_EQ(longestCommonSubsequence("", ""), 0);
    EXPECT_EQ(longestCommonSubsequence("a", "a"), 1);
    EXPECT_EQ(longestCommonSubsequence("a", "ab"), 1);
    EXPECT_EQ(longestCommonSubsequence("a", "aba"), 1);
    EXPECT_EQ(longestCommonSubsequence("a", "aa"), 1);
    EXPECT_EQ(longestCommonSubsequence("aa", "aa"), 2);

    EXPECT_EQ(longestCommonSubsequence("abc", "ab"), 2);
    EXPECT_EQ(longestCommonSubsequence("abc", "abc"), 3);
    EXPECT_EQ(longestCommonSubsequence("agbdc", "abc"), 3);
};

TEST(findLengthOfLCIS, basic) {
    EXPECT_EQ(findLengthOfLCIS({1}), 1);
    EXPECT_EQ(findLengthOfLCIS({1, 1}), 1);
    EXPECT_EQ(findLengthOfLCIS({1, 2, 3}), 3);
    EXPECT_EQ(findLengthOfLCIS({1, 2, 1, 3}), 2);
    EXPECT_EQ(findLengthOfLCIS({1, 2, 1, 3}), 2);
    EXPECT_EQ(findLengthOfLCIS({1, 2, 4, 3, 4}), 3);
    EXPECT_EQ(findLengthOfLCIS({1, 2, 4, 3, 4, 5, 6}), 4);
};

TEST(lengthOfLIS, basic) {
    EXPECT_EQ(lengthOfLIS({1}), 1);
    EXPECT_EQ(lengthOfLIS({1, 2, 3}), 3);
    EXPECT_EQ(lengthOfLIS({1, 2}), 2);

    EXPECT_EQ(lengthOfLIS({2, 1}), 1);
    EXPECT_EQ(lengthOfLIS({3, 2, 1}), 1);

    EXPECT_EQ(lengthOfLIS({1, 7, 2, 4}), 3);
    EXPECT_EQ(lengthOfLIS({4, 5, 2, 6, 7}), 4);
};

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