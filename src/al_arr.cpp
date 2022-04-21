//
// Created by wenwen on 2022/4/18.
//

#include "al_arr.h"
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <set>

vector<int> twoSum(const vector<int>& nums, int target){
    unordered_map<int, int> mValIdx;
    for(int i = 0; i < nums.size(); ++i){
        int diff = target - nums[i];
        if(mValIdx.count(diff))return {mValIdx[diff], i};

        mValIdx[nums[i]] = i;
    }

    return {};
}

void threeSumHelper(const vector<int>& nums, int startIdx, int target, vector<vector<int>>& vecVec){
    int beg = startIdx, end = int(nums.size()) - 1;

    while(beg < end){
        int tmp = nums[beg] + nums[end];
        if(tmp < target){
            ++beg;
        }else if(tmp > target){
            --end;
        }else{
            vecVec.push_back({nums[beg++], nums[end--]});
        }
    }
}

vector<vector<int>> threeSum(vector<int>& nums){
    std::set<vector<int>> setVec;

    std::stable_sort(nums.begin(), nums.end());
    int len = static_cast<int>(nums.size());

    for(int i = 0; i < len - 2; ++i){
        if(i > 0 and nums[i] == nums[i - 1])continue;

        vector<vector<int>> vecVec;
        int target = -nums[i];
        threeSumHelper(nums, i + 1, target, vecVec);

        for(auto& vec : vecVec){
            vec.insert(vec.begin(), nums[i]);
            setVec.insert(vec);
        }
    }

    vector<vector<int>> vecRes(setVec.begin(), setVec.end());
    return vecRes;
}
