//
// Created by wenwen on 2022/5/24.
//
#pragma once

#include "al_comm.h"

// https://leetcode.cn/problems/valid-parentheses/
bool isValid20(string s);

//https://leetcode.cn/problems/simplify-path/
string simplifyPath(string path);

//https://leetcode.cn/problems/backspace-string-compare/
bool backspaceCompare(string s, string t);

//https://leetcode.cn/problems/baseball-game/
int calPoints(vector<string>& ops);

// https://leetcode.cn/problems/evaluate-reverse-polish-notation/
int evalRPN(vector<string>& tokens);

// https://leetcode.cn/problems/basic-calculator/solution/chai-jie-fu-za-wen-ti-shi-xian-yi-ge-wan-zheng-j-2/
// 拆解复杂问题：实现一个完整计算器
// 第一个版本, 没有括号仅仅加减
int calcExpress1(const string& sExpress);

// 支持 +-()
int calcExpress11(const string& sExpress);

//https://leetcode.cn/problems/basic-calculator-ii/
int calcExpress227(const string& sExpress);

// 在1的基础上支持 * / , 但是不支持(), * / 不支持负数
int calcExpress2(const string& sExpress);

// 支持 + - * / ()
int calcExpress3(const string& sExpress);

// todo
// https://leetcode.cn/problems/design-circular-queue/
