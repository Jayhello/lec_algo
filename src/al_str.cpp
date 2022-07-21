//
// Created by wenwen on 2022/4/18.
//
#include <algorithm>
#include <map>
#include "al_str.h"
#include "al_comm.h"

string encode271(const vector<string>& vStr){
    string res;
    for(const auto& str : vStr){
        res += to_string(str.size());
        res += '/';
        res += str;
    }

    return res;
}

vector<string> decode271(const string& str){
    vector<string> vec;
    int i = 0, len = int(str.size());
    while(i < len){
        int j = str.find('/', i);
        string sLen = str.substr(i, j - i);
        auto sub_size = stoi(sLen);

        vec.push_back(str.substr(j + 1, sub_size));
        i = j + sub_size + 1;
    }

    return vec;
}

string helper38(const string& str){
    string res;
    int i = 0, len = int(str.size());
    while(i < len){
        int c = 1, j = i + 1;
        for(; j < len and str[j] == str[i]; ++j, ++c);
        res += to_string(c);
        res += str[i];
        i = j;
    }

    return res;
}

string countAndSay_38(int n){
    string res = "1";

    for(int i = 1; i < n; ++i){
        res = helper38(res);
    }

    return res;
}

int lengthOfLastWord(string s){
    int c = 0, len = int(s.size()), i = len - 1;
    while(i >= 0){
        if(s[i--] == ' '){
            if(c > 0)break;
            else continue;
        }

        ++c;
    }

    return c;
}

#define IS_SPACE(ch) ' ' == ch
#define NOT_SPACE(ch) ' ' != ch

#ifdef USE_reverseWords_V1

string reverseWords(string s){
    std::reverse(s.begin(), s.end());
    int len = int(s.size());
    int b = 0, e = len - 1;
    while(b < len and IS_SPACE(s[b]))++b;
    while(e >= 0 and IS_SPACE(s[e]))--e;

    string res;
    while(b <= e){
        int i = b + 1;
        while(i <= e and NOT_SPACE(s[i]))++i;

        for(int j = i - 1; j >= b; --j){
            res.push_back(s[j]);
        }

        if(i > e)break;

        res.push_back(' ');
        while(i <= e and IS_SPACE(s[i]))++i;
        b = i;
    }

    return res;
}
#else

string reverseWords(string s){
    std::reverse(s.begin(), s.end());

    int i = 0, len = int(s.size());
    int curIdx = 0;
    while(i < len){
        if(IS_SPACE(s[i])){
            ++i;
            continue;
        }

        if(curIdx > 0)s[curIdx++] = ' ';

        int j = i;
        while(j < len and NOT_SPACE(s[j]))
            s[curIdx++] = s[j++];

        std::reverse(s.begin() + curIdx - (j - i), s.begin() + curIdx);

        i = j;
    }

    s.resize(curIdx);
    return s;
}

#endif

int countSegments(string s){
    int count = 0;
    int len = int(s.size());
    for(int i = 0; i < len; ++i){
        if(IS_SPACE(s[i]))continue;

        while(i < len and NOT_SPACE(s[i]))
            ++i;
        ++count;
    }

    return count;
}

string reverseStr541(string s, int k){
    if(k <= 1 or s.size() < 2)return s;

    int len = static_cast<int>(s.size());
    int count = (len - 2) / (2 * k) + 1;
    for(int c = 0; c < count; ++c){
        int beg = 2 * k * c, end = std::min(beg + k, len);
        std::reverse(s.begin() + beg, s.begin() + end);
    }

    return s;
}

string transNK(string s, int n){
    std::reverse(s.begin(), s.begin() + n);
    for(int i = 0; i < n; ++i){
        if(IS_SPACE(s[i]))continue;

        int j = i;
        while(j < n and NOT_SPACE(s[j])){
            if(std::islower(s[j]))s[j] = std::toupper(s[j]);
            else s[j] = std::tolower(s[j]);
            ++j;
        }

        std::reverse(s.begin() + i, s.begin() + j);
        i = j;
    }

    return s;
}

int compareVersionCmp(const char* s1, int b1, int e1, const char* s2, int b2, int e2){
    while(b1 < e1 and b2 < e2){
        if(s1[b1] > s2[b2]){
            return 1;
        } else if(s1[b1] < s2[b2]){
            return -1;
        }
        ++b1;
        ++b2;
    }

    if(b1 < e1) return 1;
    if(b2 < e2) return -1;
    return 0;
}

#ifdef compareVersion_V1
int compareVersion(string version1, string version2){
    int b1 = 0, b2 = 0;
    int len1 = static_cast<int>(version1.size()), len2 = static_cast<int>(version2.size());

    while(b1 < len1 and b2 < len2){
        while(b1 < len1 and '0' == version1[b1])++b1;
        int e1 = b1 + 1;
        while(e1 < len1 and '.' != version1[e1])++e1;

        while(b2 < len2 and '0' == version2[b2])++b2;
        int e2 = b2 + 1;
        while(e2 < len2 and '.' != version2[e2])++e2;

        int tmp = compareVersionCmp(version1.data(), b1, e1, version2.data(), b2, e2);
        if(tmp) return tmp;

        b1 = e1 + 1;
        b2 = e2 + 1;
    }

    while(b1 < len1 and (version1[b1] == '0' or version1[b1] == '.'))++b1;
    while(b2 < len2 and (version2[b2] == '0' or version2[b2] == '.'))++b2;

    if(b1 < len1) return 1;
    if(b2 < len2) return -1;

    return 0;
}

#else

int compareVersion(string version1, string version2){
    int b1 = 0, b2 = 0;
    int len1 = static_cast<int>(version1.size()), len2 = static_cast<int>(version2.size());

    while(b1 < len1 or b2 < len2){
        int n1 = 0;
        while(b1 < len1 and version1[b1] != '.'){
            n1 = 10 * n1 + (version1[b1++] - '0');
        }

        int n2 = 0;
        while(b2 < len2 and version2[b2] != '.'){
            n2 = 10 * n2 + (version2[b2++] - '0');
        }

        if(n1 > n2) return 1;
        if(n1 < n2) return -1;
        ++b1;
        ++b2;
    }

    return 0;
}

#endif


#define ALPHA_OR_NUM(ch) (std::isalpha(ch) or std::isdigit(ch))
#define IG_EQ_CHAR(c1, c2) (std::tolower(c1) == std::tolower(c2))

bool isPalindrome(string s){
    int i = 0, j = static_cast<int>(s.size()) - 1;
    while(i < j){
        if(not ALPHA_OR_NUM(s[i])){++i;continue;}
        if(not ALPHA_OR_NUM(s[j])){--j;continue;}

        if(not IG_EQ_CHAR(s[i], s[j]))return false;
        ++i;
        --j;
    }

    return true;
}

int longestPalindrome(string s){
    int cnt = 0;
    map<char, int> mCharCnt;
    for(auto c : s){
        ++mCharCnt[c];
    }

    bool used = false;
    for(const auto& kv : mCharCnt){
        if(kv.second % 2){
            if(not used){
                cnt += kv.second;
                used = true;
            }else{
                cnt += (kv.second - 1);
            }
        }else{
            cnt += kv.second;
        }
    }

    return cnt;
}

bool canPermutePalindrome(string s){
    map<char, int> ch_cnt;
    for(auto c : s)++ch_cnt[c];
    int cnt = 0;
    for(const auto& item : ch_cnt){
        if(item.second % 2)++cnt;
        if(cnt > 1)return false;
    }
    return true;
}

bool isPalindrome(int x){
    if(x < 0) return false;

    int n = 0;
    while(x){
        n = 10 * n + x % 10;
        x /= 10;
    }

    return x == n;
}

bool validPalindrome680(string s){
    int len = int(s.size());
    int l = 0, r = len - 1;

    auto partPalindrome = [&s](int l, int r){
        while(l < r){
            if(s[l] == s[r]){
                ++l;--r;
            }else{
                return false;
            }
        }
        return true;
    };

    while(l < r){
        if(s[l] == s[r]){
            ++l;
            --r;
        }else{
            return partPalindrome(l, r - 1) or partPalindrome(l + 1, r);
        }
    }

    return true;
}

string addStrings(string num1, string num2){
    string res;
    int i1 = int(num1.size()) - 1, i2 = int(num2.size()) - 1;
    int carry = 0;
    while(i1 >= 0 or i2 >= 0 or carry > 0){
        int n1 = (i1 >= 0 ? (num1[i1--] - '0') : 0);
        int n2 = (i2 >= 0 ? (num2[i2--] - '0') : 0);
        int sum = n1 + n2 + carry;
        res.push_back((sum) % 10 + '0');
        carry = (sum) / 10;
    }

    std::reverse(res.begin(), res.end());
    return res;
}

string multiply43(string num1, string num2){
    if("0" == num1 or "0" == num2)return "0";

    int len1 = int(num1.size()), len2 = int(num2.size());
    int carry = 0;
    vector<int> nums(len1 + len2, 0);

    for(int i = len1 - 1; i >= 0; --i){
        int n1 = num1[i] - '0';
        for(int j = len2 - 1; j >= 0; --j){
            int n2 = num2[j] - '0';
            int idx = i + j + 1;
            int sum = n1 * n2 + carry + nums[idx];

            nums[idx] = sum % 10;
            carry = sum / 10;
        }

        if(carry){
            nums[i] = carry;
            carry = 0;
        }
    }

    int i = (nums[0] == 0 ? 1 : 0);
    string res;
    while(i < nums.size())res.push_back(nums[i++] + '0');

    return res;
}

string powOf2NK(int n){
    string s = "1";
    for(int i = 1; i <= n; ++i){
        int len = s.size(), carry = 0;
        for(int j = len - 1; j >= 0; --j){
            int sum = 2 * (s[j] - '0') + carry;
            s[j] = (sum % 10 + '0');
            carry = sum / 10;
        }

        if(carry)s = std::to_string(carry) + s;
    }

    return s;
}

// "32.123" -> 32.123
float StrToFloat(const std::string& str){
    float f = 0;
    int len = int(str.size()), i = 0;

    for(; i < len and '.' != str[i]; ++i){
        f = f * 10 + (str[i] - '0');
    }

    if('.' == str[i])++i;

    float base = 10.0;
    while(i < len){
        f += ((str[i++] - '0') / base);
        base *= 10;
    }

    return f;
}

string float2String(float f){
    if(floatEqual(f, 0)) return "0";

    string res;
    int a = int(f);
    while(a){
        res.push_back(a % 10 + '0');
        a /= 10;
    }

    std::reverse(res.begin(), res.end());
    f -= int(f);
    if(floatEqual(f, 0)){
        return res;
    }

    res.push_back('.');
    while(not floatEqual(f, 0)){
        f *= 10;
        res.push_back(int(f) % 10 + '0');
        f -= (int(f) % 10);
    }

    return res;
}

// 221.123.10.5
uint32_t ip2Int(const string& sIP){
    uint32_t ret = 0, n = 0;
    int len = static_cast<int>(sIP.size());

    for(int i = 0; i < len; ++i){
        if('.' == sIP[i]){
            ret = (ret << 8) | n;
            n = 0;
        }else{
            n = 10 * n + (sIP[i] - '0');
        }
    }

    ret = (ret << 8) | n;
    return ret;
}

string int2ip(uint32_t iIp){
    string res;
    res.append(to_string(iIp >> 24)).append(".")
       .append(to_string((iIp >> 16) & 255)).append(".")
       .append(to_string((iIp >> 8) & 255)).append(".")
       .append(to_string(iIp & 255));

    return res;
}

vector<string> Split(const string& str, char ch){
    int i = 0, len = static_cast<int>(str.size());
    vector<string> vec;

    while(i < len){
        while(i < len and ch == str[i])++i;

        if(i >= len) break;

        string tmp;
        while(i < len and ch != str[i])tmp.push_back(str[i++]);
        vec.push_back(tmp);
    }

    return vec;
}

vector<string> splitString(const std::string& str, const std::string& split){
    vector<string> vec_str;
    int i = 0, len1 = int(str.size()), len2 = int(split.size());

    auto sub_eq = [&](int j){
        int k = 0;
        while(j < len1 and k < len2 and str[j] == split[k]){
            ++j;++k;
        }
        return k >= len2;
    };

    while(i < len1){
        while(i < len1 and sub_eq(i)) i += len2;
        if(i >= len1) break;

        string tmp;
        while(i < len1 and not sub_eq(i)){
            tmp.push_back(str[i++]);
        }

        vec_str.push_back(tmp);
    }

    return vec_str;
}

int strStr(string src, string sub){
    int len1 = int(src.size()), len2 = int(sub.size());
    for(int i = 0; i <= len1 - len2; ++i){
        int j = 0;
        while(j < len2 and sub[j] == src[i + j])++j;
        if(j == len2)return i;
    }

    return -1;
}

#ifdef UASE_V1
string lengthOfLongestSubstring(string s){
    if(s.size() < 2) return s;
    int len = int(s.size());
    int beg = 0, end = 0;

    for(int i = 0; i < len - 1; ++i){
        int j = i + 1;
        for(; j < len; ++j){
            auto it = std::find(s.begin() + i, s.begin() + j, s[j]);
            if(it != (s.begin() + j))break;
        }

        if((j - i) > (end - beg)){
            beg = i;
            end = j;
        }
    }

    return s.substr(beg, end - beg);
}
#endif

string lengthOfLongestSubstring(string s){
    if(s.size() < 2) return s;
    int len = int(s.size());
    int beg = 0, end = 0, i = 0, j = 1;
    auto find_ch = [&s](int b, int e, char ch){
        while(b < e and s[b] != ch)++b;
        return b;
    };

    while(j < len){
        int k = find_ch(i, j, s[j]);
        if(k != j){
            i = k + 1;
            j += 1;
        }else{
            ++j;
        }

        if(j - i > end - beg){
            beg = i;
            end = j;
        }
    }

    return s.substr(beg, end - beg);
}

//#define replaceSpace_v1

#ifdef replaceSpace_v1
// 输入：s = "We are happy."
// 输出："We%20are%20happy."
string replaceSpace(string s){
    string res;
    for(char ch : s){
        if(' ' == ch){
            res.append("%20");
        }else{
            res.push_back(ch);
        }
    }

    return res;
}
#endif

string replaceSpace(string s){
    int old_len = int(s.size());
    int count = 0;
    for(auto c : s)if(' ' == c)++count;
    if(0 == count) return s;

    int new_len = old_len + 2 * count;
    s.resize(new_len);
    int i = old_len - 1, j = new_len - 1;

    while(i >= 0){
        if(' ' == s[i]){
            s[j--] = '0';
            s[j--] = '2';
            s[j--] = '%';
            --i;
        }else{
            s[j--] = s[i--];
        }
    }

    return s;
}

bool rotateString(string s, string goal){
    if(s.size() != goal.size()) return false;

    int len = int(s.size());
    for(int i = 0; i < len; ++i){
        int c = 0;
        for(; c < len; ++c){
            if(s[(i + c) % len] != goal[c])break;
        }

        if(c == len) return true;
    }

    return false;
}

bool repeatedSubstringPattern(string s){
    int len = int(s.size());

    auto partial_eq = [&s, len](int sub_len){
        int count = len / sub_len;
        for(int c = 1; c < count; ++c){
            for(int i = 0; i < sub_len; ++i){
                if(s[i] != s[c * sub_len + i])return false;
            }
        }

        return true;
    };

    for(int sub_len = len / 2; sub_len >= 1; --sub_len){
        if(len % sub_len) continue;

        if(partial_eq(sub_len))return true;
    }

    return false;
}

int repeatedStringMatch(string a, string b){
    for(auto c : b){
        if(a.find(c) == std::string::npos) return -1;
    }

    int len1 = int(a.size()), len2 = int(b.size());
    int max_count = 1 + len2 / len1 + (len2 % len1 ? 1 : 0);

    string tmp = a;
    for(int c = 1; c <= max_count; ++c){
        if(tmp.size() < len2){
            tmp += a;
            continue;
        }

        if(std::string::npos != tmp.find(b))return c;
        tmp += a;
    }

    return -1;
}

bool isLongPressedName(string name, string typed){
    int len1 = int(name.size()), len2 = int(typed.size());
    int i = 0, j = 0;
    while(i < len1 and j < len2){
        char a = name[i];
        int c1 = 1, c2 = 0;
        while(i < len1 - 1 and a == name[i + 1]){++c1;++i;}
        while(j < len2 and a == typed[j]){++c2;++j;}

        if(c2 < c1)return false;
        ++i;
    }

    return i >= len1 and j >= len2;
}


// s1 是否可以删除某些字符得到 s2(即s2是否是s1的子字符串)
// s1 = "abpcplea", s2 = "apple"
bool helper524(const string& src, const string& sub){
    int len = int(src.size());
    auto find_idx = [&src, len](char ch, int beg){
        while(beg < len and src[beg] != ch)++beg;
        return beg;
    };

    int idx = 0, sum = 0;
    for(auto ch : sub){
        idx = find_idx(ch, idx);
        if(idx >= len)return false;
        sum += idx;
    }

    return true;
}
bool CanDel(const string& src, const string& sub){
    int len1 = src.size(), len2 = sub.size();
    int i = 0, j = 0;
    while(i < len1 and j < len2){
        if(sub[j] == src[i]){
            ++j;
        }
        ++i;
    }

    return j == len2;
}
string findLongestWord(string s, vector<string>& dictionary){
    string res;

    for(const auto& sub : dictionary){
        if(helper524(s, sub)){
            return res;
        }
    }

    return res;
}

void helper844(const string& s1, string& dst){
    for(auto c : s1){
        if('#' == c){
            if(not dst.empty())dst.pop_back();
        }else{
            dst.push_back(c);
        }
    }
}

bool backspaceCompare(string s, string t){
    string s1, s2;
    helper844(s, s1);
    helper844(t, s2);
    return s1 == s2;
}
