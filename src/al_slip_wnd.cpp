//
// Created by wenwen on 2022/7/20.
//

#include "al_slip_wnd.h"
#include <unordered_map>
#include <map>
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

bool contains(const unordered_map<char, int>& mChCnt1, const unordered_map<char, int>& mChCnt2){
    for(const auto& kv : mChCnt2){
        auto it = mChCnt1.find(kv.first);
        if(it == mChCnt1.end() or it->second < kv.second){
            return false;
        }
    }
    return true;
}

string minWindow(string s, string t){
    int len_s = s.size(), len_t = t.size();
    unordered_map<char, int> mChCntT;
    for(auto c : t)++mChCntT[c];

    string res;
    unordered_map<char, int> mChCntWnd;
    int left = 0, right = 0;
    while(right < len_s){
        ++mChCntWnd[s[right++]];
        if(right - left < len_t or not contains(mChCntWnd, mChCntT))continue;

        while(left < right){
            if(res.empty() or res.size() > right - left){
                res = s.substr(left, right - left);
            }

            --mChCntWnd[s[left++]];
            if(not contains(mChCntWnd, mChCntT))break;
        }
    }

    return res;
    /*
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
    */
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
    int len1 = s1.size(), len2 = s2.size();
    if(len1 > len2)return false;

    unordered_map<char, int> mc1, mc_wnd;
    for(auto c : s1)++mc1[c];
    for(int i = 0; i < len1 - 1; ++i)++mc_wnd[s2[i]];

    for(int i = len1 - 1; i < len2; ++i){
        ++mc_wnd[s2[i]];
        auto it = mc1.find(s2[i]);
        if(it != mc1.end() and it->second == mc_wnd[s2[i]] and mc_wnd == mc1){
            return true;
        }

        --mc_wnd[s2[i + 1 - len1]];
        if(0 == mc_wnd[s2[i + 1 - len1]]){
            mc_wnd.erase(s2[i + 1 - len1]);
        }
    }
    return false;
    /*
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
    */
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

int helper3(const string& s, int l, int r, char c){
    for(; l <= r and s[l] != c; ++l){
    }
    return l > r ? -1 : l;
}

int lengthOfLongestSubstring1(string s){
    if(s.empty())return 0;
    int len = s.size();
    int i = 0, j = 1;
    int res = 1;
    for(; j < len; ++j){
        int idx = helper3(s, i, j - 1, s[j]);
        if(idx < 0){
            res = std::max(res, j - i + 1);
        }else{
            i = idx + 1;
        }
    }
    return res;
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

int findLength1(const vector<int>& nums1, const vector<int>& nums2){
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

vector<int> maxSlidingWindow(vector<int>& nums, int k){
    int len = nums.size();
    std::map<int, int> m_val_cnt;
    for(int i = 0; i < k; ++i)++m_val_cnt[nums[i]];
    vector<int> res;
    auto it = --m_val_cnt.end();
    res.push_back(it->first);

    for(int i = k; i < len; ++i){
        ++m_val_cnt[nums[i]];
        int v = nums[i - k];
        --m_val_cnt[v];
        if(0 == m_val_cnt[v])m_val_cnt.erase(v);

        auto it = --m_val_cnt.end();
        res.push_back(it->first);
    }

    return res;
}

namespace xy{

bool checkInclusion(string s1, string s2) {
    unordered_map<char, int> mChCnt1;
    for(auto c : s1)++mChCnt1[c];

    unordered_map<char, int> mChCntWnd;
    int left = 0, right = 0, len = s2.size();
    while(right < len){
        char ch = s2[right++];
        if(0 == mChCnt1.count(ch)){
            mChCntWnd.clear();
            left = right;
            continue;
        }

        ++mChCntWnd[ch];
        while(mChCntWnd[ch] > mChCnt1[ch]){
            char ch2 = s2[left++];
            --mChCntWnd[ch2];
            if(0 == mChCntWnd[ch2]){
                mChCntWnd.erase(ch2);
            }
        }

        if(right - left < s1.size()) continue;

        if(mChCnt1 == mChCntWnd) return true;
    }

    return false;
}

int lengthOfLongestSubstring(string s){
    if(s.empty()) return 0;

    int len = s.size(), left = 0, right = 0;
    int maxLeft = -1, maxRight = - 1;
    unordered_map<char, int> mChCnt;
    while(right < len){
        char ch = s[right++];
        ++mChCnt[ch];
        while(mChCnt[ch] > 1){
            --mChCnt[s[left++]];
        }

        if(maxLeft < 0 or (maxRight - maxLeft < right - left)){
            maxLeft = left;
            maxRight = right;
        }
    }
    return maxRight - maxLeft;
}

int minSubArrayLen(int target, vector<int>& nums){
    int len = nums.size();
    int left = 0, right = 0, minLen = 0;
    int sum = 0;
    while(right < len){
        sum += nums[right++];
        while(sum >= target){
            if(minLen == 0 or right - left < minLen){
                minLen = right - left;
            }
            sum -= nums[left++];
        }
    }
    return minLen;
}

vector<int> findSubstring(string s, vector<string>& words){
    vector<int> vec;
    int len = s.size(), sublen = words[0].size(), num = words.size();
    if(len < sublen * num){
        return vec;
    }

    unordered_map<string, int> mWordCnt;
    for(const auto& word: words)++mWordCnt[word];

    for(int i = 0; i <= len - sublen * num; ++i){
        unordered_map<string, int> mSubCnt;
        for(int k = 0; k < num; ++k){
            string part = s.substr(i + k * sublen, sublen);
            auto it = mWordCnt.find(part);
            if(it == mWordCnt.end()){
                break;
            }

            if(++mSubCnt[part] > it->second){
                break;
            }
        }

        if(mSubCnt.size() == mWordCnt.size() and mSubCnt == mWordCnt){
            vec.push_back(i);
        }
    }

    return vec;
}


} // xy
