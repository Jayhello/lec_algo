//
// Created by wenwen on 2022/5/17.
//

#include <iostream>
#include <gtest/gtest.h>
#include "src/al_heap.h"
#include "test_comm.h"

void test_feed(){
    Twitter tw;
    for(int i = 1; i < 13; ++i){
        tw.postTweet(1, i);
    }

    auto vec = tw.getNewsFeed(1);
    cout << "feed_list: " <<  tostr(vec) << endl;
}

int main(int argc, char** argv){
    test_feed();

    testing::InitGoogleTest(&argc, argv);
    testing::FLAGS_gtest_filter = "1lastStoneWeight*";
    return RUN_ALL_TESTS();
}

TEST(lastStoneWeight, basic){
    EXPECT_EQ(lastStoneWeight(vector<int>({1})), 1);
    EXPECT_EQ(lastStoneWeight(vector<int>({1, 1})), 0);
    EXPECT_EQ(lastStoneWeight(vector<int>({1, 1, 2})), 0);
    EXPECT_EQ(lastStoneWeight(vector<int>({1, 1, 2, 2})), 0);
    EXPECT_EQ(lastStoneWeight(vector<int>({1, 2, 3})), 0);
    EXPECT_EQ(lastStoneWeight(vector<int>({1, 2, 3, 3})), 1);
}