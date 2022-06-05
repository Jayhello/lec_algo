//
// Created by wenwen on 2022/5/24.
//

#include "src/al_que_sta.h"
#include "test_comm.h"
#include <iostream>
#include <gtest/gtest.h>

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    testing::FLAGS_gtest_filter = "calcExpress11*";
    return RUN_ALL_TESTS();

    return 0;
}

TEST(calcExpress11, basic){
    EXPECT_EQ(calcExpress11("-(3)"), -3);
    EXPECT_EQ(calcExpress11("(3)"), 3);
    EXPECT_EQ(calcExpress11("(3 + 1)"), 4);
    EXPECT_EQ(calcExpress11("(3 - 1)"), 2);
    EXPECT_EQ(calcExpress11("(3 - 1 + 2)"), 4);
    EXPECT_EQ(calcExpress11("(3 - 1 + 2) - (3 +  5)"), -4);
    EXPECT_EQ(calcExpress11("-(3 - 1 + 2) - (3 +  5)"), -12);
    EXPECT_EQ(calcExpress11("14-(3 - 1 + 2) - (3 +  5)"), 2);

    EXPECT_EQ(calcExpress11("-(3 + (4 + 5))"), -12);
    EXPECT_EQ(calcExpress11("- (3 + (4 + 5))"), -12);

}

TEST(calcExpress3, basic){

    EXPECT_EQ(calcExpress3("-(3 + (4 + 5))"), -12);
    EXPECT_EQ(calcExpress3("- (3 + (4 + 5))"), -12);

    EXPECT_EQ(calcExpress3("(2 + 3) * 2"), 10);
    EXPECT_EQ(calcExpress3("(-3) * 2"), -6);
    EXPECT_EQ(calcExpress3("(-3) * 2"), -6);
    EXPECT_EQ(calcExpress3("(2 + (3 / 2 * 3)) * 2"), 10);
    EXPECT_EQ(calcExpress3("(2 + (3 / 2 * 3) + 2) * 2"), 14);

    EXPECT_EQ(calcExpress3(""), 0);
    EXPECT_EQ(calcExpress3("1"), 1);
    EXPECT_EQ(calcExpress3("1  "), 1);
    EXPECT_EQ(calcExpress3("-1  "), -1);
    EXPECT_EQ(calcExpress3("+1  "), 1);
    EXPECT_EQ(calcExpress3("  +1   "), 1);
    EXPECT_EQ(calcExpress3("1  +1 -  2  "), 0);
    EXPECT_EQ(calcExpress3("1  +1 -  3  "), -1);
    EXPECT_EQ(calcExpress3(" 100  + 99 -  101  "), 98);
    EXPECT_EQ(calcExpress3(" 101 - 100 - 99 "), -98);
    EXPECT_EQ(calcExpress3(" 1  +  2 +  4  + 3 + 5 "), 15);
    EXPECT_EQ(calcExpress3(" 1  -  2 +  4  + 3 - 5 "), 1);

    EXPECT_EQ(calcExpress3("1  *  2 "), 2);
    EXPECT_EQ(calcExpress3("1 +  3 +  1  *  2 "), 6);
    EXPECT_EQ(calcExpress3("1 +  3 - 2 +  2  *  2 "), 6);
    EXPECT_EQ(calcExpress3("1  + 5  /  2 * 2"), 5);
    EXPECT_EQ(calcExpress3("1  + 5  /  2 / 2 * 2"), 3);
    EXPECT_EQ(calcExpress3("3 / 2 + 1 * 2 * 3  + 5  /  2 / 2 * 2"), 9);
    EXPECT_EQ(calcExpress3("3 * 1 / 2  + 5  /  3 / 2 * 2"), 1);
}

TEST(calcExpress2, basic){
    EXPECT_EQ(calcExpress2(""), 0);
    EXPECT_EQ(calcExpress2("1"), 1);
    EXPECT_EQ(calcExpress2("1  "), 1);
    EXPECT_EQ(calcExpress2("-1  "), -1);
    EXPECT_EQ(calcExpress2("+1  "), 1);
    EXPECT_EQ(calcExpress2("  +1   "), 1);
    EXPECT_EQ(calcExpress2("1  +1 -  2  "), 0);
    EXPECT_EQ(calcExpress2("1  +1 -  3  "), -1);
    EXPECT_EQ(calcExpress2(" 100  + 99 -  101  "), 98);
    EXPECT_EQ(calcExpress2(" 101 - 100 - 99 "), -98);
    EXPECT_EQ(calcExpress2(" 1  +  2 +  4  + 3 + 5 "), 15);
    EXPECT_EQ(calcExpress2(" 1  -  2 +  4  + 3 - 5 "), 1);

    EXPECT_EQ(calcExpress2("1  *  2 "), 2);
    EXPECT_EQ(calcExpress2("1 +  3 +  1  *  2 "), 6);
    EXPECT_EQ(calcExpress2("1 +  3 - 2 +  2  *  2 "), 6);
    EXPECT_EQ(calcExpress2("1  + 5  /  2 * 2"), 5);
    EXPECT_EQ(calcExpress2("1  + 5  /  2 / 2 * 2"), 3);
    EXPECT_EQ(calcExpress2("3 / 2 + 1 * 2 * 3  + 5  /  2 / 2 * 2"), 9);
    EXPECT_EQ(calcExpress2("3 * 1 / 2  + 5  /  3 / 2 * 2"), 1);
}

TEST(calcExpress1, basic){
    EXPECT_EQ(calcExpress1(""), 0);
    EXPECT_EQ(calcExpress1("1"), 1);
    EXPECT_EQ(calcExpress1("1  "), 1);
    EXPECT_EQ(calcExpress1("-1  "), -1);
    EXPECT_EQ(calcExpress1("+1  "), 1);
    EXPECT_EQ(calcExpress1("  +1   "), 1);
    EXPECT_EQ(calcExpress1("1  +1 -  2  "), 0);
    EXPECT_EQ(calcExpress1("1  +1 -  3  "), -1);
    EXPECT_EQ(calcExpress1(" 100  + 99 -  101  "), 98);
    EXPECT_EQ(calcExpress1(" 101 - 100 - 99 "), -98);
    EXPECT_EQ(calcExpress1(" 1  +  2 +  4  + 3 + 5 "), 15);
    EXPECT_EQ(calcExpress1(" 1  -  2 +  4  + 3 - 5 "), 1);
}

TEST(simplifyPath, basic){
    EXPECT_EQ(simplifyPath("/home"), "/home");
    EXPECT_EQ(simplifyPath("/home/"), "/home");
    EXPECT_EQ(simplifyPath("/home/."), "/home");
    EXPECT_EQ(simplifyPath("/a/./b/../../c/"), "/c");
    EXPECT_EQ(simplifyPath("/.."), "/");
    EXPECT_EQ(simplifyPath("/home//foo"), "/home/foo");
}

TEST(backspaceCompare, basic){
    EXPECT_EQ(backspaceCompare("a", "a"), true);
    EXPECT_EQ(backspaceCompare("d#a", "a"), true);
    EXPECT_EQ(backspaceCompare("a#c", "d#c"), true);
    EXPECT_EQ(backspaceCompare("###a", "a"), true);
    EXPECT_EQ(backspaceCompare("#a", "a"), true);
    EXPECT_EQ(backspaceCompare("", ""), true);

    EXPECT_EQ(backspaceCompare("a", ""), false);
    EXPECT_EQ(backspaceCompare("a", "c"), false);
    EXPECT_EQ(backspaceCompare("ac", "a#c"), false);
}
