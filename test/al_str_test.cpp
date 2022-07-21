//
// Created by wenwen on 2022/4/18.
//
#include "src/al_str.h"
#include "test_comm.h"
#include <iostream>
#include <vector>
#include <gtest/gtest.h>

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    testing::FLAGS_gtest_filter = "isLongPressedName*";
    return RUN_ALL_TESTS();

    return 0;
}

TEST(isLongPressedName, basic) {
    EXPECT_EQ(isLongPressedName("a", "a"), true);
    EXPECT_EQ(isLongPressedName("a", "aa"), true);
    EXPECT_EQ(isLongPressedName("a", "aaa"), true);

    EXPECT_EQ(isLongPressedName("ab", "aab"), true);
    EXPECT_EQ(isLongPressedName("ab", "aabb"), true);

    EXPECT_EQ(isLongPressedName("a", "b"), false);
    EXPECT_EQ(isLongPressedName("acc", "aac"), false);

};

TEST(repeatedSubstringPattern, basic) {
    EXPECT_EQ(repeatedSubstringPattern("a"), true);
    EXPECT_EQ(repeatedSubstringPattern("aa"), true);
    EXPECT_EQ(repeatedSubstringPattern("aaa"), true);

    EXPECT_EQ(repeatedSubstringPattern("abab"), true);
    EXPECT_EQ(repeatedSubstringPattern("ababab"), true);
    EXPECT_EQ(repeatedSubstringPattern("abcabcabc"), true);
    EXPECT_EQ(repeatedSubstringPattern("abcabc"), true);

    EXPECT_EQ(repeatedSubstringPattern("ab"), false);
    EXPECT_EQ(repeatedSubstringPattern("abc"), false);
    EXPECT_EQ(repeatedSubstringPattern("abac"), false);
    EXPECT_EQ(repeatedSubstringPattern("ababc"), false);
    EXPECT_EQ(repeatedSubstringPattern("ababcc"), false);
};

TEST(replaceSpace, basic) {
    EXPECT_EQ(replaceSpace("a"), "a");
    EXPECT_EQ(replaceSpace("ab"), "ab");

    EXPECT_EQ(replaceSpace("a b"), "a%20b");
    EXPECT_EQ(replaceSpace("a  b"), "a%20%20b");
    EXPECT_EQ(replaceSpace(" ab"), "%20ab");
    EXPECT_EQ(replaceSpace(" ab "), "%20ab%20");
    EXPECT_EQ(replaceSpace("ab "), "ab%20");
    EXPECT_EQ(replaceSpace("a b "), "a%20b%20");
};

TEST(lengthOfLongestSubstring, basic) {
    EXPECT_EQ(lengthOfLongestSubstring("abcce"), "abc");
    EXPECT_EQ(lengthOfLongestSubstring("aaa"), "a");
    EXPECT_EQ(lengthOfLongestSubstring("a"), "a");
    EXPECT_EQ(lengthOfLongestSubstring("aa"), "a");
    EXPECT_EQ(lengthOfLongestSubstring("xyabxz"), "yabxz");
    EXPECT_EQ(lengthOfLongestSubstring("pwwkew"), "wke");
};

TEST(strStr, basic) {
    EXPECT_EQ(strStr("12341256", "12"), 0);
    EXPECT_EQ(strStr("abcde", "cd"), 2);
    EXPECT_EQ(strStr("abcde", "de"), 3);
    EXPECT_EQ(strStr("abcde", "abcde"), 0);
    EXPECT_EQ(strStr("abcde", "cde"), 2);

    EXPECT_EQ(strStr("12", "123"), -1);
    EXPECT_EQ(strStr("12edf", "2d"), -1);

};

TEST(splitString, basic) {
    std::vector<string> vec;
    vec = {"34", "56"};
    EXPECT_EQ(splitString("12341256", "12"), vec);

    vec = {"12"};
    EXPECT_EQ(splitString("111112", "11"), vec);

    vec = {"56", "34"};
    EXPECT_EQ(splitString("56123412", "12"), vec);

    vec = {"1", "23"};
    EXPECT_EQ(splitString("12223", "22"), vec);

    vec = {"1234"};
    EXPECT_EQ(splitString("1234", "22"), vec);
};

TEST(Split, basic){
    std::vector<string> vec;
    vec = {"abc", "def", "ghc"};
    EXPECT_EQ(Split("abc.def.ghc", '.'), vec);

    vec = {"home", "xy", "code"};
    EXPECT_EQ(Split("/home///xy//code", '/'), vec);

    vec = {"home", "xy", "code"};
    EXPECT_EQ(Split("//home///xy//code", '/'), vec);

    vec = {"home", "xy", "code"};
    EXPECT_EQ(Split("//home///xy//code////", '/'), vec);

    vec = {"abc"};
    EXPECT_EQ(Split("abc", '.'), vec);

    vec = {"1", "2", "3"};
    EXPECT_EQ(Split("1.2.3", '.'), vec);
};


TEST(int2ip, basic) {
    EXPECT_EQ(int2ip(3715828229), "221.123.10.5");
    EXPECT_EQ(int2ip(0), "0.0.0.0");
    EXPECT_EQ(int2ip(16843009), "1.1.1.1");
    EXPECT_EQ(int2ip(33686018), "2.2.2.2");
};

TEST(ip2Int, basic) {
    EXPECT_EQ(ip2Int("221.123.10.5"), 3715828229);
    EXPECT_EQ(ip2Int("0.0.0.0"), 0);
    EXPECT_EQ(ip2Int("1.1.1.1"), 16843009);
    EXPECT_EQ(ip2Int("1.1.1.2"), 16843010);
    EXPECT_EQ(ip2Int("2.2.2.2"), 33686018);

};

TEST(float2String, basic) {
    EXPECT_EQ(float2String(2.13), "2.13");
    EXPECT_EQ(float2String(1.00), "1");
    EXPECT_EQ(float2String(0.0123), "0.0123");
    EXPECT_EQ(float2String(1230.0123), "1230.0123");
};

TEST(StrToFloat, basic) {
    EXPECT_TRUE(floatEqual(StrToFloat("2.13"), 2.13));
    EXPECT_TRUE(floatEqual(StrToFloat("323.13"), 323.13));
    EXPECT_TRUE(floatEqual(StrToFloat("0"), 0));
    EXPECT_TRUE(floatEqual(StrToFloat("123.9999"), 123.9999));
};

TEST(powOf2NK, basic) {
    EXPECT_EQ(powOf2NK(1), "2");
    EXPECT_EQ(powOf2NK(2), "4");
    EXPECT_EQ(powOf2NK(8), "256");
    EXPECT_EQ(powOf2NK(10), "1024");
    EXPECT_EQ(powOf2NK(32), "4294967296");
}


TEST(multiply43, basic) {
    EXPECT_EQ(multiply43("1", "2"), "2");
    EXPECT_EQ(multiply43("1", "0"), "0");
    EXPECT_EQ(multiply43("2", "3"), "6");
    EXPECT_EQ(multiply43("7", "9"), "63");
    EXPECT_EQ(multiply43("99", "38"), "3762");
    EXPECT_EQ(multiply43("123", "123"), "15129");

    EXPECT_EQ(multiply43("999", "888"), to_string(999 * 888));
    EXPECT_EQ(multiply43("9919", "8188"), to_string(9919 * 8188));
}

TEST(addStrings, basic) {
    EXPECT_EQ(addStrings("1", "2"), "3");
    EXPECT_EQ(addStrings("0", "0"), "0");

    EXPECT_EQ(addStrings("4", "8"), "12");
    EXPECT_EQ(addStrings("1", "99"), "100");
    EXPECT_EQ(addStrings("11", "99"), "110");
    EXPECT_EQ(addStrings("1234", "1234"), "2468");
}

TEST(validPalindrome680, basic){
    EXPECT_EQ(validPalindrome680("a"), true);
    EXPECT_EQ(validPalindrome680("aa"), true);
    EXPECT_EQ(validPalindrome680("aab"), true);
    EXPECT_EQ(validPalindrome680("caa"), true);
    EXPECT_EQ(validPalindrome680("aca"), true);
    EXPECT_EQ(validPalindrome680("abca"), true);

    EXPECT_EQ(validPalindrome680("abc"), false);
}

TEST(longestPalindrome, basic){
    EXPECT_EQ(longestPalindrome("a"), 1);
    EXPECT_EQ(longestPalindrome("aa"), 2);
    EXPECT_EQ(longestPalindrome("baa"), 3);
    EXPECT_EQ(longestPalindrome("baac"), 3);
    EXPECT_EQ(longestPalindrome("baba"), 4);
    EXPECT_EQ(longestPalindrome("badba"), 5);
    EXPECT_EQ(longestPalindrome("baddba"), 6);
}

TEST(isPalindrome, basic){
    EXPECT_EQ(isPalindrome("1"), true);
    EXPECT_EQ(isPalindrome(""), true);
    EXPECT_EQ(isPalindrome("11"), true);
    EXPECT_EQ(isPalindrome("1  1"), true);
    EXPECT_EQ(isPalindrome("1  1   "), true);
    EXPECT_EQ(isPalindrome("1  1   1"), true);
    EXPECT_EQ(isPalindrome("  1  1   1  "), true);
    EXPECT_EQ(isPalindrome("A man, a plan, a canal: Panama"), true);
    EXPECT_EQ(isPalindrome("race a car"), false);

    EXPECT_EQ(isPalindrome("a11"), false);
    EXPECT_EQ(isPalindrome("a11a"), true);
    EXPECT_EQ(isPalindrome("ac 11a"), false);
}

TEST(compareVersion, basic){
    EXPECT_EQ(compareVersion("1", "1"), 0);
    EXPECT_EQ(compareVersion("1.1", "1.1"), 0);
    EXPECT_EQ(compareVersion("1.01", "1.01"), 0);
    EXPECT_EQ(compareVersion("1.001", "1.01"), 0);

    EXPECT_EQ(compareVersion("1.0", "1.0.0"), 0);

    EXPECT_EQ(compareVersion("0.1", "1.0"), -1);
    EXPECT_EQ(compareVersion("1.10", "1.01"), 1);
}

TEST(transNK, basic){
    EXPECT_EQ(transNK("A", 1), "a");
    EXPECT_EQ(transNK("AA", 2), "aa");

    EXPECT_EQ(transNK("Ab", 2), "aB");
    EXPECT_EQ(transNK("ab", 2), "AB");
    EXPECT_EQ(transNK("AB", 2), "ab");

    EXPECT_EQ(transNK("   AB  cd ", 10), " CD  ab   ");
    EXPECT_EQ(transNK("This is a sample", 16), "SAMPLE A IS tHIS");
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
