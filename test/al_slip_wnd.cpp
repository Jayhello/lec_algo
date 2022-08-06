//
// Created by wenwen on 2022/7/20.
//

#include <iostream>
#include <gtest/gtest.h>
#include "src/al_slip_wnd.h"

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    testing::FLAGS_gtest_filter = "findLength*";
    return RUN_ALL_TESTS();

    return 0;
}

TEST(findLength, basic) {
    EXPECT_EQ(findLength({1}, {1}), 1);
    EXPECT_EQ(findLength({1}, {0}), 0);
    EXPECT_EQ(findLength({0}, {1}), 0);
    EXPECT_EQ(findLength({1}, {1, 1}), 1);
    EXPECT_EQ(findLength({1, 1}, {1}), 1);
    EXPECT_EQ(findLength({1, 1}, {1, 1}), 2);
    EXPECT_EQ(findLength({1, 1}, {1, 1, 1}), 2);
    EXPECT_EQ(findLength({1, 1, 1}, {1, 1, 1}), 3);
    EXPECT_EQ(findLength({1,2,3,2,1}, {3,2,1,4,7}), 3);
    EXPECT_EQ(findLength({1,2,3,2,1, 3, 4}, {1,2,3,4,2, 1, 3 ,4}), 4);
    EXPECT_EQ(findLength({1,2,3,2,1}, {3,2,1,4}), 3);
};

TEST(minSubArrayLen, basic){
    EXPECT_EQ(minSubArrayLen(7, {2,3,1,2,4,3}), 2);
    EXPECT_EQ(minSubArrayLen(2, {1,1,1}), 2);
    EXPECT_EQ(minSubArrayLen(2, {1,2,1}), 1);
    EXPECT_EQ(minSubArrayLen(4, {1,3,4}), 1);
    EXPECT_EQ(minSubArrayLen(4, {1,1,1}), 0);
}

TEST(lengthOfLongestSubstring, basic) {
    EXPECT_EQ(lengthOfLongestSubstring("aaa"), 1);
    EXPECT_EQ(lengthOfLongestSubstring("a"), 1);
    EXPECT_EQ(lengthOfLongestSubstring("aa"), 1);
    EXPECT_EQ(lengthOfLongestSubstring("ab"), 2);
    EXPECT_EQ(lengthOfLongestSubstring("aab"), 2);
    EXPECT_EQ(lengthOfLongestSubstring("abcce"), 3);
    EXPECT_EQ(lengthOfLongestSubstring("xyabxz"), 5);
    EXPECT_EQ(lengthOfLongestSubstring("pwwkew"), 3);
};

TEST(checkInclusion, basic){
    EXPECT_EQ(checkInclusion("a", "a"), true);
    EXPECT_EQ(checkInclusion("ab", "eidbaooo"), true);
    EXPECT_EQ(checkInclusion("ab", "eidboaoo"), false);
    EXPECT_EQ(checkInclusion("abc", "abbbca"), true);
    EXPECT_EQ(checkInclusion("hello", "ooolleoooleh"), false);
    EXPECT_EQ(checkInclusion("ky", "ainwkckifykxlribaypk"), true);
}

TEST(minWindow, basic){
    EXPECT_EQ(minWindow("a", "a"), "a");
    EXPECT_EQ(minWindow("aa", "a"), "a");
    EXPECT_EQ(minWindow("ADOBECODEBANC", "ABC"), "BANC");

    EXPECT_EQ(minWindow("abca", "ac"), "ca");
    EXPECT_EQ(minWindow("abcaa", "aac"), "caa");
}

TEST(findMaxConsecutiveOnes, basic){
    EXPECT_EQ(findMaxConsecutiveOnes({1}), 1);
    EXPECT_EQ(findMaxConsecutiveOnes({1, 1}), 2);
    EXPECT_EQ(findMaxConsecutiveOnes({1, 1, 1}), 3);

    EXPECT_EQ(findMaxConsecutiveOnes({1, 0}), 1);
    EXPECT_EQ(findMaxConsecutiveOnes({0, 1}), 1);
    EXPECT_EQ(findMaxConsecutiveOnes({0}), 0);
    EXPECT_EQ(findMaxConsecutiveOnes({0, 0}), 0);

    EXPECT_EQ(findMaxConsecutiveOnes({1, 0, 1}), 1);
    EXPECT_EQ(findMaxConsecutiveOnes({1, 0, 1, 0}), 1);
    EXPECT_EQ(findMaxConsecutiveOnes({1, 0, 1, 0, 1, 1}), 2);
    EXPECT_EQ(findMaxConsecutiveOnes({1, 0, 1, 1, 0, 1, 1}), 2);
    EXPECT_EQ(findMaxConsecutiveOnes({1, 0, 1, 1, 0, 1, 1, 1}), 3);
};
