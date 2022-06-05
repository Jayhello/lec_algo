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