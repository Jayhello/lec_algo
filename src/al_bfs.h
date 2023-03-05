//
// Created by wenwen on 2023/2/14.
//

#pragma once
#include "al_comm.h"

int numIslands(vector<vector<char>>& grid);

int numIslands_v2(vector<vector<char>>& grid);

//https://leetcode.cn/problems/max-area-of-island/description/
int maxAreaOfIsland(vector<vector<int>>& grid);

//https://leetcode.cn/problems/island-perimeter
int islandPerimeter(vector<vector<int>>& grid);

//https://leetcode.cn/problems/01-matrix/description
// https://leetcode.cn/problems/01-matrix/solutions/171070/c-bfsxiang-jie-by-yi-zhi-ri-shi-jiu/?orderBy=most_votes
// c++ BFS详解
vector<vector<int>> updateMatrix(vector<vector<int>>& mat);

//https://leetcode.cn/problems/word-ladder/description/
int ladderLength(string beginWord, string endWord, vector<string>& wordList);

//https://leetcode.cn/problems/open-the-lock/description/
int openLock(vector<string>& deadends, string target);

//https://leetcode.cn/problems/surrounded-regions/
void solve(vector<vector<char>>& board);
