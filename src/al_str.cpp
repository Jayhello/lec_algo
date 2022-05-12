//
// Created by wenwen on 2022/4/18.
//
#include <algorithm>
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
