//
// Created by wenwen on 2022/8/1.
//

#include <numeric>
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

int coinChange1(const vector<int>& coins, int amount){
    if(amount < 0) return -1;
    if(amount == 0) return 0;

    int ret = amount + 1;
    for(auto c : coins){
        if(c > amount) continue;
        int tmp = coinChange(coins, amount - c);
        if(tmp != -1){
            ret = std::min(ret, tmp + 1);
        }
    }

    return ret == amount + 1 ? -1 : ret;
}

int coinChange(const vector<int>& coins, int amount){
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for(int i = 1; i <= amount; ++i){
        for(auto c : coins){
            if(c > i) continue;
            dp[i] = std::min(dp[i], dp[i - c] + 1);
        }
    }

    return dp[amount] == amount + 1 ? -1 : dp[amount];
}

int change518_err(int amount, const vector<int>& coins){
    if(amount <= 0) return 0;

    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for(int i = 1; i <= amount; ++i){
        for(auto c : coins){
            if(c > i) continue;
            dp[i] += dp[i - c];
        }
    }

    return dp[amount];
}

int change518_v2(int amount, const vector<int>& coins){
    if(amount <= 0) return 1;

    vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));

    for(int i = 1; i <= int(coins.size()); ++i)dp[i][0] = 1;

    for(int i = 1; i <= int(coins.size()); ++i){
        for(int m = 1; m <= amount; ++m){
            if(m >= coins[i - 1]){
                dp[i][m] = dp[i - 1][m] + dp[i][m - coins[i - 1]];
            }else{
                dp[i][m] = dp[i - 1][m];
            }
        }
    }

    return dp[coins.size()][amount];
}

int change518(int amount, const vector<int>& coins){
    if(amount <= 0) return 1;

    vector<int> dp(amount + 1, 0);
    dp[0] = 1;

    for(auto coin : coins){
        for(int m = 1; m <= amount; ++m){
            if(m < coin)continue;

            dp[m] = dp[m] + dp[m - coin];
        }
    }

    return dp[amount];
}

int climbStairs(int n){
    if(n < 3) return n;
    vector<int> dp(n , 0);
    dp[1] = 1;dp[2] = 2;
    for(int i = 3; i <= n; ++i){
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// m >= 2
int climbStairs2(int n, int m){
    if(n < 3) return n;
    vector<int> dp(n , 0);
    dp[1] = 1;dp[2] = 2;
    for(int i = 3; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(i - j >= 0)dp[i] += dp[i - j];
        }
    }
    return dp[n];
}

int knapsack01(int W, const vector<int>& wt, const vector<int>& val){
    vector<vector<int>> dp(1 + wt.size(), vector<int>(W + 1, 0));

    for(int j = 1; j <= wt.size(); ++j){
        for(int w = 1; w <= W; ++w){
            if(wt[j - 1] <= w){
                dp[j][w] = std::max(dp[j - 1][w], dp[j - 1][w - wt[j - 1]] + val[j - 1]);
            }else{
                dp[j][w] = dp[j - 1][w];
            }
        }
    }

    return dp[wt.size()][W];
}

bool canPartition416(const vector<int>& nums){
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    if(sum % 2) return false;
    int n = sum / 2, len = int(nums.size());
    vector<vector<bool>> dp(1 + len, vector<bool>(n + 1, false));
    for(int i = 0; i <= len; ++i)dp[i][0] = true;

    for(int i = 1;i <= len; ++i){
        for(int w = 1; w <= n; ++w){
            if(nums[i - 1] <= w){
                dp[i][w] = (dp[i - 1][w] or dp[i - 1][w - nums[i - 1]]);
            }else{
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[len][n];
}

int numSquares(int n){
    if(n <= 1) return n;

    int k = n / 2;

    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));

    for(int i = 1; i <= k; ++i){
        int r = i * i;
        if(r > n){
            k = i - 1;
            break;
        }

        for(int j = 1; j <= n; ++j){
            if(r > j){
                dp[i][j] = dp[i - 1][j];
            }else{
                if(0 == dp[i - 1][j]){
                    dp[i][j] = dp[i][j - r] + 1;
                }else{
                    dp[i][j] = std::min(dp[i - 1][j], dp[i][j - r] + 1);
                }
            }
        }
    }

    return dp[k][n];
}

int combinationSum4(const vector<int>& nums, int target){
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for(int i = 1; i <= target; ++i){
        for(auto c : nums){
            if(c > i) continue;
            dp[i] += dp[i - c];
        }
    }

    return dp[target];
}
