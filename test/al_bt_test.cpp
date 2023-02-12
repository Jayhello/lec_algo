//
// Created by wenwen on 2022/10/7.
//

#include <iostream>
#include <gtest/gtest.h>
#include "src/al_bt.h"

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    testing::FLAGS_gtest_filter = "wordBreak*";
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