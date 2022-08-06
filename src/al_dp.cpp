//
// Created by wenwen on 2022/8/1.
//

#include "al_dp.h"

int maxSubArray(const vector<int>& nums){
    int ret = nums[0], cur_max = nums[0];
    for(int i = 1; i < nums.size(); ++i){
        if(cur_max > 0)cur_max += nums[i];
        else cur_max = nums[i];

        ret = std::max(ret, cur_max);
    }

    return ret;
}

// 下面这个方法错误的(奇数最大或者偶数最大) [2,1,1,2] 其实是 2 + 2
int rob_err(vector<int>& nums){
    int odd = 0, even = 0;
    for(int i = 0; i < int(nums.size()); ++i){
        if(i % 2)odd += nums[i];
        else     even += nums[i];
    }

    return std::max(odd, even);
}

int rob1(const vector<int>& nums){
    if(1 == nums.size()) return nums[0];

    int len = int(nums.size());
    vector<int> dp(len, 0);
    dp[0] = nums[0];
    dp[1] = std::max(nums[1], nums[0]);

    for(int i = 2; i < len; ++i){
        dp[i] = std::max(dp[i - 1], nums[i] + dp[i - 2]);
    }
    return dp[len - 1];
}

int rob(const vector<int>& nums){
    if(1 == nums.size()) return nums[0];

    int prev = nums[0], cur = std::max(nums[0], nums[1]);
    for(int i = 2; i < int(nums.size()); ++i){
        int tmp = cur;
        cur = std::max(cur, nums[i] + prev);
        prev = tmp;
    }

    return cur;
}

int rob2Helper(const vector<int>& nums, int l, int r){
    int prev = nums[l], cur = std::max(nums[l], nums[l + 1]);
    for(int i = l + 2; i <= r; ++i){
        int tmp = cur;
        cur = std::max(cur, prev + nums[i]);
        prev = tmp;
    }

    return cur;
}

int rob2(const vector<int>& nums){
    if(1 == nums.size()) return nums[0];
    if(2 == nums.size()) return std::max(nums[0], nums[1]);
    int len = nums.size();
    int v1 = rob2Helper(nums, 0, len - 2);
    int v2 = rob2Helper(nums, 1, len - 1);
    return std::max(v1, v2);
}

int maxProfit(const vector<int>& prices){
    int len = int(prices.size());
    int cur_min = prices[0], ret = 0;
    for(int i = 1; i < len; ++i){
        ret = std::max(ret, prices[i] - cur_min);
        cur_min = std::min(cur_min, prices[i]);
    }
    return ret;
}

int maxProfit122(const vector<int>& prices){
    int len = int(prices.size());
    int ret = 0;
    for(int i = 1; i < len; ++i){
        ret = std::max(ret, prices[i] - prices[i - 1] + ret);
    }

    return ret;
}

int coinChange(vector<int>& coins, int amount){

}
