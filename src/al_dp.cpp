//
// Created by wenwen on 2022/8/1.
//

#include <numeric>
#include <algorithm>
#include <map>
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

int coinChange2(const vector<int>& coins, int amount){
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

int coinChange1(const vector<int>& coins, int amount){
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

int coinChange(const vector<int>& coins, int amount){
    if(0 == amount) return 0;

    int len = int(coins.size());
    vector<vector<int>> dp(len + 1, vector<int>(amount + 1, 0));
    for(int i = 1; i <= len; ++i){
        for(int m = 1; m <= amount; ++m){
            if(coins[i - 1] > m){
                dp[i][m] = dp[i - 1][m];
            }else{
                if(0 == dp[i - 1][m]){
                    dp[i][m] = dp[i][m - coins[i - 1]] + 1;
                }else{
                    dp[i][m] = std::min(dp[i - 1][m], dp[i][m - coins[i - 1]] + 1);
                }
            }
        }
    }

    return 0 == dp[len][amount] ? -1 : dp[len][amount];
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

int change518_v3(int amount, const vector<int>& coins){
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

int change518(int amount, const vector<int>& coins){
    if(amount <= 0) return 0;

    int len = int(coins.size());
    vector<vector<int>> dp(len + 1, vector<int>(amount + 1, 0));
    for(int i = 1; i <= len; ++i){
        dp[i][0] = 1;
    }

    for(int i = 1; i <= len; ++i){
        for(int m = 1; m <= amount; ++m){
            if(coins[i - 1] > m){
                dp[i][m] = dp[i - 1][m];
            }else{
                dp[i][m] = dp[i - 1][m] + dp[i][m - coins[i - 1]];
            }
        }
    }

    return dp[len][amount];
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



int knapsackAll(int W, const vector<int>& wt, const vector<int>& val){
    int n = int(wt.size());
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for(int i = 1; i <= n; ++i){
        for(int w = 1; w <= W; ++w){
            if(wt[i - 1] > w){
                dp[i][w] = dp[i - 1][w];
            }else{
                dp[i][w] = std::max(dp[i - 1][w], dp[i][w - wt[i - 1]] + val[i - 1]);
            }
        }
    }
    return dp[n][W];
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
    int k = 1;
    while(k * k <= n)++k;
    --k;

    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));

    for(int i = 1; i <= k; ++i){
        int r = i * i;

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

int lengthOfLIS(const vector<int>& nums){
    int len = int(nums.size());
    vector<int> dp(len, 1);
    int ret = 1;

    for(int i = 1; i < len; ++i){
        for(int j = i - 1; j >= 0; --j){
            if(nums[i] > nums[j]){
                dp[i]= std::max(dp[j] + 1, dp[i]);
                ret = std::max(ret, dp[i]);
            }
        }
    }

    return ret;
}

int findLengthOfLCIS(const vector<int>& nums){
    int cnt = 1, ret = 1;
    int len = int(nums.size()), i = 1;
    while(i < len){
        if(nums[i] > nums[i - 1]){
            cnt += 1;
            ret = std::max(ret, cnt);
        }else{
            cnt = 1;
        }
        ++i;
    }
    return ret;
}

int longestCommonSubsequence(string text1, string text2){
    int len1 = int(text1.size()), len2 = int(text2.size());
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

    for(int i = 0; i < len1; ++i){
        for(int j = 0; j < len2; ++j){
            if(text1[i] != text2[j]){
                dp[i + 1][j + 1] = std::max(dp[i + 1][j], dp[i][j + 1]);
            }else{
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }
        }
    }

    return dp[len1][len2];
}

int minimumDeleteSum(string s1, string s2){
    int sum = 0;
    for(auto c : s1)sum += c;
    for(auto c : s2)sum += c;

    int len1 = int(s1.size()), len2 = int(s2.size());
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
    for(int r = 0; r < len1; ++r){
        for(int c = 0; c < len2; ++c){
            if(s1[r] == s2[c]){
                dp[r + 1][c + 1] = dp[r][c] + s1[r];
            }else{
                dp[r + 1][c + 1] = std::max(dp[r + 1][c], dp[r][c + 1]);
            }
        }
    }

    return sum - dp[len1][len2] * 2;
}

int minDistance(string word1, string word2){
    int len1 = int(word1.size()), len2 = int(word2.size());
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
    for(int i = 1; i <= len1; ++i)dp[i][0] = i;
    for(int i = 1; i <= len2; ++i)dp[0][i] = i;

    for(int r = 0; r < len1; ++r){
        for(int c = 0; c < len2; ++c){
            if(word1[r] == word2[c]){
                dp[r + 1][c + 1] = dp[r][c];
            }else{
                dp[r + 1][c + 1] = std::min(dp[r + 1][c], dp[r][c + 1]) + 1;
            }
        }
    }

    return dp[len1][len2];
}

int findLength(const vector<int>& nums1, const vector<int>& nums2){
    int len1 = int(nums1.size()), len2 = int(nums2.size());
    int ret = 0;
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
    for(int r = 0; r < len1; ++r){
        for(int c = 0; c < len2; ++c){
            if(nums1[r] == nums2[c]){
                dp[r + 1][c + 1] = dp[r][c] + 1;
                ret = std::max(ret, dp[r + 1][c + 1]);
            }else{
                dp[r + 1][c + 1] = 0;
            }
        }
    }

    return ret;
}

int countSubstrings(string s){
    int ret = 0, len = int(s.size());
    vector<vector<bool>> dp(len, vector<bool>(len, false));
    for(int r = len - 1; r >= 0; --r){
        for(int c = r; c < len; ++c){
            if(s[r] == s[c]){
                if(c - r < 2 or dp[r + 1][c - 1]){
                    dp[r][c] = true;
                    ++ret;
                }
            }
        }
    }

    return ret;
}

string longestPalindrome(string s){
    int b = 0, e = 0, len = int(s.size());
    vector<vector<bool>> dp(len, vector<bool>(len, false));
    for(int r = len - 1; r >= 0; --r){
        for(int c = r; c < len; ++c){
            if(s[r] == s[c]){
                if(c - r < 2 or dp[r + 1][c - 1]){
                    dp[r][c] = true;
                    if(c - r > e - b){
                        b = r;
                        e = c;
                    }
                }
            }
        }
    }

    return s.substr(b, e - b + 1);
}

int longestPalindromeSubseq(string s){
    int len = int(s.size()), ret = 0;
    vector<vector<int>> dp(len, vector<int>(len, 0));
    for(int r = len - 1; r >= 0; --r){
        for(int c = r; c < len; ++c){
            if(s[r] == s[c]){
                if(c - r < 2){
                    dp[r][c] = c - r + 1;
                }else{
                    dp[r][c] = dp[r + 1][c - 1] + 2;
                }
            }else{
                dp[r][c] = std::max(dp[r][c - 1], dp[r + 1][c]);
            }
            ret = std::max(ret, dp[r][c]);
        }
    }
    
    return ret;
}

int minDistance72(string word1, string word2){
    int len1 = int(word1.size()), len2 = int(word2.size());
    vector<vector<int>> dp(len1, vector<int>(len2, 0));

    for(int r = 1; r < len1; ++r)dp[r][0] = r;
    for(int c = 1; c < len2; ++c)dp[0][c] = c;

    for(int r = 0; r < len1; ++r){
        for(int c = 0; c < len2; ++c){

        }
    }

    return dp[len1][len2];
}

bool wordBreak1(string s, const vector<string>& wordDict){
    int len = int(s.size());
    vector<bool> dp(len + 1, false);
    dp[0] = true;

    auto range_match = [&s](int idx, const string& word){
        for(int i = 0; i < (word.size()); ++i){
            if(s[idx + i] != word[i])return false;
        }

        return true;
    };

    for(int i = 1; i <= len; ++i){
        for(const auto& word : wordDict){
            if(word.size() > i) continue;
            int start = i - int(word.size());
            if(dp[start]){
                bool match = range_match(start, word);
                if(match){
                    dp[i] = true;
                    break;
                }
            }
        }
    }

    return dp[len];
}

int uniquePaths(int m, int n){
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for(int c = 0; c < n; ++c)dp[0][c] = 1;
    for(int r = 0; r < m; ++r)dp[r][0] = 1;

    for(int r = 1; r < m; ++r){
        for(int c = 1; c < n; ++c){
            dp[r][c] = dp[r][c - 1] + dp[r - 1][c];
        }
    }

    return dp[m - 1][n - 1];
}

int uniquePathsWithObstacles(const vector<vector<int>>& obstacleGrid){
    int row = int(obstacleGrid.size());
    int col = int(obstacleGrid[0].size());

    vector<vector<int>> dp(row, vector<int>(col, 0));
    for(int c = 0; c < col and !obstacleGrid[0][c]; ++c)dp[0][c] = 1;
    for(int r = 0; r < row and !obstacleGrid[r][0]; ++r)dp[r][0] = 1;

    for(int r = 1; r < row; ++r){
        for(int c = 1; c < col; ++c){
            if(obstacleGrid[r][c])continue;

            dp[r][c] = dp[r][c - 1] + dp[r - 1][c];
        }
    }

    return dp[row - 1][col - 1];
}

int minPathSum(const vector<vector<int>>& grid){
    int row = int(grid.size());
    int col = int(grid[0].size());

    vector<vector<int>> dp(row, vector<int>(col, 0));
    dp[0][0] = grid[0][0];
    for(int c = 1; c < col; ++c)dp[0][c] = dp[0][c-1] + grid[0][c];
    for(int r = 1; r < row; ++r)dp[r][0] = dp[r-1][0] + grid[r][0];

    for(int r = 1; r < row; ++r){
        for(int c = 1; c < col; ++c){
            dp[r][c] = grid[r][c] + std::min(dp[r][c - 1], dp[r - 1][c]);
        }
    }

    return dp[row - 1][col - 1];
}

int maximalSquare(const vector<vector<char>>& matrix){
    int row = int(matrix.size()), col = int(matrix[0].size());
    int len = 0;
    vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));

    for(int r = 0; r < row; ++r){
        for(int c = 0; c < col; ++c){
            if('0' == matrix[r][c])continue;

            int w = std::min(dp[r][c], std::min(dp[r+1][c], dp[r][c+1]));
            dp[r + 1][c + 1] = w + 1;
            len = std::max(len, dp[r + 1][c + 1]);
        }
    }

    return len * len;
}

int maxProduct1(const vector<int>& nums){
    using MinMax = std::pair<int, int>;
    int len = int(nums.size()), ret = nums[0];
    vector<MinMax>  dp(len, {ret, ret});
    for(int i = 1; i < len; ++i){
        int tmp = nums[i];
        if(0 == tmp){
            dp[i] = {0, 0};
        }else{
            if(0 == dp[i - 1].first){
                dp[i] = {nums[i], nums[i]};
            }else{
               int n1 = tmp * dp[i - 1].first;
               int n2 = tmp * dp[i - 1].second;
               int mi = std::min(tmp, std::min(n1, n2));
               int ma = std::max(tmp, std::max(n1, n2));
               dp[i].first = mi;
               dp[i].second = ma;
               tmp = ma;
            }
        }

        ret = std::max(tmp, ret);
    }

    return ret;
}

int maxProduct(const vector<int>& nums){
    int len = int(nums.size()), ret = nums[0];
    int iMin = ret, iMax = ret;

    for(int i = 1; i < len; ++i){
        int tmp = nums[i];
        if(0 == tmp){
            iMin = iMax = 0;
        }else{
            if(0 == iMin){
                iMin = iMax = nums[i];
            }else{
                int n1 = tmp * iMin;
                int n2 = tmp * iMax;
                iMin = std::min(tmp, std::min(n1, n2));
                iMax = std::max(tmp, std::max(n1, n2));
            }
        }

        ret = std::max(iMax, ret);
    }

    return ret;
}

int fenceNumWays(int n, int k){

}

int cuttingMaxProfit(const vector<int>& prices, int n){

}

int combinationSum4_v2(const vector<int>& nums, int target){
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

int combinationSum4(const vector<int>& nums, int target){
    int len = int(nums.size());
    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for(int m = 1; m <= target; ++m){
        for(auto n : nums){
            if(n > m) continue;
            dp[m] += dp[m - n];
        }
    }

    return dp[len];
}

bool canReach(string s, int minJump, int maxJump){
    int len = int(s.size());
    vector<bool> dp(len, false);
    dp[0] = true;

    for(int i = 1; i < len; ++i){
        if('0' != s[i]) continue;

        int b = (i - maxJump >= 0 ? i - maxJump : 0);
        int e = (i - minJump);
        while(b <= e){
            if(dp[e--]){
                dp[i] = true;
                break;
            }
        }
    }

    return dp[len - 1];
}

bool canJump(vector<int>& nums){
    int len = int(nums.size());
    if(0 == nums[0]){
        return 1 == len ? true : false;
    }
    vector<int> dp(nums);
    int idx = 1;
    for(; idx < len; ++idx){
        dp[idx] = std::max(dp[idx], dp[idx - 1] - 1);
        if(0 == dp[idx])break;
    }

    return idx >= (len - 1);
}


int jump45(vector<int>& nums){
    int len = int(nums.size());
    vector<int> dp(len, len + 1);
    dp[0] = 0;
    for(int j = 1; j < len; ++j){
        for(int i = j - 1; i >= 0; --i){
            if(nums[i] >= j - i){
                dp[j] = std::min(dp[j], dp[i] + 1);
            }
        }
    }
    return dp[len - 1];
}

int deleteAndEarn(vector<int>& nums){
    std::map<int, int> mNumCnt;
    for(auto n : nums) mNumCnt[n] += n;

    int len = mNumCnt.size();
    vector<int> dp;
    for(const auto& kv : mNumCnt)dp.push_back(kv.second);

    int i = 1;
    auto it = ++mNumCnt.begin();
    while(it != mNumCnt.end()){
        auto prev = std::prev(it);
        if(prev->first + 1 != it->first){
            dp[i] += dp[i - 1];
        }else{
            if(i >= 2){
                dp[i] = std::max(dp[i - 1], dp[i - 2] + dp[i]);
            }else{
                dp[i] = std::max(dp[i], dp[i - 1]);
            }
        }
        ++i;
        ++it;
    }

    return dp[len - 1];
}

