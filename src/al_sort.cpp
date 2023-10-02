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

bool canDel(const string& src, const string& dst){
    int i = 0, len = src.size();
    for(auto c : dst){
        for(; i < len and src[i] != c; ++i){
        }

        if(i >= len) return false;
        if(src[i] == c)++i;
    }
    return true;
}

string findLongestWord(string s, vector<string>& dictionary){
    std::stable_sort(dictionary.begin(), dictionary.end(), [](const string& s1, const string& s2){
        if(s1.size() > s2.size()){
            return true;
        }else if(s1.size() == s2.size()){
            return s1 < s2;
        }else{
            return false;
        }
    });

    for(const string& tmp : dictionary){
        if(canDel(s, tmp)){
            return tmp;
        }
    }

    return "";
}

int majorityElement(vector<int>& nums){
    int n = nums[0], count = 1;
    for(int i = 1; i < nums.size(); ++i){
        if(nums[i] == n){
            ++count;
        }else if(--count == 0){
            n = nums[i];
            count = 1;
        }
    }
    return n;
}


int pairCount(vector<int>& nums, vector<int>& vTmp, int b, int m, int e){
    int i = m, j = e, k = e, cnt = 0;
    while(i >= b and j > m){
        if(nums[i] > nums[j]){
            cnt = cnt + (j - m);
            vTmp[k--] = nums[i--];
        }else{
            vTmp[k--] = nums[j--];
        }
    }

    while(i >= b)vTmp[k--] = nums[i--];
    while(j > m)vTmp[k--] = nums[j--];

    for(int i = b; i <= e; ++i){
        nums[i] = vTmp[i];
    }
    return cnt;
}

int reversePairs_(vector<int>& nums, vector<int>& vTmp, int b, int e){
    if(b < e){
        int mid = (b + e) / 2;
        int cnt = reversePairs_(nums, vTmp, b, mid);
        cnt += reversePairs_(nums, vTmp, mid + 1, e);
        cnt += pairCount(nums, vTmp, b, mid, e);
        return cnt;
    }
    return 0;
}

int reversePairs(vector<int>& nums){
    vector<int> vTmp = nums;
    int len = nums.size();
    return reversePairs_(nums, vTmp, 0, len - 1);
}
