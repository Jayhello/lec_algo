//
// Created by wenwen on 2022/5/17.
//

#include "al_heap.h"

int lastStoneWeight(const vector<int>& stones){
    priority_queue<int> que(stones.begin(), stones.end());

    while(que.size() > 1){
       int n1 = que.top();
       que.pop();
       int n2 = que.top();
       que.pop();
       if(n1 > n2){
           que.push(n1 - n2);
       }
    }

    return que.empty() ? 0 : que.top();
}

vector<int> getLeastNumbers(vector<int>& arr, int k){
    if(k <= 0) return {};
    if(arr.size() < k) return arr;

    priority_queue<int> que(arr.begin(), arr.begin() + k);
    for(int i = k; i < arr.size(); ++i){
        if(que.top() > arr[i]){
            que.pop();
            que.push(arr[i]);
        }
    }

    vector<int> res(que.size());
    for(int i = 0; i < res.size(); ++i){
        res[i] = que.top();
        que.pop();
    }

    return res;
}

struct NumCount{
    int n, c;
};

bool operator < (const NumCount& lhs, const NumCount& rhs){
    return lhs.c > rhs.c;
}

typedef priority_queue<NumCount> NumCountQueue;

vector<int> topKFrequent(vector<int>& nums, int k){
    typedef std::pair<int, int> NumCount;

    std::unordered_map<int, int> mNC;
    for(auto n : nums)mNC[n]++;

    NumCountQueue que;
    for(const auto& item : mNC){
        if(que.size() < k){
            que.push({item.first, item.second});
        }else{
            if(que.top().c < item.second){
                que.pop();
                que.push({item.first, item.second});
            }
        }
    }

    vector<int> res;
    res.reserve(que.size());
    while(not que.empty()){
        res.insert(res.begin(), que.top().n);
        que.pop();
    }

    return res;
}
