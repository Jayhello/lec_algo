//
// Created by wenwen on 2022/4/18.
//

#include "al_sort.h"

void heapAdjust(vector<int>& nums, int beg, int end){
    while(beg < end){
        int i = 2 * beg + 1;
        if(i > end) break;

        if(i + 1 <= end and nums[i + 1] > nums[i]){
            i += 1;
        }

        if(nums[beg] >= nums[i]) break;

        std::swap(nums[beg], nums[i]);
        beg = i;
    }
}

void heapSort1(vector<int>& nums){
    int len = nums.size();

    for(int i = len / 2 - 1; i >= 0; --i){
        heapAdjust(nums, i, len - 1);
    }

    for(int i = 0; i < len - 1; ++i){
        std::swap(nums[0], nums[len - 1 - i]);
        heapAdjust(nums, 0, len - 1 - i - 1);
    }
}

int findKthLargest11(const vector<int>& nums, int k) {
    std::multiset<int, std::greater<int>> orders(nums.begin(), nums.begin() + k);
    for(int i = k; i < nums.size(); ++i){
        auto it = --orders.end();
        if(*it > nums[k]){
            orders.erase(it);
            orders.insert(nums[k]);
        }
    }

    auto it = --orders.end();
    return *it;
}

int findKthLargest_2(const vector<int>& nums, int k) {
    std::multiset<int> orders(nums.begin(), nums.begin() + k);
    for(int i = k; i < nums.size(); ++i){
        auto it = orders.begin();
        if(nums[i] > *it){
            orders.erase(it);
            orders.insert(nums[i]);
        }
    }

    return *orders.begin();
}

int findKthLargest_3(const vector<int>& nums, int k) {
    std::priority_queue<int, vector<int>, std::greater<int>> orders(nums.begin(), nums.begin() + k);
    for(int i = k; i < nums.size(); ++i){
        auto it = orders.top();
        if(nums[i] > it){
            orders.pop();
            orders.push(nums[i]);
        }
    }

    return orders.top();
}

vector<int> topKFrequent5(vector<int>& nums, int k) {
    map<int, int> mValCnt;
    vector<int> vUniq;
    for(auto n : nums){
        ++mValCnt[n];
        if(1 == mValCnt[n]) vUniq.push_back(n);
    }

    std::stable_sort(vUniq.begin(), vUniq.end(), [&](int v1, int v2){
        return mValCnt[v1]  > mValCnt[v2];
    });

    vector<int> res(vUniq.begin(), vUniq.begin() + k);
    return res;
}

int thirdMax(vector<int>& nums){
    int len = nums.size();
    set<int> orders;
    int i = 0;
    for(; i < len and orders.size() < 3; ++i)
        orders.insert(nums[i]);

    for(; i < len; ++i){
        if(0 == orders.count(nums[i]) and nums[i] > *orders.begin()){
            orders.erase(orders.begin());
            orders.insert(nums[i]);
        }
    }
    return orders.size() >= 3 ? *orders.begin() : *(--orders.end());
}

vector<int> exchange21(vector<int>& nums) {
    int len = nums.size();
    int i = 0, j = len - 1;
    while(i < j){
        if(nums[i] % 2 == 1){
            ++i;
        }else if(nums[j] % 2 == 0){
            --j;
        }else{
            std::swap(nums[i++], nums[j--]);
        }
    }
    return nums;
}
