//
// Created by wenwen on 2022/4/18.
//
#include "src/al_str.h"
#include "test_comm.h"
#include <iostream>
#include <gtest/gtest.h>

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    testing::FLAGS_gtest_filter = "reverseStr541*";
    return RUN_ALL_TESTS();

    return 0;
}

TEST(reverseStr541, basic){
    EXPECT_EQ(reverseStr541("12", 1), "12");
    EXPECT_EQ(reverseStr541("1", 1), "1");
    EXPECT_EQ(reverseStr541("abcdefg", 2), "bacdfeg");
    EXPECT_EQ(reverseStr541("abcd", 2), "bacd");
    EXPECT_EQ(reverseStr541("abc", 2), "bac");

    EXPECT_EQ(reverseStr541("abcefghi", 3), "cbaefgih");

}

TEST(countSegments, basic){
    EXPECT_EQ(countSegments(""), 0);
    EXPECT_EQ(countSegments("1"), 1);
    EXPECT_EQ(countSegments("12"), 1);
    EXPECT_EQ(countSegments("12   "), 1);
    EXPECT_EQ(countSegments("12   3"), 2);
    EXPECT_EQ(countSegments("12   3   "), 2);
    EXPECT_EQ(countSegments("12   3   abc"), 3);
    EXPECT_EQ(countSegments("12   3   abc "), 3);
    EXPECT_EQ(countSegments("12   3   abc asd"), 4);
    EXPECT_EQ(countSegments("1 2"), 2);
    EXPECT_EQ(countSegments("a, b, c"), 3);

}

TEST(reverseWords, basic){
    EXPECT_EQ(reverseWords("1"), "1");
    EXPECT_EQ(reverseWords("12"), "12");
    EXPECT_EQ(reverseWords("123"), "123");
    EXPECT_EQ(reverseWords("1 2"), "2 1");
    EXPECT_EQ(reverseWords("1  2"), "2 1");
    EXPECT_EQ(reverseWords("1 2 3"), "3 2 1");
    EXPECT_EQ(reverseWords("  1 2 3"), "3 2 1");
    EXPECT_EQ(reverseWords("1 2 3   "), "3 2 1");
    EXPECT_EQ(reverseWords("     1 2 3   "), "3 2 1");
    EXPECT_EQ(reverseWords("hello world   "), "world hello");
    EXPECT_EQ(reverseWords("hello world"), "world hello");
    EXPECT_EQ(reverseWords("   hello    world   "), "world hello");
}

TEST(lengthOfLastWord, basic){
    EXPECT_EQ(lengthOfLastWord(""), 0);
    EXPECT_EQ(lengthOfLastWord(" "), 0);
    EXPECT_EQ(lengthOfLastWord("12"), 2);
    EXPECT_EQ(lengthOfLastWord("1"), 1);
    EXPECT_EQ(lengthOfLastWord("1 "), 1);
    EXPECT_EQ(lengthOfLastWord(" 1"), 1);
    EXPECT_EQ(lengthOfLastWord("hello world"), 5);
    EXPECT_EQ(lengthOfLastWord("hello world "), 5);
    EXPECT_EQ(lengthOfLastWord("hello world  "), 5);
}

TEST(countAndSay_38, basic){
#define __TEST_38__(n, sRight)       \
    {                                \
        auto str = countAndSay_38(n);\
        EXPECT_EQ(str, sRight);      \
    }

    __TEST_38__(1, "1")
    __TEST_38__(2, "11")
    __TEST_38__(3, "21")
    __TEST_38__(4, "1211")
    __TEST_38__(5, "111221")
    __TEST_38__(6, "312211")

#undef __TEST_38__
}

TEST(de_encode271, basic){
#define __TEST_ONCE(vec, str)\
    string sRes = encode271(vec);          \
    printf("encode: %s\n", sRes.c_str());  \
    EXPECT_EQ(sRes, str);                  \
    auto vRes = decode271(str);            \
    EXPECT_EQ(vRes, vec);                  \
    printf("decode: %s\n", tostr(vRes).c_str()); \

    {
        vector<string> vec = {"a","ab","abc"};
        string str = "1/a2/ab3/abc";
        __TEST_ONCE(vec, str)
    }

    {
        vector<string> vec = {"a","","abc"};
        string str = "1/a0/3/abc";
        __TEST_ONCE(vec, str)
    }
}
