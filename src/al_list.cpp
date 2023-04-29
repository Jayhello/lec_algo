//
// Created by wenwen on 2022/5/20.
//

#include "al_list.h"


struct NodePtrComp{
    bool operator()(const ListNodePtr& lhs, const ListNodePtr & rhs)const{
        return lhs->val < rhs->val;
    }
};

ListNode* createList(const vector<int>& vec){
    if(vec.empty()) return nullptr;

    ListNode* head = new ListNode(vec[0]);
    ListNode* ptr = head;
    for(int i = 1; i < vec.size(); ++i){
        ListNode* tmp = new ListNode(vec[i]);
        ptr->next = tmp;
        ptr = tmp;
    }

    return head;
}

void printListFront(ListNode* head){
    if(!head)return;
    std::cout << head->val;
    printListFront(head->next);
}

void printListFront2(ListNode* head){
    while(head){
        std::cout << head->val;
        head = head->next;
    }
}

void printListBack(ListNode* head){
    if(!head)return;
    printListBack(head->next);
    std::cout << head->val;
}

void printListBack1(ListNode* head){
    std::stack<ListNode*> sta;
    while(head){
        sta.push(head);
        head = head->next;
    }

    while(not sta.empty()){
        auto tmp = sta.top();
        std::cout << tmp->val;
        sta.pop();
    }
}

bool isPalindrome(ListNode* head){
    vector<int> vec;
    ListNode* ptr = head;
    while(ptr){
        vec.push_back(ptr->val);
        ptr = ptr->next;
    }

    int len = vec.size(), cnt = len / 2, i = len - 1;
    for(int c = 0; c < cnt; ++c){
        if(vec[i - c] != head->val){
            return false;
        }
        head = head->next;
    }

    return true;
}

int kthToLast(ListNode* head, int k){
    ListNode* ptr = head;

    while(k-- > 0)ptr = ptr->next;
    while(ptr){
        ptr = ptr->next;
        head = head->next;
    }
    return head->val;
}

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
