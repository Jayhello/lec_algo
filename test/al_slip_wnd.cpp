//
// Created by wenwen on 2022/7/20.
//

#include <iostream>
#include <gtest/gtest.h>
#include "src/al_slip_wnd.h"

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    testing::FLAGS_gtest_filter = "findMaxConsecutiveOnes*";
    return RUN_ALL_TESTS();

    return 0;
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
