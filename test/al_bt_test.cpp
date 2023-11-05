//
// Created by wenwen on 2022/10/7.
//

#include <iostream>
#include <gtest/gtest.h>
#include "src/al_bt.h"

namespace test{
bool match(const vector<vector<char>>& board, int r, int c, char ch){
    for(int i = 0; i < 9; ++i){  // 同一行
        if(board[r][i] == ch) return false;
    }

    for(int i = 0; i < 9; ++i){  // 同一列
        if(board[i][c] == ch) return false;
    }

    int row = r / 3, col = c / 3;
    for(int i = 0; i <= 2; ++i){
        for(int j = 0; j <= 2; ++j){
            int m = row * 3 + i, k = col * 3 + j;
            if(board[m][k] == ch) return false;
        }
    }

    return true;
}

void helper37(vector<vector<char>>& board, int row, int col, bool& found){
    if(row == 9){
        found = true;
        return;
    }

    for(int r = row; r < 9 and not found; ++r){
        for(int c = col; c < 9 and not found; ++c){
//            printf("r: %d, c: %d \n", r, c);
            if(8 == r and 8 == c and '.' != board[r][c]){
                helper37(board, 9, 0, found);
                break;
            }

            if('.' != board[r][c]) continue;

            for(int n = 1; n <= 9 and not found; ++n){
                if(not match(board, r, c, n + '0')) continue;
                board[r][c] = n + '0';
                int next_col = c + 1, next_row = r;
                if(next_col == 9){
                    next_col = 0;
                    next_row += 1;
                }
                helper37(board, next_row, next_col, found);
                if(not found) board[r][c] = '.';
            }
        }
    }
}

void solveSudoku2(vector<vector<char>>& board) {
    bool found = false;
    helper37(board, 0, 0, found);
}

} // test

int main(int argc, char** argv){
    vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    test::solveSudoku2(board);

    testing::InitGoogleTest(&argc, argv);
//    testing::FLAGS_gtest_filter = "wordBreak*";
    return RUN_ALL_TESTS();

    return 0;
}

TEST(wordBreak, basic) {
    EXPECT_EQ(wordBreak("a", {"a", "b"}), true);
    EXPECT_EQ(wordBreak("a", {"c", "b"}), false);
    EXPECT_EQ(wordBreak("a", {"c", "aa"}), false);
    EXPECT_EQ(wordBreak("ab", {"a", "b"}), true);
    EXPECT_EQ(wordBreak("acb", {"a", "b"}), false);
    EXPECT_EQ(wordBreak("acb", {"ca", "b"}), false);
    EXPECT_EQ(wordBreak("leetcode", {"leet", "code"}), true);
    EXPECT_EQ(wordBreak("applepenapple", {"apple", "pen"}), true);
    EXPECT_EQ(wordBreak("catsandog", {"cats", "dog", "sand", "and", "cat"}), false);
};

TEST(findTargetSumWays, basic){
    EXPECT_EQ(findTargetSumWays({1, 2}, 3), 1);
    EXPECT_EQ(findTargetSumWays({1,1,1,1,1}, 3), 5);

}

TEST(addOperators, baisc){
    vector<string> res;
    EXPECT_EQ(addOperators("12", 2), vector<string>{"1*2"});
};

TEST(wordBreak139, basic) {
    EXPECT_TRUE(wordBreak139("leetcode", {"leet", "code"}));
    EXPECT_TRUE(wordBreak139("applepenapple", {"apple", "pen"}));
    EXPECT_FALSE(wordBreak139("catsandog", {"cats", "dog", "sand", "and", "cat"}));
};

TEST(combine, basic) {
    vector<vector<int>> res, vRight;
    res = combine(1, 1);
    vRight = {{1}};
    EXPECT_EQ(vRight, res);

    res = combine(2, 1);
    vRight = {{1}, {2}};
    EXPECT_EQ(vRight, res);

    res = combine(3, 2);
    vRight = {{1, 2}, {1, 3}, {2, 3}};
    EXPECT_EQ(vRight, res);
};

TEST(letterCasePermutation, basic){
    vector<string> res, vRight;
    res = letterCasePermutation("123");
    vRight = {"123"};
    EXPECT_EQ(vRight, res);

    res = letterCasePermutation("123a");
    vRight = {"123a", "123A"};
    EXPECT_EQ(vRight, res);

}

TEST(permute46, basic){
    vector<vector<int>> vRes, vTmp;
    vRes = permute46({1, 2});
    vTmp = {{1, 2}, {2, 1}};
    EXPECT_EQ(vRes, vTmp);

}