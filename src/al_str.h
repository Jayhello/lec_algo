//
// Created by wenwen on 2022/4/18.
//
#pragma once
#include <vector>
#include <string>

using namespace std;

// https://leetcode-cn.com/problems/encode-and-decode-strings/
// 参考 https://www.cnblogs.com/grandyang/p/5265628.html
// 会员题目, 后面在验证
string encode271(const vector<string>& vStr);

vector<string> decode271(const string& str);

string countAndSay_38(int n);

int lengthOfLastWord(string s);

// https://leetcode.cn/problems/reverse-words-in-a-string/
string reverseWords(string s);

// https://leetcode.cn/problems/number-of-segments-in-a-string/
int countSegments(string s);

// https://leetcode.cn/problems/reverse-string-ii/
string reverseStr541(string s, int k);

//https://www.nowcoder.com/questionTerminal/c3120c1c1bc44ad986259c0cf0f0b80e
string transNK(string s, int n);

//https://leetcode.cn/problems/compare-version-numbers/
int compareVersion(string version1, string version2);

// https://leetcode.cn/problems/valid-palindrome/
bool isPalindrome(string s);