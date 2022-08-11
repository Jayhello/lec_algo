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

//https://leetcode.cn/problems/combination-sum-iv/
int combinationSum4(const vector<int>& nums, int target);

