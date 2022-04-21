//
// Created by wenwen on 2022/4/18.
//

#include <iostream>
#include <gtest/gtest.h>
#include "src/al_arr.h"


int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    testing::FLAGS_gtest_filter = "threeSum*";
    return RUN_ALL_TESTS();

    return 0;
}

TEST(twoSum, basic_1){
    vector<int> vec = {0, 2};
    EXPECT_EQ(twoSum({1, 2, 3}, 4), vec);
}

TEST(threeSum, basic){
    vector<vector<int>> vEmpty;

    vector<int> nums = {1, 2, 3};
    EXPECT_EQ(threeSum(nums), vEmpty);

    {
        nums = {0, 0, 0, 0, 0};
        vector<vector<int>> tmp = {{0, 0, 0}};
        EXPECT_EQ(threeSum(nums), tmp);
    }

    {
        nums = {1, -1, 0, 1, -1};
        vector<vector<int>> tmp = {{-1, 0, 1}};
        EXPECT_EQ(threeSum(nums), tmp);
    }

    {
        nums = {1, -1, 0, 1, -1, 2};
        vector<vector<int>> tmp = {{-1, -1, 2}, {-1, 0, 1}};
        EXPECT_EQ(threeSum(nums), tmp);
    }
}