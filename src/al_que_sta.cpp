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

string helper844_v2(const string& str){
    string res;
    for(auto c : str){
        if('#' == c){
            if(not res.empty()) res.pop_back();
        }else{
            res.push_back(c);
        }
    }
    return res;
}

bool backspaceCompare2(string s, string t){
    string str1 = helper844_v2(s);
    string str2 = helper844_v2(t);
    return str1 == str2;
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

int evalRPN2(vector<string>& tokens){
    vector<int> vec;
    for(const auto& s : tokens){
        if(1 == s.size() and not std::isdigit(s[0])){
            int n2 = vec.back();vec.pop_back();
            int n1 = vec.back();vec.pop_back();
            int n = 0;
            if(s == "+"){
                n = n1 + n2;
            }else if(s == "-"){
                n = n1 - n2;
            }else if(s == "*"){
                n = n1 * n2;
            }else{
                n = n1 / n2;
            }
            vec.push_back(n);
        }else{
            vec.push_back(std::stoi(s));
        }
    }

    return vec[0];
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

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int len = temperatures.size();
    vector<int> res(len, 0);
    stack<int> sta;
    for(int i = len - 1; i >= 0; --i){
        while(not sta.empty() and temperatures[sta.top()] <= temperatures[i]){
            sta.pop();
        }
        res[i] = sta.empty() ? 0 : sta.top();
        sta.push(i);
    }

    for(int i = 0; i < len; ++i){
        if(res[i] > 0)res[i] -= i;
    }

    return res;
}

//https://leetcode.cn/problems/largest-rectangle-in-histogram/
int largestRectangleArea(vector<int>& vec){
    int len = vec.size();
    vector<int> vLeft(len, -1), vRight(len, len);
    stack<int> sta;
    for(int i = 0; i < len; ++i){
        while(not sta.empty() and vec[sta.top()] >= vec[i])
            sta.pop();
        if(not sta.empty()) vLeft[i] = sta.top();
        sta.push(i);
    }

    sta = {};
    for(int i = len - 1; i >= 0; --i){
        while(not sta.empty() and vec[sta.top()] >= vec[i])
            sta.pop();
        if(not sta.empty()) vRight[i] = sta.top();
        sta.push(i);
    }

    int res = 0;
    for(int i = 0; i < len; ++i){
        int area = vec[i] * (vRight[i] - vLeft[i] - 1);
        res = std::max(res, area);
    }
    return res;
}

//https://leetcode.cn/problems/maximal-rectangle/solution/
int maximalRectangle(vector<vector<char>>& matrix){
    int row = matrix.size(), col = matrix[0].size();
    vector<int> heights(col, 0);
    int res = 0;
    for(int r = 0; r < row; ++r){
        for(int c = 0; c < col; ++c){
            if(matrix[r][c] == '0')heights[c] = 0;
            else heights[c] += 1;
        }

        int area = largestRectangleArea(heights);
        res = std::max(res, area);
    }
    return res;
}

class StockSpanner {
public:
    StockSpanner() {
    }

    int next(int price){
        vec_.push_back(price);
        while(not sta_.empty() and vec_[sta_.top()] <= price){
            sta_.pop();
        }

        int len = vec_.size();
        int res = 0;
        if(sta_.empty()){
            res = len;
        }else{
            res = len - sta_.top() - 1;
        }

        sta_.push(len - 1);
        return res;
    }

    vector<int>  vec_;
    stack<int>   sta_;
};

string removeDuplicateLetters(string s){
    int len = s.size();
    vector<int> counts(26, 0);
    for(auto c : s)++counts[c - 'a'];

    stack<char> sta;
    vector<bool> visited(26, false);
    for(auto c : s){
        int idx = c - 'a';
        --counts[idx];
        if(visited[idx]) continue;

        while(not sta.empty() and sta.top() > c){
            if(counts[sta.top() - 'a'] == 0) break;
            visited[sta.top() - 'a'] = false;
            sta.pop();
        }

        sta.push(c);
        visited[idx] = true;
    }

    string res;
    while(not sta.empty()){
        res.push_back(sta.top());
        sta.pop();
    }

    std::reverse(res.begin(), res.end());
    return res;
}

// https://leetcode.cn/problems/remove-k-digits/
string removeKdigits(string num, int k){
    if(k >= num.size()) return "0";
    stack<char> sta;
    for(auto c : num){
        while(k > 0 and not sta.empty() and sta.top() > c){
            sta.pop();
            --k;
        }
        sta.push(c);
    }

    while(k > 0){
        sta.pop();
        --k;
    }

    string res;
    while(not sta.empty()){
        res.push_back(sta.top());
        sta.pop();
    }
    std::reverse(res.begin(), res.end());
    if(res[0] != '0') return res;
    int i = 0;
    for(; i < res.size() and res[i] == '0'; ++i)
        ;
    return i < res.size() ? res.substr(i) : "0";
}

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2){
    int len = nums2.size();
    std::unordered_map<int, int> mValNext;
    stack<int> sta;
    for(int i = len - 1; i >= 0; --i){
        while(not sta.empty() and sta.top() < nums2[i]){
            sta.pop();
        }
        mValNext[nums2[i]] = sta.empty() ? -1 : sta.top();
        sta.push(nums2[i]);
    }

    vector<int> res;
    for(auto v : nums1){
        res.push_back(mValNext[v]);
    }
    return res;
}

bool isValid(string s){
    const static map<char, char> mLeftRight{{'(', ')'}, {'[', ']'}, {'{', '}'}};
    const static map<char, char> mRightLeft{{')', '('}, {']', '['}, {'}', '{'}};
    stack<char> sta;
    for(auto c : s){
        if(mLeftRight.count(c)){
            if(not sta.empty() and mRightLeft.count(sta.top())){
                return false;
            }
            sta.push(c);
        }else{
            if(sta.empty())return false;
            auto it = mRightLeft.find(c);
            if(it == mRightLeft.end() or it->second != sta.top()) return false;
            sta.pop();
        }
    }
    return sta.empty();
}

void split(const string& str, char ch, vector<string>& vec){
    int len = str.size(), i = 0;
    while(i < len){
        while(i < len and str[i] == ch)++i;
        if(i >= len) break;
        int s = i;
        while(i < len and str[i] != ch) ++i;
        vec.push_back(str.substr(s, i - s));
    }
}

string simplifyPath2(string path){
    vector<string> vec;
    split(path, '/', vec);

    vector<string> sta;
    int len = vec.size();
    for(int i = 0; i < len; ++i){
        if("." == vec[i]){
        }else if(".." == vec[i]){
            if(not sta.empty())sta.pop_back();
        }else{
            sta.push_back(vec[i]);
        }
    }

    len = sta.size();
    string res = "/";
    for(int i = 0; i < len; ++i){
        res += sta[i];
        if(i < len - 1) res += '/';
    }
    return res;
}
