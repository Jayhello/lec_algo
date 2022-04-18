//
// Created by wenwen on 2022/4/18.
//

#include "al_arr.h"
#include <unordered_map>

vector<int> twoSum(const vector<int>& nums, int target){
    unordered_map<int, int> mValKey;
    for(int i = 0; i < nums.size(); ++i){
        int diff = target - nums[i];
        if(mValKey.count(diff))return {mValKey[diff], i};

        mValKey[nums[i]] = i;
    }

    return {};
}
