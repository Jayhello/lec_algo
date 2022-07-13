//
// Created by wenwen on 2022/5/19.
//

#pragma once
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <unordered_set>
#include <cmath>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

typedef ListNode*  ListNodePtr;

inline bool floatEqual(float a, float b, float EPSILON = 0.000001){
    return std::fabs(a - b) < EPSILON;
}

inline bool floatGt(float a, float b, float EPSILON = 0.000001){
    return std::fabs(a - b) >= EPSILON;
}
