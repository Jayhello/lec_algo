//
// Created by wenwen on 2023/8/23.
//

#include <iostream>
#include <gtest/gtest.h>
#include "src/al_sort.h"

void test_heap_sort();

int main(int argc, char** argv){

//    test_heap_sort();
//    findKthLargest_2({3,2,3,1,2,4,5,5,6}, 4);

    testing::InitGoogleTest(&argc, argv);
    testing::FLAGS_gtest_filter = "sort*";
    return RUN_ALL_TESTS();

    return 0;
}

void test_heap_sort(){
    {
        vector<int> nums{1, 3, 2, 4};
        heapSort1(nums);
        print(nums);
    }

    {
        vector<int> nums{2};
        heapSort1(nums);
        print(nums);
    }

    {
        vector<int> nums{2, 1};
        heapSort1(nums);
        print(nums);
    }

    {
        vector<int> nums{2, 1, 3};
        heapSort1(nums);
        print(nums);
    }

    {
        vector<int> nums{2, 7, 1, 2, 3, 4, 2, 5, 7};
        heapSort1(nums);
        print(nums);
    }
}
