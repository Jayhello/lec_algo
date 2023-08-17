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

//https://leetcode.cn/problems/spiral-matrix/
vector<int> spiralOrder(vector<vector<int>>& matrix);

vector<vector<int>> generateMatrix(int n);

string convert6(string s, int row);

vector<int> exchange(vector<int>& nums);

//https://leetcode.cn/problems/remove-duplicates-from-sorted-array/
int removeDuplicates(vector<int>& nums);

//https://leetcode.cn/problems/remove-duplicates-from-sorted-array-ii/
int removeDuplicates2(vector<int>& nums);

//https://leetcode.cn/problems/remove-element/
int removeElement(vector<int>& nums, int val);

//https://leetcode.cn/problems/move-zeroes/
void moveZeroes(vector<int>& nums);

//https://leetcode.cn/problems/merge-sorted-array/
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);

//https://leetcode.cn/problems/container-with-most-water/
int maxArea(vector<int>& height);

//https://leetcode.cn/problems/largest-rectangle-in-histogram/
int largestRectangleArea(vector<int>& heights);

//https://leetcode.cn/problems/search-insert-position/
int searchInsert(vector<int>& nums, int target);

//https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/
vector<int> searchRange(vector<int>& nums, int target);

//https://leetcode.cn/problems/search-in-rotated-sorted-array/
int search33(vector<int>& nums, int target);

int threeSumClosest(vector<int>& nums, int target);

