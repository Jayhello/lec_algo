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

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

typedef ListNode*  ListNodePtr;
