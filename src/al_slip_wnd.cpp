//
// Created by wenwen on 2022/7/20.
//

#include "al_slip_wnd.h"

#ifdef USE_findMaxConsecutiveOnes_v1

int findMaxConsecutiveOnes(const vector<int>& nums){
    int len = int(nums.size()), i = 0;
    int cnt = 0, max_cnt = 0;
    while(i < len){
        if(1 == nums[i++]){
            ++cnt;
            max_cnt = std::max(max_cnt, cnt);
        }else{
            cnt = 0;
        }
    }

    return max_cnt;
}
#endif

int findMaxConsecutiveOnes(const vector<int>& nums){
    int len = int(nums.size());
    int cnt = 0, left = 0, right = 0;
    while(right < len){
        if(1 == nums[right++]){
            cnt = std::max(cnt, right - left);
        }else{
            left = right;
        }
    }

    return cnt;
}
