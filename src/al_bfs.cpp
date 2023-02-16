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
