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
    if(!head){std::cout << std::endl; return;}
    std::cout << head->val << " ";
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

void helper206(ListNode* head, ListNode* prev, ListNode*& res){
    if(!head)return;
    if(!head->next)res = head;
    helper206(head->next, head, res);
    head->next = prev;
}

ListNode* reverseList(ListNode* head){
    ListNode* res = head;
    helper206(head, nullptr, res);
    return res;
}

ListNode* reverseList2(ListNode* head){
    ListNode* cur = head, *prev = nullptr;
    while(cur){
        ListNode* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    return prev;
}

ListNode* reverseBetween(ListNode* head, int left, int right){
    if(left == right) return head;

    ListNode* cur = head;
    int count = left;
    while(count-- > 1){
        cur = cur->next;
    }

    ListNode* tmp = cur;
    vector<int> vec;
    vec.reserve(right - left + 1);
    for(int i = left; i <= right;++i){
        vec.push_back(cur->val);
        cur = cur->next;
    }

    for(auto it = vec.rbegin(); it != vec.rend(); ++it){
        tmp->val = *it;
        tmp = tmp->next;
    }
    return head;
}

bool hasCycle(ListNode *head){
    if(!head)return false;
    std::unordered_set<ListNode*> setExists;
    while(head){
        if(setExists.count(head)) return true;
        setExists.insert(head);
        head = head->next;
    }

    return false;
}

ListNode *detectCycle(ListNode *head){
    if(!head)return nullptr;
    std::unordered_set<ListNode*> setExists;
    while(head){
        if(setExists.count(head)) return head;
        setExists.insert(head);
        head = head->next;
    }

    return nullptr;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
    std::unordered_set<ListNode*> setExists;
    while(headA){
        setExists.insert(headA);
        headA = headA->next;
    }

    while(headB){
        if(setExists.count(headB)) return headB;
        headB = headB->next;
    }
    return nullptr;
}

int getLength(ListNode* head){
    int len = 0;
    while(head){
        ++len;
        head = head->next;
    }
    return len;
}

ListNode *getIntersectionNode2(ListNode *head1, ListNode *head2){
    int len1 = getLength(head1);
    int len2 = getLength(head2);
    int diff = std::abs(len1 - len2);
    if(len1 > len2){
        while(diff--) head1 = head1->next;
    }else if(len2 > len1){
        while(diff--) head2 = head2->next;
    }

    while(head1 and head2){
        if(head1 == head2) return head1;
        head1 = head1->next;
        head2 = head2->next;
    }

    return nullptr;
}

ListNode* removeElements(ListNode* head, int val){
    ListNode* ptr = head;
    vector<int> vec;
    while(ptr){
        if(ptr->val != val){
            vec.push_back(ptr->val);
        }
        ptr = ptr->next;
    }

    if(vec.empty())return nullptr;
    auto prev = ptr;
    ptr = head;
    for(auto v : vec){
        ptr->val = v;
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = nullptr;
    return head;
}

ListNode* removeElements1(ListNode* head, int val){
    ListNode* cur = nullptr, *next = head;
    while(next){
        if(next->val != val){
            if(!cur){
                cur = head;
                cur->val = next->val;
            }else{
                cur = cur->next;
                cur->val = next->val;
            }
        }
        next = next->next;
    }
    if(!cur){
        return nullptr;
    }else{
        cur->next = nullptr;
    }
    return head;
}

ListNode* deleteDuplicates(ListNode* head){
    if(!head) return head;
    vector<int> vec = {head->val};
    ListNode* ptr = head->next;
    while(ptr){
        if(ptr->val != vec.back()){
            vec.push_back(ptr->val);
        }
        ptr = ptr->next;
    }

    ptr = head;
    ListNode* prev = head;
    for(auto val : vec){
        ptr->val = val;
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = nullptr;
    return head;
}

ListNode* deleteDuplicates1(ListNode* head){
    if(!head or !head->next) return head;

    ListNode* cur = head, *next = head->next;
    while(next){
        if(next->val != cur->val){
            cur = cur->next;
            cur->val = next->val;
        }
        next = next->next;
    }

    cur->next = nullptr;
    return head;
}

ListNode* deleteDuplicates2(ListNode* head){
    ListNode* cur = head;
    unordered_map<int, int> mValCount;
    while(cur){
        ++mValCount[cur->val];
        cur = cur->next;
    }

    cur = head;
    ListNode* prev = nullptr;
    while(cur){
        if(1 == mValCount[cur->val]){
            if(!prev){
                prev = head;
                prev->val = cur->val;
            }else{
                prev = prev->next;
                prev->val = cur->val;
            }
        }
        cur = cur->next;
    }

    if(!prev){
        return prev;
    }else{
        prev->next = nullptr;
    }
    return head;
}

ListNode* mergeTwoLists2(ListNode* list1, ListNode* list2){
    if(!list1) return list2;
    if(!list2) return list1;

    ListNode* head = nullptr;
    if(list1->val <= list2->val){
        head = list1;
        head->next = mergeTwoLists2(list1->next, list2);
    }else{
        head = list2;
        head->next = mergeTwoLists2(list1, list2->next);
    }
    return head;
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

ListNode* helper23(ListNode* list1, ListNode* list2){
    if(!list1) return list2;
    if(!list2) return list1;

    ListNode* head = nullptr;
    if(list1->val <= list2->val){
        head = list1;
        head->next = helper23(list1->next, list2);
    }else{
        head = list2;
        head->next = helper23(list1, list2->next);
    }
    return head;
}

ListNode* mergeKListsV2(vector<ListNode*>& lists) {
    ListNode* res = nullptr;
    for(auto p : lists){
        res = helper23(res, p);
    }
    return res;
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

bool isPalindrome2(ListNode* head){
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

ListNode* swapPairs(ListNode* head){
    if(!head or !head->next) return head;

    ListNode* prev = nullptr, *p1 = head, *p2 = head->next;
    ListNode* res = p2;
    while(p1 and p2){
        ListNode* tmp = p2->next;
        p2->next = p1;
        if(prev){
            prev->next = p2;
        }
        prev = p1;
        p1 = tmp;
        if(p1){
            p2 = p1->next;
        }else{
            p2 = nullptr;
        }
    }
    prev->next = p1;
    return res;
}

ListNode* removeNthFromEnd(ListNode* head, int n){
    ListNode* fast = head;
    while(n-- > 0) 	 fast = fast->next;
    ListNode* prev = nullptr, *cur = head;
    while(fast){
        prev = cur;
        cur = cur->next;
        fast = fast->next;
    }

    if(!prev){
        return head->next;
    }else{
        prev->next = cur->next;
        return head;
    }
}

ListNode* oddEvenList(ListNode* head){
    if(!head or !head->next)	 return head;

    ListNode* odd = head, *even = head->next;
    while(even and even->next){
        ListNode* oddNext = odd->next;
        ListNode* evenNext = even->next;

        odd->next = evenNext;
        odd = odd->next;

        even->next = evenNext->next;
        even = even->next;

        odd->next = oddNext;
    }

    return head;
}
