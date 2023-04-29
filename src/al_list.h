//
// Created by wenwen on 2022/5/20.
//

#pragma once
#include "al_comm.h"

ListNode* createList(const vector<int>& vec);

void printListFront(ListNode* head);

void printListBack(ListNode* head);

//https://leetcode.cn/problems/palindrome-linked-list/
bool isPalindrome(ListNode* head);

//https://leetcode.cn/problems/kth-node-from-end-of-list-lcci/
int kthToLast(ListNode* head, int k);

ListNode* mergeKLists(vector<ListNode*>& lists);

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);

bool isPalindrome(ListNode* head);

