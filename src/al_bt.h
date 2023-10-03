//
// Created by wenwen on 2022/9/26.
//
#pragma once

#include <vector>
#include <string>

using namespace std;

// https://leetcode.cn/problems/permutations/
vector<vector<int>> permute46(const vector<int>& nums);

//https://leetcode.cn/problems/permutations-ii/
vector<vector<int>> permuteUnique(vector<int>& nums);

//https://leetcode.cn/problems/permutation-sequence/description/
string getPermutation(int n, int k);

// 这题非排列问题, 也不好做
// https://leetcode.cn/problems/next-permutation
void nextPermutation(std::vector<int>& nums);

//https://leetcode.cn/problems/letter-case-permutation/
vector<string> letterCasePermutation(string s);

//https://leetcode.cn/problems/combinations/
vector<vector<int>> combine(int n, int k);

//https://leetcode.cn/problems/palindrome-partitioning/
vector<vector<string>> partition131(string s);

//https://leetcode.cn/problems/word-break/
bool wordBreak139(string s, const vector<string>& wordDict);

//https://leetcode.cn/problems/combination-sum-iii/
vector<vector<int>> combinationSum3(int k, int n);

//https://leetcode.cn/problems/combination-sum/
vector<vector<int>> combinationSum(vector<int>& candidates, int target);

//https://leetcode.cn/problems/combination-sum-ii/
vector<vector<int>> combinationSum2(vector<int>& candidates, int target);

//https://leetcode.cn/problems/combination-sum-iv/description/
int combinationSum4(vector<int>& nums, int target);

//https://leetcode.cn/problems/letter-combinations-of-a-phone-number/
vector<string> letterCombinations(string digits);

//https://leetcode.cn/problems/partition-to-k-equal-sum-subsets/
// 这题有点难, 以后有空在做吧
bool canPartitionKSubsets(vector<int>& nums, int k);

//https://leetcode.cn/problems/restore-ip-addresses
vector<string> restoreIpAddresses(string s);

//https://leetcode.cn/problems/subsets/
vector<vector<int>> subsets(vector<int>& nums);

//https://leetcode.cn/problems/subsets-ii/
vector<vector<int>> subsetsWithDup(vector<int>& nums);

//https://leetcode.cn/problems/word-search/
bool exist(vector<vector<char>>& board, string word);

//https://leetcode.cn/problems/generate-parentheses/
vector<string> generateParenthesis(int n);

//https://leetcode.cn/problems/binary-watch/
vector<string> readBinaryWatch(int turnedOn);

//https://leetcode.cn/problems/sudoku-solver/
void solveSudoku(vector<vector<char>>& board);

//https://leetcode.cn/problems/n-queens/
vector<vector<string>> solveNQueens(int n);

//https://leetcode.cn/problems/expression-add-operators/
vector<string> addOperators(string num, int target);

//https://leetcode.cn/problems/target-sum/
int findTargetSumWays(const vector<int>& nums, int target);

//https://leetcode.cn/problems/partition-equal-subset-sum/description/
bool canPartition(vector<int>& nums);

//https://leetcode.cn/problems/word-break/
bool wordBreak(string s, const vector<string>& wordDict);

//https://leetcode.cn/problems/word-ladder/description/
int ladderLength(string beginWord, string endWord, vector<string>& wordList);
