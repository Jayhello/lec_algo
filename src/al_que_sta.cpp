//
// Created by wenwen on 2022/5/24.
//

#include <numeric>
#include "al_que_sta.h"

inline bool isLeft(char ch){return '(' == ch or '{' == ch or '[' == ch;}

inline bool matchRight(char ch){return '(' == ch or '{' == ch or '[' == ch;}

bool isValid20(string s){
    static const set<char> LEFT_SET{'(', '{', '['};
    static const set<char> RIGHT_SET{')', '}', ']'};
    static map<char, char> M_MATCH{{'(', ')'}, {'[', ']'}, {'{', '}'}};

    stack<char> cSta;
    for(auto ch : s){
        if(LEFT_SET.count(ch)){
            cSta.push(ch);
        }else{
            if(cSta.empty()) return false;
            if(M_MATCH[cSta.top()] != ch) return false;
            cSta.pop();
        }
    }

    return cSta.empty();
}

static void Split(const string& str, char ch, vector<string>& vec){
    int len = int(str.size()), i = 0;

    while(i < len){
        if(ch == str[i])++i;
        else{
            int j = i + 1;
            while(j < len and ch != str[j])++j;
            vec.emplace_back(str.substr(i, j - i));
            i = j;
        }
    }
}

string simplifyPath(string path){
    vector<string> vec;
    Split(path, '/', vec);

    stack<int> sta;
    for(int i = 0; i < vec.size(); ++i){
        if("." == vec[i]){
        }
        else if(".." == vec[i]){
            if(not sta.empty()) sta.pop();
        }else{
            sta.push(i);
        }
    }

    string res;
    while(!sta.empty()){
        res = "/" + vec[sta.top()] + res;
        sta.pop();
    }

    return res.empty() ? "/" : res;
}

void helper844(const string& s1, stack<char>& sta){
    for(auto ch : s1){
        if('#' == ch){
            if(not sta.empty())sta.pop();
        }else{
            sta.push(ch);
        }
    }
}

bool backspaceCompare(string s, string t){
    stack<char> sta1;
    stack<char> sta2;
    helper844(s, sta1);
    helper844(t, sta2);

    return sta1 == sta2;
}

int calPoints(vector<string>& ops){
    vector<int> nums;

    for(const auto& op : ops){
        if("+" == op){
            int sum = nums[nums.size() - 1] + nums[nums.size() - 2];
            nums.push_back(sum);
        }else if("D" == op){
            nums.push_back(nums.back() * 2);
        }else if("C" == op){
            nums.pop_back();
        }else{
            nums.push_back(stoi(op));
        }
    }

    return accumulate(nums.begin(), nums.end(), 0);
}

int evalRPN(vector<string>& tokens){
    int n = 0, n1 = 0, n2 = 0;
    stack<int> sta;

    for(const auto& token : tokens){
#define __INNER_OP__(op) {n2 = sta.top();sta.pop(); n1 = sta.top();sta.pop();n = n1 op n2;sta.push(n);}
        if("+" == token)__INNER_OP__(+)
        else if("-" == token)__INNER_OP__(-)
        else if("*" == token)__INNER_OP__(*)
        else if("/" == token)__INNER_OP__(/)
        else sta.push(stoi(token));
    }

    return sta.top();
}

#define IS_SPACE(ch) (' ' == ch)

#ifdef USE_calcExpress1
int calcExpress1(const string& sExpress){
    int len = int(sExpress.size()), i = 0;
    vector<int> nums;

    while(i < len){
        if(IS_SPACE(sExpress[i])){
            ++i;
        }else{
            bool positive = true;
            if('+' == sExpress[i])++i;
            if('-' == sExpress[i]){++i; positive = false;}

            while(i < len and IS_SPACE(sExpress[i]))++i;

            int n = 0;
            while(i < len and std::isdigit(sExpress[i])){
                n = 10 * n + (sExpress[i] - '0');
                ++i;
            }

            nums.push_back(positive ? n : -n);
        }
    }

    return accumulate(nums.begin(), nums.end(), 0);
}
#endif

// 第二个版本, 无需vector nums
#ifdef calcExpress1_v1
int calcExpress1(const string& sExpress){
    int len = int(sExpress.size()), i = 0;
    int ret = 0;

    while(i < len){
        if(IS_SPACE(sExpress[i])){
            ++i;
        }else{
            bool positive = true;
            if('+' == sExpress[i])++i;
            if('-' == sExpress[i]){++i; positive = false;}

            while(i < len and IS_SPACE(sExpress[i]))++i;

            int n = 0;
            while(i < len and std::isdigit(sExpress[i])){
                n = 10 * n + (sExpress[i] - '0');
                ++i;
            }

            if(positive){
                ret += n;
            }else{
                ret -= n;
            }
        }
    }

    return ret;
}

#else
// 简单的版本呢
int calcExpress1(const string& s){
    int res = 0, num = 0;
    bool positive = true;

    for(int i = 0; i < s.size(); ++i){
        if(std::isdigit(s[i])){
            num = 10 * num + (s[i] - '0');
        }else if('+' == s[i] or '-' == s[i]){
            res += (positive ? num : -num);
            num = 0;
            positive = ('+' == s[i]);
        }
    }
    res += (positive ? num : -num);

    return res;
}
#endif

int calcExpress11(const string& s){
    int res = 0, num = 0, sign = 1;
    stack<int> sta;

    for(int i = 0; i < s.size(); ++i){
        if(std::isdigit(s[i])){
            num = 10 * num + (s[i] - '0');
        }else if('+' == s[i] or '-' == s[i]){
            res += (sign * num);
            num = 0;
            sign = ('+' == s[i] ? 1 : -1);
        }else if('(' == s[i]){
            sta.push(res);
            sta.push(sign);

            res = 0;
            sign = 1;
        }else if(')' == s[i]){
            res += (sign * num);
            num = 0;

            res *= sta.top();sta.pop();
            res += sta.top();sta.pop();
        }
    }

    res += (sign * num);

    return res;
}

int calcExpress227(const string& s){

}

// the registers xv6 will save and restore
// to stop and subsequently restart a process
struct context {
    int eip;
    int esp;
    int ebx;
};


int calcExpress2(const string& sExpress){
    int len = int(sExpress.size()), i = 0;
    vector<int> nums;
    char op = '+';

    while(i < len){
        if(IS_SPACE(sExpress[i])){
            ++i;
        }else{

            if('+' == sExpress[i]){++i;op = '+';}
            if('-' == sExpress[i]){++i;op = '-';}
            if('*' == sExpress[i]){++i;op = '*';}
            if('/' == sExpress[i]){++i;op = '/';}

            while(i < len and IS_SPACE(sExpress[i]))++i;

            int n = 0;
            while(i < len and std::isdigit(sExpress[i])){
                n = 10 * n + (sExpress[i] - '0');
                ++i;
            }

            switch (op) {
                case '+':
                    nums.push_back(n);
                    break;
                case '-':
                    nums.push_back(-n);
                    break;
                case '*':
                    nums.back() = nums.back() * n;
                    break;
                case '/':
                    nums.back() = nums.back() / n;
                    break;
                default:;
            }
        }
    }

    return accumulate(nums.begin(), nums.end(), 0);
}

int helper39(const string& sExpress, int& i){
    int len = static_cast<int>(sExpress.size());
    if(i >= len) return 0;

    vector<int> nums;
    char op = '+';

    while(i < len){
        if(IS_SPACE(sExpress[i])){++i;continue;}

        if('+' == sExpress[i]){++i;op = '+';}
        if('-' == sExpress[i]){++i;op = '-';}
        if('*' == sExpress[i]){++i;op = '*';}
        if('/' == sExpress[i]){++i;op = '/';}
        if('(' == sExpress[i]){
            int tmp = helper39(sExpress, ++i);
            nums.push_back('-' == op ? -tmp : tmp);
            continue;
        }

        if(')' == sExpress[i]){
            ++i;
            break;
        }

        while(i < len and IS_SPACE(sExpress[i]))++i;

        int n = 0;
        while(i < len and std::isdigit(sExpress[i])){
            n = 10 * n + (sExpress[i] - '0');
            ++i;
        }

        switch (op) {
            case '+':
                nums.push_back(n);
                break;
            case '-':
                nums.push_back(-n);
                break;
            case '*':
                nums.back() = nums.back() * n;
                break;
            case '/':
                nums.back() = nums.back() / n;
                break;
            default:;
        }

    }

    int sum = accumulate(nums.begin(), nums.end(), 0);
    return sum;
//    return sum + helper39(sExpress, i);
}

int calcExpress3(const string& sExpress){
    int i = 0;
    return helper39(sExpress, i);
}
