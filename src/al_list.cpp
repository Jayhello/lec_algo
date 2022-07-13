//
// Created by wenwen on 2022/5/20.
//

#include "al_list.h"

struct NodePtrComp{
    bool operator()(const ListNodePtr& lhs, const ListNodePtr & rhs)const{
        return lhs->val < rhs->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists){
    multiset<ListNodePtr, NodePtrComp> nodeSet;

    for(auto head : lists){
        while (head){
            nodeSet.insert(head);
            head = head->next;
        }
    }

    ListNode dummy;
    ListNodePtr tmp = &dummy;

    for(auto ptr : nodeSet){
        tmp->next = ptr;
        tmp = tmp->next;
    }

    tmp->next = nullptr;
    return dummy.next;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
    ListNode dummy;
    ListNode* ptr = &dummy;

    while(list1 and list2){
        if(list1->val < list2->val){
            ptr->next = list1;
            list1 = list1->next;
        }else{
            ptr->next = list2;
            list2 = list2->next;
        }

        ptr = ptr->next;
    }

    if(list1) ptr->next = list1;
    if(list2) ptr->next = list2;

    return dummy.next;
}

#ifdef isPalindrome_V1
bool isPalindrome(ListNode* head){
    stack<ListNode*> sta;
    ListNode* tmp = head;
    while(tmp){
        sta.push(tmp);
        tmp = tmp->next;
    }

    while(not sta.empty() and sta.top()->val == head->val){
        sta.pop();
        head = head->next;
    }

    return sta.empty();
}
#endif

bool isPalindrome(ListNode* head){
    stack<ListNode*> sta;
    ListNode* tmp = head;
    while(tmp){
        sta.push(tmp);
        tmp = tmp->next;
    }

    int cnt = int(sta.size()) / 2;
    while(cnt and sta.top()->val == head->val){
        sta.pop();
        head = head->next;
        --cnt;
    }

    return 0 == cnt;
}