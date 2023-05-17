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

//https://leetcode.cn/problems/reverse-linked-list
ListNode* reverseList(ListNode* head);

//https://leetcode.cn/problems/reverse-linked-list-ii
ListNode* reverseBetween(ListNode* head, int left, int right);

ListNode* mergeKLists(vector<ListNode*>& lists);

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);

bool isPalindrome(ListNode* head);

//https://leetcode.cn/problems/linked-list-cycle/
bool hasCycle(ListNode *head);

ListNode *detectCycle(ListNode *head);

//https://leetcode.cn/problems/remove-duplicates-from-sorted-list
ListNode* deleteDuplicates(ListNode* head);


//https://leetcode.cn/problems/remove-linked-list-elements/
ListNode* removeElements(ListNode* head, int val);

//https://leetcode.cn/problems/merge-two-sorted-lists
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);

//https://leetcode.cn/problems/intersection-of-two-linked-lists/
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);

//https://leetcode.cn/problems/swap-nodes-in-pairs
ListNode* swapPairs(ListNode* head);

//https://leetcode.cn/problems/odd-even-linked-list/
ListNode* oddEvenList(ListNode* head);
