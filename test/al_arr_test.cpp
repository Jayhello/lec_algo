//
// Created by wenwen on 2022/4/18.
//

#include <iostream>
#include <gtest/gtest.h>
#include "src/al_arr.h"


int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
//    testing::FLAGS_gtest_filter = "throw_exception*";
    return RUN_ALL_TESTS();

    return 0;
}

TEST(twoSum, basic_1){
    vector<int> vec = {0, 2};
    EXPECT_EQ(twoSum({1, 2, 3}, 4), vec);
}
