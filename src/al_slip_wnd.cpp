//
// Created by wenwen on 2022/7/20.
//

#include "al_slip_wnd.h"
#include <unordered_map>
#include <climits>

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

bool includeMap(const unordered_map<char, int>& m1, const unordered_map<char, int>& m2){
    for(auto kv : m2){
        auto it = m1.find(kv.first);
        if(it == m1.end() or kv.second > it->second){
            return false;
        }
    }
    return true;
}

//#define minWindow_V1
#ifdef minWindow_V1
string minWindow(string s, string t){
    int cnt = 0;
    unordered_map<char, int> mt;
    for(auto ch : t){
        ++mt[ch];
        ++cnt;
    }

    int len1 = int(s.size());
    string res;
    for(int i = 0; i < len1; ++i){
        unordered_map<char, int> ms;
        int c = 0;
        for(int j = i; j < len1; ++j){
            if(mt.count(s[j])){
                ++ms[s[j]];
                ++c;

                if(c >= cnt and includeMap(ms, mt)){
                    if(res.empty() or (j - i + 1) < res.size()){
                        res = s.substr(i, j - i + 1);
                        break;
                    }
                }
            }
        }
    }

    return res;
}
#endif

//#define minWindow_V2
#ifdef minWindow_V2
string minWindow(string s, string t){
    unordered_map<char, int> mt;
    for(auto ch : t){
        ++mt[ch];
    }

    int len1 = int(s.size()), l = 0, r = 0, cnt_s = 0;
    string res;
    unordered_map<char, int> ms;

    while(r < len1){
        char ch = s[r++];
        if(not mt.count(ch)) continue;

        ++ms[ch];
        ++cnt_s;
        while(cnt_s >= t.size() and ms.size() == mt.size() and includeMap(ms, mt)){
            char c = s[l];
            if(0 == ms.count(c)){
                ++l;
            }else{
                if(res.empty() or (r - l) < res.size()){
                    res = s.substr(l, r - l);
                }
                --ms[c];
                --cnt_s;
                ++l;
            }
        }
    }

    return res;
}
#endif

string minWindow(string s, string t){
    unordered_map<char, int> mt;
    for(auto ch : t){
        ++mt[ch];
    }

    int len1 = int(s.size()), l = 0, r = 0, cnt = 0;
    string res;
    unordered_map<char, int> ms;

    while(r < len1){
        char c = s[r++];
        ++ms[c];
        if(0 == mt.count(c))continue;

        ++cnt;
        while(0 == mt.count(s[l]))++l;
        while(mt[s[l]] > 0 and mt[s[l]] < ms[s[l]]){--ms[s[l]];++l;--cnt;}

        if(cnt >= t.size()){
            if(res.empty() or (r - l) < res.size()){
                res = s.substr(l, r - l);
            }
        }
    }

    return res;
}

//#define checkInclusion_V1

#ifdef checkInclusion_V1
bool checkInclusion(string s1, string s2){
    unordered_map<char, int> mc1, mc2;
    for(auto c : s1)++mc1[c];

    int cnt = 0, l = 0, r = 0;
    while(r < s2.size()){
        char c = s2[r++];
        if(0 == mc1.count(c)){
            l = r;
            cnt = 0;
            mc2.clear();
            continue;
        }

        ++cnt;
        ++mc2[c];
        while(mc2[c] > mc1[c]){
            --cnt;
            --mc2[s2[l++]];
        }

        if(cnt >= s1.size())
            return true;
    }

    return false;
}
#endif

bool checkInclusion(string s1, string s2){
    if(s1.size() > s2.size()) return false;

    unordered_map<char, int> mc1, mc2;
    for(auto c : s1)++mc1[c];

    int len1 = int(s1.size()), len2 = int(s2.size());
    for(int i = 0; i < len1 - 1; ++i)++mc2[s2[i]];

    for(int j = len1 - 1; j < len2; ++j){
        ++mc2[s2[j]];
        if(mc1 == mc2) return true;

        int& a = mc2[s2[j - (len1 - 1)]];
        --a;
        if(0 == a){
            mc2.erase(s2[j - (len1 - 1)]);
        }
    }

    return false;
}

//s = "abcabcbb" -> "abc"
//s = "bbbbb"	 -> "b"
//s = "pwwkew"   ->	"wke"
int lengthOfLongestSubstring(string s){
    int len = int(s.size());
    int i = 0, j = 0, cnt = 0;
    unordered_map<char, int> mc;
    while(j < len){
        char ch = s[j++];
        if((++mc[ch]) == 1){
            cnt = max(cnt, j - i);
            continue;
        }

        while(mc[ch] > 1){
            --mc[s[i++]];
        }
    }

    return cnt;
}

/*
输入：target = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。
*/
int minSubArrayLen(int target, const vector<int>& nums){
    int cnt = INT_MAX, l = 0, r = 0, sum = 0;
    int len = int(nums.size());
    while(r < len){
        sum += nums[r++];
        if(sum < target) continue;

        while(sum - nums[l] >= target){
            sum -= nums[l];
            ++l;
        }

        cnt = std::min(cnt, r - l);
    }

    return INT_MAX == cnt ? 0 : cnt;
}

int minSubArrayLen2(int target, vector<int>& nums){
    int len = int(nums.size());
    int ret = len + 1, beg = 0, idx = 0, sum = 0;
    while(idx < len){
        sum += nums[idx++];
        while(sum >= target){
            ret = std::min(ret, idx - beg);
            sum -= nums[beg++];
        }
    }

    return (ret == len + 1) ? 0 : ret;
}

//输入：nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
//输出：3
//解释：长度最长的公共子数组是 [3,2,1] 。
//#define findLength_V1

#ifdef findLength_V1
int findLength(const vector<int>& nums1, const vector<int>& nums2){
    int len1 = int(nums1.size()), len2 = int(nums2.size());
    int cnt = 0;

    for(int i = 0; i < len1; ++i){
        for(int j = 0; j < len2; ++j){
            int k = j;
            while(k < len2 and (i + k - j) < len1 and nums2[k] == nums1[i + (k - j)]){
                ++k;
            }

            cnt = std::max(cnt, k - j);
        }
    }

    return cnt;
}
#endif

int findLength(const vector<int>& nums1, const vector<int>& nums2){
    int len1 = int(nums1.size()), len2 = int(nums2.size());
    int ret = 0, cnt = (len1 + len2 - 1);

    for(int i = 0; i < cnt; ++i){
        int start1 = 0, start2 = 0, cmp_len = 0;
        if(i < len1){
            start1 = len1 - i - 1;
            start2 = 0;
            cmp_len = len1 - start1;
        }else{
            start1 = 0;
            start2 = i - len1 + 1;
            cmp_len = len2 - start2;
        }

        int part = 0;
        for(int j = 0; j < cmp_len; ++j){
            if(nums1[start1 + j] == nums2[start2 + j]){
                ++part;
                ret = std::max(part, ret);
            }else{
                part = 0;
            }
        }
    }

    return ret;
}

// 下面这个是连续的
bool increasingTriplet(const vector<int>& nums){
    int len = int(nums.size()), i = 0, j = 1;
    while (j < len){
        if(nums[j] > nums[j - 1]){
            if(j - i + 1 >= 3){
                return true;
            }
        }else{
            i = j;
        }
        ++j;
    }

    return false;
}
