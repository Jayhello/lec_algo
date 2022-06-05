//
// Created by wenwen on 2022/4/18.
//
#include <algorithm>
#include <map>
#include "al_str.h"

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
