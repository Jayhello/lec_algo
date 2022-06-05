//
// Created by wenwen on 2022/4/18.
//
#pragma once
#include <vector>
#include <string>

using namespace std;

vector<int> twoSum(const vector<int>& nums, int target);

vector<vector<int>> threeSum(vector<int>& nums);

// https://leetcode-cn.com/problems/merge-sorted-array/
void mergeSortArr(vector<int>& nums1, int m, vector<int>& nums2, int n);

vector<int> sortedSquares(vector<int>& nums);

// https://leetcode-cn.com/problems/reverse-only-letters
string reverseOnlyLetters(string s);

// https://leetcode-cn.com/problems/compress-string-lcci/
string compressString(string str);

// 和上面的类似
int compress(vector<char>& chars);

void heapSort(vector<int>& arr);
