//
// Created by wenwen on 2022/9/26.
//

#include "al_bt.h"
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <climits>

void permute46Helper(const vector<int>& vNums, vector<int>& vTrack, vector<vector<int>>& vRes){
    if(vTrack.size() == vNums.size()){
        vRes.push_back(vTrack);
        return;
    }

    int len = static_cast<int>(vNums.size());
    for(int i = 0; i < len; ++i){
        auto it = std::find(vTrack.begin(), vTrack.end(), vNums[i]);
        if(it != vTrack.end())continue;
        vTrack.push_back(vNums[i]);
        permute46Helper(vNums, vTrack, vRes);
        vTrack.pop_back();
    }
}

vector<vector<int>> permute46(const vector<int>& nums){
    vector<vector<int>> vRes;
    vector<int> vTrack;
    permute46Helper(nums, vTrack, vRes);
    return vRes;
}

void helper46_v2(const vector<int>& nums, vector<int>& path, vector<bool>& visited, vector<vector<int>>& res){
    if(path.size() == nums.size()){
        res.push_back(path);
        return;
    }

    for(int i = 0; i < nums.size(); ++i){
        if(visited[i]) continue;
        visited[i] = true;
        path.push_back(nums[i]);
        helper46_v2(nums, path, visited, res);
        visited[i] = false;
        path.pop_back();
    }
}

vector<vector<int>> permute46_v2(vector<int>& nums){
    vector<int> path;
    vector<bool> visited(nums.size(), false);
    vector<vector<int>> res;
    helper46_v2(nums, path, visited, res);
    return res;
}

void permuteUniqueHelper47(const vector<int>& vNum, vector<bool>& vVisit, vector<int>& vTrack, vector<vector<int>>& vRes){
    if(vTrack.size() == vNum.size()){
        vRes.push_back(vTrack);
        return;
    }

    for(int i = 0; i < static_cast<int>(vNum.size()); ++i){
        if(vVisit[i])continue;
        if(i > 0 and vNum[i] == vNum[i - 1] and (not vVisit[i]))continue;
        vVisit[i] = true;
        vTrack.push_back(vNum[i]);
        permuteUniqueHelper47(vNum, vVisit, vTrack, vRes);
        vVisit[i] = false;
        vTrack.pop_back();
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums){
    std::stable_sort(nums.begin(), nums.end());
    vector<vector<int>> vRes;
    vector<int> vTrack;
    vector<bool> vVisit(nums.size(), false);
    permuteUniqueHelper47(nums, vVisit, vTrack, vRes);
    return vRes;
}

vector<string> letterCasePermutation(string s){
    vector<string> vStr;
    for(auto c : s){
        if(vStr.empty()){
            if(std::isalpha(c)){
                vStr.emplace_back(string(1, std::toupper(c)));
                vStr.emplace_back(string(1, std::tolower(c)));
            }
            else {
                vStr.emplace_back(string(1, c));
            }
            continue;
        }

        if(std::isalpha(c)){
            vector<string> vTmp = vStr;
            for(auto& s : vStr)s.push_back(std::tolower(c));
            for(auto& s : vTmp)s.push_back(std::toupper(c));

            vStr.insert(vStr.end(), vTmp.begin(), vTmp.end());
        }else{
            for(auto& s : vStr)s.push_back(c);
        }
    }

    return vStr;
}

void helper77(vector<vector<int>>& res, vector<int>& tracks, int b, int e, int k){
    if(tracks.size() == k){
        res.push_back(tracks);
        return;
    }

    for(int i = b; i <= e; ++i){
        tracks.push_back(i);
        helper77(res, tracks, i + 1, e, k);
        tracks.pop_back();
    }
}

vector<vector<int>> combine(int n, int k){
    if(k > n) return {};

    vector<vector<int>> res;
    vector<int> tracks;
    helper77(res, tracks, 1, n, k);
    return res;
}

using StrList = vector<string>;
using StrListList = vector<StrList>;

inline bool isPalindrome(const string& s, int b, int e){
    while(b <= e and s[b] == s[e]){
        ++b;
        --e;
    }

    return b > e;
}

void partition131Helper(const string& s, int iStart, StrList& tracks, StrListList& res){
    if(iStart == s.size()){
        res.push_back(tracks);
        return;
    }

    for(int i = iStart; i < int(s.size()); ++i){
        if(not isPalindrome(s, iStart, i)) continue;
        tracks.push_back(s.substr(iStart, i - iStart + 1));
        partition131Helper(s, i + 1, tracks, res);
        tracks.pop_back();
    }
}

vector<vector<string>> partition131(string s){
    StrListList res;
    StrList tracks;
    partition131Helper(s, 0, tracks, res);
    return res;
}

bool helper139(const string& str, const vector<string>& wordDict, int idx){
    if(idx >= str.size()){
        return true;
    }

    int len = int(str.size());
    for(int i = 0; i < int(wordDict.size()); ++i){
        if(len - idx < wordDict[i].size())continue;
        if(str.substr(idx, wordDict[i].size()) != wordDict[i]) continue;

        bool res = helper139(str, wordDict, idx + wordDict[i].size());
        if(res){
            return res;
        }
    }

    return false;
}

bool wordBreak139(string s, const vector<string>& wordDict){
    return helper139(s, wordDict, 0);
}

void combinationSum3Helper(int k, int n, int start, int sum,
                           vector<vector<int>>& res, vector<int>& tracks){
    if(tracks.size() == k){
        if(sum == n){
            res.push_back(tracks);
        }
        return;
    }

    for(int i = start; i <= 9; ++i){
        if(sum + i > n)continue;
        sum += i;
        tracks.push_back(i);
        combinationSum3Helper(k, n, i + 1, sum, res, tracks);
        sum -= i;
        tracks.pop_back();
    }
}

/*
输入: k = 3, n = 9
输出: [[1,2,6], [1,3,5], [2,3,4]]

输入: k = 4, n = 1
输出: []  // 在[1,9]范围内使用4个不同的数字，我们可以得到的最小和是1+2+3+4 = 10，因为10 > 1，没有有效的组合。
*/
vector<vector<int>> combinationSum3(int k, int n){
    vector<vector<int>> res;
    vector<int> tracks;
    combinationSum3Helper(k, n, 1, 0, res, tracks);
    return res;
}

void combinationSum39Helper(const vector<int>& candidates, int target,
                           int idx, int sum, vector<int>& tracks, vector<vector<int>>& res){
    if(sum == target){
        res.push_back(tracks);
        return;
    }

    for(int i = idx; i < int(candidates.size()); ++i){
        if(sum + candidates[i] > target) break;
        sum += candidates[i];
        tracks.push_back(candidates[i]);
        combinationSum39Helper(candidates, target, i, sum, tracks, res);
        sum -= candidates[i];
        tracks.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target){
    std::stable_sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    vector<int> tracks;
    combinationSum39Helper(candidates, target, 0, 0, tracks, res);
    return res;
}

void helper40(const vector<int>& vec, vector<int>& tracks, vector<bool>& visits,
              int target, int sum, int idx, vector<vector<int>>& res){
    if(target == sum){
        res.push_back(tracks);
        return;
    }

    for(int i = idx; i < int(vec.size()); ++i){
        if(i > 0 and vec[i] == vec[i - 1] and !visits[i - 1])continue;
        if(sum + vec[i] > target) break;

        sum += vec[i];
        visits[i] = true;
        tracks.push_back(vec[i]);
        helper40(vec, tracks, visits, target, sum, i + 1, res);
        sum -= vec[i];
        visits[i] = false;
        tracks.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& vec, int target){
    std::sort(vec.begin(), vec.end());
    vector<vector<int>> res;
    vector<int> tracks;
    vector<bool> visits(vec.size(), false);
    helper40(vec, tracks, visits, target, 0, 0, res);
    return res;
}

void helper17(const vector<string>& vStr, int idx, string& tracks, vector<string>& res){
    if(tracks.size() == vStr.size()){
        res.push_back(tracks);
        return;
    }

    for(int i = idx; i < int(vStr.size()); ++i){
        for(auto c : vStr[i]){
            tracks.push_back(c);
            helper17(vStr, i + 1, tracks, res);
            tracks.pop_back();
        }
    }
}

void helper60(const string& src, int& n, vector<bool>& visited, string& tracks, string& res){
    if(tracks.size() == src.size()){
        --n;
        if(0 == n){
            res = tracks;
            return;
        }
    }

    for(int i = 0; i < src.size() and n > 0; ++i){
        if(visited[i]) continue;
        visited[i] = true;
        tracks.push_back(src[i]);
        helper60(src, n, visited, tracks, res);
        visited[i] = false;
        tracks.pop_back();
    }
}

string getPermutation(int n, int k) {
    string s;
    for(int i = 1; i <= n; ++i)s.push_back(i + '0');
    if(n <= 1 or k <= 1) return s;

    int total = 1;
    for(int i = 2; i <= n; ++i) total *= i;

    int per = total / n;
    int i = (k - 1) / per;
    if(i > 0){
        std::swap(s[0], s[i]);
        std::stable_sort(s.begin() + 1, s.end());
    }
    int cnt = k % per;
    cnt = (cnt > 0 ? cnt : per);
    if(k <= 1) return s;

    vector<bool> visited(n, false);
    string tracks, res;
    helper60(s, cnt, visited, tracks, res);
    return res;
}

vector<string> letterCombinations(string digits){
    if(digits.empty())return {};

    static vector<string> VEC = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> vStr, res;
    for(auto c : digits){
        vStr.push_back(VEC[c - '0']);
    }

    string tracks;
    helper17(vStr, 0, tracks, res);
    return res;
}

void helper377(const vector<int>& nums, int target, int cur, int& cnt){
    if(cur == target){
        ++cnt;
        return;
    }
    for(int i = 0; i < nums.size(); ++i){
        if(cur + nums[i] > target) break;
        cur += nums[i];
        helper377(nums, target, cur, cnt);
        cur -= nums[i];
    }
}

int combinationSum4(vector<int>& nums, int target){
    int cnt = 0;
    std::stable_sort(nums.begin(), nums.end());
    helper377(nums, target, 0, cnt);
    return cnt;
}

bool helper698(const vector<int>& nums, int target, int sum){
    return false;
}

bool canPartitionKSubsets(vector<int>& nums, int k){
    return false;
}

bool isValidPart(const string& str){
    if(str.empty() or str.size() > 3) return false;
    if(str.size() > 1 and str[0] == '0'){
        return false;
    }

    int a = std::stoi(str);
    return a >= 0 and a <= 255;
}

string joinStr(const vector<string>& vec, const string& sep){
    string res;
    int len = int(vec.size());
    for(int i = 0; i < len; ++i){
        res += vec[i];
        if(i != len - 1)res += sep;
    }
    return res;
}

void helper93(const string& s, int idx, vector<string>& tracks, vector<string>& res){
    if(idx == s.size()){
        if(tracks.size() < 4) return;
        res.push_back(joinStr(tracks, "."));
        return;
    }

    if(4 == tracks.size()) return;

    for(int i = 1; i <= 3; ++i){
        if(idx + i > s.size())continue;
        string sub = s.substr(idx, i);
        if(not isValidPart(sub)) continue;
        tracks.push_back(sub);
        helper93(s, idx + i, tracks, res);
        tracks.pop_back();
    }
}

vector<string> restoreIpAddresses(string s){
    vector<string> res, tracks;
    helper93(s, 0, tracks, res);
    return res;
}

void helper78(const vector<int>& nums, vector<int>& tracks, vector<vector<int>>& res, int idx){
    res.push_back(tracks);
    for(int i = idx; i < int(nums.size()); ++i){
        tracks.push_back(nums[i]);
        helper78(nums, tracks, res, i + 1);
        tracks.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums){
    vector<vector<int>> res;
    vector<int> tracks;
    helper78(nums, tracks, res, 0);
    return res;
}

bool helper79(const vector<vector<char>>& board, const string& word,
              int idx, int r, int c, vector<vector<bool>>& visits){
    if(idx == word.size()){
        return true;
    }

    int row = board.size(), col = board[0].size();
    if(r < 0 or r >= row or c < 0 or c >= col) return false;
    if(board[r][c] != word[idx]) return false;
    if(visits[r][c]) return false;

    visits[r][c] = true;
    bool res = helper79(board, word, idx + 1, r - 1, c, visits) ||
            helper79(board, word, idx + 1, r + 1, c, visits) ||
            helper79(board, word, idx + 1, r, c - 1, visits) ||
            helper79(board, word, idx + 1, r, c + 1, visits);
    if(res) return res;

    visits[r][c] = false;
    return false;
}

bool exist(vector<vector<char>>& board, string word){
    vector<vector<bool>> visits(board.size(), vector<bool>(board[0].size(), false));
    for(int r = 0; r < board.size(); ++r){
        for(int c = 0; c < board[0].size(); ++c){
            if(helper79(board, word, 0, r, c, visits))
                return true;
        }
    }
    return false;
}

void helper22(int n, string& tracks, vector<string>& res, int left, int right){
    if(left == right and left == n){
        res.push_back(tracks);
        return;
    }

    if(left < n){
        tracks.push_back('(');
        helper22(n, tracks, res, left + 1, right);
        tracks.pop_back();
    }

    if(right < left){
        tracks.push_back(')');
        helper22(n, tracks, res, left, right + 1);
        tracks.pop_back();
    }
}

vector<string> generateParenthesis(int n){
    vector<string> res;
    string tracks;
    helper22(n, tracks, res, 0, 0);
    return res;
}

void binaryValue(int idx, int bits, int n, int threshold, int cnt, int num, vector<int>& nums){
    if(0 == n){
        nums.push_back(0);
        return;
    }

    if(cnt == n){
        if(num <= threshold){
            nums.push_back(num);
        }
        return;
    }

    for(int i = idx; i < bits; ++i){
         num |= (1 << i);
         binaryValue(i + 1, bits, n, threshold, cnt + 1, num, nums);
         num &= (~(1 << i));
    }
}

vector<string> readBinaryWatch(int turnedOn){
    if(turnedOn > 8) return {};

    vector<string> res;
    for(int hCnt = 0;hCnt <= turnedOn; ++hCnt){
        if(hCnt > 3) break;
        int mCnt = turnedOn - hCnt;
        if(mCnt > 5)continue;

        vector<int> hNums, mNums;
        binaryValue(0, 4, hCnt, 11, 0, 0, hNums);
        binaryValue(0, 6, mCnt, 59, 0, 0, mNums);

        for(auto h : hNums){
            for(auto m : mNums){
                string sH = std::to_string(h);
                string sM = (m < 10 ? "0" : "") + std::to_string(m);
                res.push_back(sH + ":" + sM);
            }
        }
    }

    return res;
}

bool isvalid(const vector<vector<char>>& board, int r, int c, char ch){
    for(int i = 0; i < board.size(); ++i){
        if(board[r][i] == ch) return false;
    }

    for(int i = 0; i < board.size(); ++i){
        if(board[i][c] == ch) return false;
    }

    int rs = r / 3 * 3, cs = c / 3 * 3;
    for(int m = 0; m < 3; ++m){
        for(int n = 0; n < 3; ++n){
            if(ch == board[rs + m][cs + n]){
                return false;
            }
        }
    }

    return true;
}

bool helper37(vector<vector<char>>& board){
    int row = int(board.size()), col = int(board.size());
    for(int sr = 0; sr < row; ++sr){
        for(int sc = 0; sc < col; ++sc){
            if(board[sr][sc] != '.') continue;

             for(char ch = '1'; ch <= '9'; ++ch){
                if(not isvalid(board, sr, sc, ch))continue;
                board[sr][sc] = ch;
                int nr = sr, nc = sc + 1;
                if(nc == 9){
                    ++nr;
                    nc = 0;
                }
                bool res = helper37(board);
                if(res) return true;
                 board[sr][sc] = '.';
             }

             return false;
        }
    }

    return true;
}

void solveSudoku(vector<vector<char>>& board){
    helper37(board);
}

bool match51(const vector<string>& vec){
    std::unordered_map<int, int> mColCnt;
    int row = vec.size(), col = vec[0].size();
    for(int c = 0; c < col; ++c){
        for(int r = 0; r < row; ++r){
            if('Q' == vec[r][c]){
                ++mColCnt[c];
                if(mColCnt[c] >= 2) return false;
            }
        }
    }

    for(int r = 0; r < row; ++r){
        for(int c = 0; c < col; ++c){
            for(int n = 1; n < row; ++n){
                if('.' == vec[r][c])continue;

                if(r + n < row and c + n < col and vec[r + n][c + n] == 'Q'){
                    return false;
                }

                if(c - n >= 0 and r + n < row and vec[r + n][c - n] == 'Q'){
                    return false;
                }

            }
        }
    }

    return true;
}

void helper51(vector<vector<string>>& res, vector<string>& tracks, int n){
    if(tracks.size() == n){
        res.push_back(tracks);
        return;
    }

    for(int i = 0; i < n; ++i){
        string str(n, '.');
        str[i] = 'Q';
        tracks.push_back(str);
        if(not match51(tracks)){
            tracks.pop_back();
            continue;
        }

        helper51(res, tracks, n);
        tracks.pop_back();
    }
}

vector<vector<string>> solveNQueens(int n){
    vector<vector<string>> res;
    vector<string> tracks;
    helper51(res, tracks, n);
    return res;
}

string join282(const string& num, const string& tracks){
    int len = int(num.size());
    string res;
    for(int i = 0; i < len; ++i){
        res.push_back(num[i]);
        if(i != len - 1){
            res.push_back(tracks[i]);
        }
    }
    return res;
}

void helper282(const string& num, int target, int idx, int sum, string& tracks, vector<string>& res){
    int len = int(num.size());
    if(idx == len){
        if(sum == target){
            res.push_back(join282(num, tracks));
        }
        return;
    }

    const static string OPS = "+-*";
    for(auto op : OPS){
        int old = sum;
        int n = (num[idx] - '0');
        if('+' == op){
            sum += n;
        }else if('-' == op){
            sum -= n;
        }else{
            sum *= n;
        }

        tracks.push_back(op);
        helper282(num, target, idx + 1, sum, tracks, res);
        sum = old;
        tracks.pop_back();
    }
}

vector<string> addOperators(string num, int target){
    vector<string> res;
    string tracks;
    helper282(num, target, 1, num[0] - '0', tracks, res);
    return res;
}

void helper494(const vector<int>& nums, int target, int idx, int sum, int& cnt){
    int len = int(nums.size());
    if(idx == len){
        if(sum == target) ++cnt;
        return;
    }

    helper494(nums, target, idx + 1, sum + nums[idx], cnt);
    helper494(nums, target, idx + 1, sum - nums[idx], cnt);
}

int findTargetSumWays(const vector<int>& nums, int target){
    int cnt = 0;
    helper494(nums, target, 0, 0, cnt);
    return cnt;
}

void helper416(const vector<int>& nums, int target, int idx, int cur, bool& found){
    if(target == cur){
        found = true;
        return;
    }

    for(int i = idx; i < nums.size(); ++i){
        if(cur + nums[i] > target) break;
        helper416(nums, target, i + 1, cur + nums[i], found);
        if(found) return;
    }
}

bool canPartition(vector<int>& nums){
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    if(sum % 2) return false;

    bool found = false;
    std::stable_sort(nums.begin(), nums.end());
    helper416(nums, sum / 2, 0, 0, found);
    return found;
}

void helper139(const string& s, int idx, const vector<string>& vec, bool& found){
    int len = int(s.size());
    if(len == idx){
        found = true;
        return;
    }

    for(int i = 0; i < vec.size(); ++i){
        if(len - idx < vec[i].size())continue;
        if(s.substr(idx, vec[i].size()) != vec[i])continue;
        helper139(s, idx + vec[i].size(), vec, found);
        if(found) return;
    }
}

bool wordBreak(string s, const vector<string>& wordDict){
    bool found = false;
    helper139(s, 0, wordDict, found);
    return found;
}

bool canReach(const string& s1, const string& s2){
    int count = 0;
    int len = s1.size();
    for(int i = 0; i < len and count < 2; ++i){
        if(s1[i] != s2[i]){
            ++count;
        }
    }
    return count == 1;
}

void helper127(const string& endWord, const vector<string>& wordList,
               vector<string>& vPath, vector<bool>& visited, int& minLen){
    if(vPath.back() == endWord){
        minLen = std::min(int(vPath.size()), minLen);
        return;
    }

    for(int i = 0; i < wordList.size(); ++i){
        if(visited[i]) continue;
        if(not canReach(vPath.back(), wordList[i]))continue;

        vPath.push_back(wordList[i]);
        visited[i] = true;
        helper127(endWord, wordList, vPath, visited, minLen);
        vPath.pop_back();
        visited[i] = false;
    }
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList){
    auto it = std::find(wordList.begin(), wordList.end(), endWord);
    if(it == wordList.end())return 0;

    vector<bool> visited(wordList.size(), false);
    vector<string>  vPath = {beginWord};
    int minLen = INT_MAX;
    helper127(endWord, wordList, vPath, visited, minLen);

    return INT_MAX == minLen ? 0 : minLen;
}
