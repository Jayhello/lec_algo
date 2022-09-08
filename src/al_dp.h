//
// Created by wenwen on 2022/8/1.
//
#pragma once

#include <vector>
#include <string>

using namespace std;

//https://leetcode.cn/problems/maximum-subarray/
int maxSubArray(const vector<int>& nums);

// https://leetcode.cn/problems/house-robber/
int rob(const vector<int>& nums);

//https://leetcode.cn/problems/house-robber-ii/
int rob2(const vector<int>& nums);

//https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/
int maxProfit(const vector<int>& prices);

//https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/
int maxProfit122(const vector<int>& prices);

//https://leetcode.cn/problems/coin-change/
int coinChange(const vector<int>& coins, int amount);

//https://leetcode.cn/problems/coin-change-2/
int change518(int amount, const vector<int>& coins);

//https://leetcode.cn/problems/climbing-stairs/
int climbStairs(int n);

int knapsack01(int W, const vector<int>& wt, const vector<int>& val);

//https://leetcode.cn/problems/partition-equal-subset-sum/
bool canPartition416(const vector<int>& nums);

//https://leetcode.cn/problems/perfect-squares/
int numSquares(int n);

//https://leetcode.cn/problems/longest-increasing-subsequence/
int lengthOfLIS(const vector<int>& nums);

//https://leetcode.cn/problems/longest-continuous-increasing-subsequence/
int findLengthOfLCIS(const vector<int>& nums);

//https://leetcode.cn/problems/longest-common-subsequence/
int longestCommonSubsequence(string text1, string text2);

//https://leetcode.cn/problems/minimum-ascii-delete-sum-for-two-strings/
int minimumDeleteSum(string s1, string s2);

//https://leetcode.cn/problems/delete-operation-for-two-strings/
int minDistance(string word1, string word2);

//https://leetcode.cn/problems/maximum-length-of-repeated-subarray/
int findLength(const vector<int>& nums1, const vector<int>& nums2);

//https://leetcode.cn/problems/palindromic-substrings/
int countSubstrings(string s);

//https://leetcode.cn/problems/longest-palindromic-substring/
string longestPalindrome(string s);

//https://leetcode.cn/problems/longest-palindromic-subsequence/
int longestPalindromeSubseq(string s);

//https://leetcode.cn/problems/edit-distance/
int minDistance72(string word1, string word2);

//https://leetcode.cn/problems/word-break/
bool wordBreak(string s, const vector<string>& wordDict);

//https://leetcode.cn/problems/unique-paths/
int uniquePaths(int m, int n);

//https://leetcode.cn/problems/unique-paths-ii/
int uniquePathsWithObstacles(const vector<vector<int>>& obstacleGrid);

//https://leetcode.cn/problems/minimum-path-sum/
int minPathSum(const vector<vector<int>>& grid);

//https://leetcode.cn/problems/maximal-square/
int maximalSquare(const vector<vector<char>>& matrix);

//https://leetcode.cn/problems/maximum-product-subarray/
int maxProduct(const vector<int>& nums);

//https://www.lintcode.com/problem/paint-fence/description
int fenceNumWays(int n, int k);

int cuttingMaxProfit(const vector<int>& prices, int n);

//https://leetcode.cn/problems/combination-sum-iv/
int combinationSum4(const vector<int>& nums, int target);

