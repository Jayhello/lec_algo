//
// Created by wenwen on 2023/3/8.
//

#include "src/al_tree.h"
#include <iostream>
#include <vector>
#include <gtest/gtest.h>

int main(int argc, char** argv){
    auto p = deserialize("1 2 x x 3 4 x x 5 x x");

    string str = serialize(p);

    string str2 = v2::serialize(p);

//    v2::deserialize("1 2 3 x x 4 x x 5 x x");
    auto p2 = v2::deserialize(str2);

    testing::InitGoogleTest(&argc, argv);
    testing::FLAGS_gtest_filter = "serialize*";
    return RUN_ALL_TESTS();

    return 0;
}

TEST(serialize, basic) {

};
