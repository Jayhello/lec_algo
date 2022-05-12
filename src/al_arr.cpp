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


#ifdef USE_3SUM_V1

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
#endif

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
            while(nums[beg] == nums[beg - 1] and beg < end)++beg;
            while(nums[end] == nums[end + 1] and beg < end)--end;
        }
    }
}

vector<vector<int>> threeSum(vector<int>& nums){
    vector<vector<int>> vecVec;
    std::stable_sort(nums.begin(), nums.end());
    if(nums.empty() or nums[0] > 0)return vecVec;

    int len = static_cast<int>(nums.size());
    for(int i = 0; i < len - 2; ++i){
        if(nums[i] > 0) break;
        if(i > 0 and nums[i] == nums[i - 1])continue;
        int target = -nums[i];

        vector<vector<int>> vecTmp;
        threeSumHelper(nums, i + 1, target, vecTmp);

        for(const auto& vec : vecTmp){
            vecVec.push_back({nums[i], vec[0], vec[1]});
        }
    }

    return vecVec;
}

void mergeSortArr(vector<int>& nums1, int m, vector<int>& nums2, int n){
    int pos = m + n - 1;
    int i = m - 1, j = n - 1;
    while(i >= 0 and j >= 0){
        if(nums1[i] >= nums2[j]){
            nums1[pos--] = nums1[i--];
        }else{
            nums1[pos--] = nums2[j--];
        }
    }

    while(j >= 0) nums1[pos--] = nums2[j--];
}

vector<int> sortedSquares(vector<int>& nums) {
    int len = static_cast<int>(nums.size());
    int i = 0, j = len - 1, pos = len - 1;
    vector<int> res(nums.size(), 0);

    while(i <= j){
        int v = nums[i];
        if(std::abs(nums[i]) < std::abs(nums[j])){
            v = nums[j--];
        }else{
            ++i;
        }

        res[pos--] = v * v;
    }

    return res;
}

string reverseOnlyLetters(string s){
    int l = 0, r = static_cast<int>(s.size()) - 1;
    while(l < r){
        bool lFlag = std::isalpha(s[l]), rFlag = std::isalpha(s[r]);
        if(lFlag and rFlag){
            std::swap(s[l++], s[r--]);
        }

        if(not lFlag) ++l;
        if(not rFlag) --r;
    }

    return s;
}

string compressString(string str){
    int len = static_cast<int>(str.size());
    int i = 0;
    string res;

    while(i < len){
        int j = i + 1;
        for(; j < len and str[j] == str[j - 1]; ++j);
        res.push_back(str[i]);
        if(j - i < 10)res.push_back(j - i + '0');
        else res.append(std::to_string(j - i));
        i = j;
    }

    return res.size() < str.size() ? res : str;
}

template<typename Size>
int getNumericSize(Size size){
    int cnt = 0;
    while(size){++cnt; size /= 10;}
    return cnt;
}

int compress(vector<char>& chars){
    int len = chars.size();
    int i = 0, k = 0, cnt = 0;
    while(i < len){
        int j = i + 1;
        for(; j < len and chars[j] == chars[j - 1]; ++j);

        cnt += 1;
        chars[k++] = chars[i];
        int diff = j - i;
        if(diff > 1){
            cnt += getNumericSize(diff);
            string tmp = std::to_string(diff);
            for(auto ch : tmp)chars[k++] = ch;
        }

        i = j;
    }
    return std::min(cnt, len);
}
