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

//https://leetcode.cn/problems/longest-palindrome/
int longestPalindrome(string s);

//https://leetcode.cn/problems/palindrome-permutation-lcci/
bool canPermutePalindrome(string s);

//https://leetcode.cn/problems/palindrome-number/
bool isPalindrome(int x);

// https://leetcode.cn/problems/valid-palindrome-ii/
bool validPalindrome680(string s);

// https://leetcode.cn/problems/add-strings/
string addStrings(string num1, string num2);

// https://leetcode.cn/problems/multiply-strings/
string multiply43(string num1, string num2);

//https://www.nowcoder.com/questionTerminal/e9a4919b8848451d9aff81e3cdd133b1
string powOf2NK(int n);

float StrToFloat(const std::string& str);

string float2String(float f);

//https://www.nowcoder.com/questionTerminal/66ca0e28f90c42a196afd78cc9c496ea
uint32_t ip2Int(const string& sIP);

string int2ip(uint32_t iIp);

// Split("abc.def.ghc", '.') ->   {abc, def, ghc}
// Split("/home/xy/code", '/') -> {home, xy, code}

vector<string> Split(const string& str, char ch);

;  // "12341256", "12" -> {"34", "56"}
;  // "111112", "11" -> {"12"}
;  // "56123412", "12" -> {"56", "34"}
vector<string> splitString(const std::string& str, const std::string& split);

//https://leetcode.cn/problems/Implement-strStr/
int strStr(string haystack, string needle);

//https://leetcode.com/problems/longest-substring-without-repeating-characters/
string lengthOfLongestSubstring(string s);

//https://leetcode.cn/problems/ti-huan-kong-ge-lcof/
string replaceSpace(string s);

//https://leetcode.cn/problems/rotate-string/
bool rotateString(string s, string goal);

//https://leetcode.cn/problems/repeated-substring-pattern/
bool repeatedSubstringPattern(string s);

//https://leetcode.cn/problems/repeated-string-match/
int repeatedStringMatch(string a, string b);

//https://leetcode-cn.com/problems/long-pressed-name/
bool isLongPressedName(string name, string typed);

//https://leetcode.cn/problems/longest-word-in-dictionary-through-deleting/
string findLongestWord(string s, vector<string>& dictionary);


// https://leetcode.cn/problems/backspace-string-compare/
bool backspaceCompare(string s, string t);
