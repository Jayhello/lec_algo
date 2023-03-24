//
// Created by wenwen on 2023/2/14.
//

#include "al_bfs.h"

void helper200(vector<vector<char>>& grid, vector<vector<bool>>& visit, int r, int c, int& num){
    int row = grid.size(), col = grid[0].size();
    if(r < 0 or c < 0 or r >= row or c >= col){
        return;
    }
    if(visit[r][c])return;
    visit[r][c] = true;
    if('0' == grid[r][c])return;
//    grid[r][c] = '0';
    ++num;

    helper200(grid, visit, r - 1, c, num);
    helper200(grid, visit, r + 1, c, num);
    helper200(grid, visit, r, c - 1, num);
    helper200(grid, visit, r, c + 1, num);
}

int numIslands(vector<vector<char>>& grid){
    int row = grid.size(), col = grid[0].size();
    vector<vector<bool>> visit(row, vector<bool>(col, false));
    int ret = 0;
    for(int r = 0; r < row; ++r){
        for(int c = 0; c < col; ++c){
            int n = 0;
            helper200(grid, visit, r, c, n);
            ret += (n > 0 ? 1 : 0);
        }
    }

    return ret;
}

void helper200v2(vector<vector<char>>& grid, int r, int c){
    int row = grid.size(), col = grid[0].size();
    std::queue<std::pair<int, int>> que;
    que.push({r, c});
    grid[r][c] = '0';
    static const vector<std::pair<int, int>> directions{{-1,0},{1,0},{0,-1},{0,1}};
    while(not que.empty()){
        auto tmp = que.front();
        que.pop();
        for(const auto& d : directions){
            int r1 = tmp.first + d.first;
            int c1 = tmp.second + d.second;
            if(r1 < 0 or r1 >= row or c1 < 0 or c1 >= col) continue;
            if('0' == grid[r1][c1])continue;
            que.push({r1, c1});
            grid[r1][c1] = '0';
        }
    }
}

int numIslands_v2(vector<vector<char>>& grid){
    int row = grid.size(), col = int(grid[0].size());
    int num = 0;
    for(int r = 0; r < row; ++r){
        for(int c = 0; c < col; ++c){
            if('0' == grid[r][c]) continue;
            helper200v2(grid, r, c);
            ++num;
        }
    }
    return num;
}

void helper695(vector<vector<int>>& grid, vector<vector<bool>>& visit, int r, int c, int& num){
    int row = grid.size(), col = grid[0].size();
    if(r < 0 or c < 0 or r >= row or c >= col){
        return;
    }
    if(visit[r][c])return;
    visit[r][c] = true;
    if(0 == grid[r][c])return;
//    grid[r][c] = '0';
    ++num;

    helper695(grid, visit, r - 1, c, num);
    helper695(grid, visit, r + 1, c, num);
    helper695(grid, visit, r, c - 1, num);
    helper695(grid, visit, r, c + 1, num);
}

int maxAreaOfIsland(vector<vector<int>>& grid){
    int row = grid.size(), col = grid[0].size();
    vector<vector<bool>> visit(row, vector<bool>(col, false));
    int ret = 0;
    for(int r = 0; r < row; ++r){
        for(int c = 0; c < col; ++c){
            int n = 0;
            helper695(grid, visit, r, c, n);
            ret = std::max(ret, n);
        }
    }

    return ret;
}

int islandPerimeter(vector<vector<int>>& grid){
    int row = int(grid.size()), col = (grid[0].size());
    int ret = 0;
    for(int r = 0; r < row; ++r){
        for(int c = 0; c < col; ++c){
            if(0 == grid[r][c])continue;
            ret += 4;
            if(r > 0 and grid[r - 1][c]) ret -= 2;
            if(c > 0 and grid[r][c - 1]) ret -= 2;
        }
    }

    return ret;
}

vector<vector<int>> updateMatrix(vector<vector<int>>& mat){
    int row = mat.size(), col = mat[0].size();
    vector<vector<int>> res(row, vector<int>(col, INT32_MAX));
    std::queue<std::pair<int, int>> que;

    for(int r = 0; r < row; ++r){
        for(int c= 0; c < col; ++c){
            if(0 == mat[r][c]){
                res[r][c] = 0;
                que.push({r, c});
            }
        }
    }

    vector<std::pair<int, int>> directions{{-1,0}, {1,0}, {0,-1}, {0,1}};
    while(not que.empty()){
        auto tmp = que.front();
        que.pop();
        for(const auto& d: directions){
            int r = tmp.first + d.first;
            int c = tmp.second + d.second;
            if(r < 0 or r >= row or c < 0 or c >= col)continue;
            if(res[tmp.first][tmp.second] + 1 < res[r][c]){
                res[r][c] = res[tmp.first][tmp.second] + 1;
                que.push({r, c});
            }
        }
    }

    return res;
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

int ladderLength(string beginWord, string endWord, vector<string>& wordList){
    auto it = std::find(wordList.begin(), wordList.end(), endWord);
    if(it == wordList.end()) return 0;

    int len = int(wordList.size());
    std::queue<string> que;
    que.push(beginWord);
    std::vector<bool> visited(len, false);

    int ret = 0;
    while(not que.empty()){
        int num = que.size();
        ++ret;
        for(int i = 0; i < num; ++i){
            string str = que.front();
            que.pop();

            for(int j = 0; j < len; ++j){
                if(visited[j])continue;
                if(not canReach(str, wordList[j])) continue;

                if(wordList[j] == endWord)return ret + 1;

                visited[j] = true;
                que.push(wordList[j]);
            }
        }
    }

    return 0;
}

void getNearest(const string& s, vector<string>& vec){
    int len = s.size();
    vec.reserve(len * 2);
    for(int i = 0; i < len; ++i){
        string s1 = s, s2 = s;
        if(s[i] == '0'){
            s1[i] = '1';
            s2[i] = '9';
        }else if(s[i] == '9'){
            s1[i] = '0';
            s2[i] = '8';
        }else{
            s1[i] += 1;
            s2[i] += -1;
        }

        vec.push_back(s1);
        vec.push_back(s2);
    }
}


int openLock(vector<string>& deadends, string target){
    if(target == "0000") return 0;
    std::unordered_set<string> setDead(deadends.begin(), deadends.end());
    if(setDead.count("0000")) return -1;

    queue<string> que;
    que.push("0000");
    std::unordered_set<string> visited;
    visited.insert("0000");

    int ret = 0;
    while(not que.empty()){
        int n = que.size();
        ++ret;
        for(int i = 0; i < n; ++i){
            string s = que.front();
            que.pop();

            vector<string> vec;
            getNearest(s, vec);
            for(const auto& str : vec){
                if(setDead.count(str)) continue;
                if(visited.count(str))continue;
                if(str == target) return ret;
                visited.insert(str);
                que.push(str);
            }
        }
    }

    return 0;
}

void helper130(const vector<vector<char>>& board, int r, int c,
               vector<vector<bool>>& visited, vector<std::pair<int, int>>& regions, bool& bFlag){
    int row = board.size(), col = board[0].size();
    if(r < 0 or r >= row or c < 0 or c >= col)return;
    if(visited[r][c])return;

    visited[r][c] = true;
    if(board[r][c] == 'X'){
        return;
    }

    regions.emplace_back(r, c);
    if(r == 0 or r == row - 1 or c == 0 or c == col - 1)bFlag = true;
    helper130(board, r - 1, c, visited, regions, bFlag);
    helper130(board, r + 1, c, visited, regions, bFlag);
    helper130(board, r, c - 1, visited, regions, bFlag);
    helper130(board, r, c + 1, visited, regions, bFlag);
}

void solve(vector<vector<char>>& board){
    int row = board.size(), col = board[0].size();

    vector<vector<bool>> visited(row, vector<bool>(col, false));
    for(int r = 0; r < row; ++r){
        for(int c = 0; c < col; ++c){
            vector<std::pair<int, int>> regions;
            bool flag = false;
            helper130(board, r, c, visited, regions, flag);

            if(flag) continue;

            for(const auto& rw : regions){
                board[rw.first][rw.second] = 'X';
            }
        }
    }
}

bool canFinish(int n, vector<vector<int>>& prerequisites){
    vector<int> vec(n , 0);
    for(const auto& req : prerequisites){
        ++vec[req[0]];
    }

    std::queue<int> que;
    for(int i = 0; i < n; ++i){
        if(0 == vec[i])que.push(i);
    }

    while(not que.empty()){
        int idx = que.front();
        que.pop();

        for(const auto& req : prerequisites){
            if(req[1] == idx){
                --vec[req[0]];
                if(0 == vec[req[0]]){
                    que.push(req[0]);
                }
            }
        }
    }

    auto it = std::find_if(vec.begin(), vec.end(), [](int a){
        return a > 0;
    });

    return it == vec.end();
}
