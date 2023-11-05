//
// Created by wenwen on 2022/4/18.
//

#include <iostream>
#include <gtest/gtest.h>
#include "src/al_arr.h"
int main(int argc, char** argv){

    testing::InitGoogleTest(&argc, argv);
    testing::FLAGS_gtest_filter = "convert6*";
    return RUN_ALL_TESTS();

    return 0;
}

TEST(convert6, basic){
    EXPECT_EQ(convert6("1", 1), "1");
    EXPECT_EQ(convert6("12", 1), "12");
    EXPECT_EQ(convert6("12", 2), "12");
    EXPECT_EQ(convert6("123", 2), "132");

    EXPECT_EQ(convert6("1234", 3), "1243");
    EXPECT_EQ(convert6("123456", 2), "135246");
    EXPECT_EQ(convert6("123456", 3), "152463");
}

TEST(generateMatrix, basic){
    vector<vector<int>> matrix;
    {
        matrix = {{1}};
        EXPECT_EQ(generateMatrix(1), matrix);
    }

    {
        matrix = {{1, 2}, {4, 3}};
        EXPECT_EQ(generateMatrix(2), matrix);
    }

    {
        matrix = {{1, 2, 3}, {8, 9, 4}, {7, 6, 5}};
        EXPECT_EQ(generateMatrix(3), matrix);
    }
}

TEST(spiralOrder, basic){
    vector<vector<int>> matrix;
    vector<int> nums;

    {
        nums = {0, 1, 2};
        vector<vector<int>> tmp = {{0, 1, 2}};
        EXPECT_EQ(spiralOrder(tmp), nums);
    }

    {
        nums = {0, 1, 2, 5, 4, 3};
        vector<vector<int>> tmp = {{0, 1, 2}, {3, 4, 5}};
        EXPECT_EQ(spiralOrder(tmp), nums);
    }
    {
        nums = {0, 1, 2, 5, 8, 7, 6, 3, 4};
        vector<vector<int>> tmp = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};
        EXPECT_EQ(spiralOrder(tmp), nums);
    }
    {
        nums = {1, 2, 4, 6, 5, 3};
        vector<vector<int>> tmp = {{1, 2}, {3, 4}, {5, 6}};
        EXPECT_EQ(spiralOrder(tmp), nums);
    }

    {
        nums = {1, 2, 3};
        vector<vector<int>> tmp = {{1}, {2}, {3}};
        EXPECT_EQ(spiralOrder(tmp), nums);
    }
}

TEST(sort, basic){
#define COMM_SORT(arr) \
    {                  \
        vector<int> vec1 = arr; \
        vector<int> vec2 = arr; \
        heapSort(vec1);      \
        std::stable_sort(vec2.begin(), vec2.end());\
        EXPECT_EQ(vec1, vec2);  \
    }

    COMM_SORT(vector<int>({5, 2, 3, 4, 1}))
    COMM_SORT(vector<int>({6, 2, 3, 2, 1}))
    COMM_SORT(vector<int>({6, 2, 3, 2, 3}))
    COMM_SORT(vector<int>({6, 2, 3, 2, 3, 2, 3, 6, 1, 2, 3}))
}

TEST(compress, basic){
    int cnt = 0;
    vector<char> vec, tmp;

    vec = {'a'};
    tmp = {'a'};
    cnt = compress(vec);
    EXPECT_EQ(cnt, 1);
    vec.resize(tmp.size());
    EXPECT_EQ(vec, tmp);

    vec = {'a', 'a'};
    tmp = {'a', '2'};
    cnt = compress(vec);
    EXPECT_EQ(cnt, 2);
    vec.resize(tmp.size());
    EXPECT_EQ(vec, tmp);

    vec = {'a', 'a', 'a'};
    tmp = {'a', '3'};
    cnt = compress(vec);
    EXPECT_EQ(cnt, 2);
    vec.resize(tmp.size());
    EXPECT_EQ(vec, tmp);

    vec = {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'};
    tmp = {'a', '1', '2'};
    cnt = compress(vec);
    EXPECT_EQ(cnt, 3);
    vec.resize(tmp.size());
    EXPECT_EQ(vec, tmp);

    vec = {'a', 'a', 'a', 'b'};
    tmp = {'a', '3', 'b'};
    cnt = compress(vec);
    EXPECT_EQ(cnt, 3);
    vec.resize(tmp.size());
    EXPECT_EQ(vec, tmp);

    vec = {'a', 'a', 'a', 'b', 'c'};
    tmp = {'a', '3', 'b', 'c'};
    cnt = compress(vec);
    EXPECT_EQ(cnt, 4);
    vec.resize(tmp.size());
    EXPECT_EQ(vec, tmp);
}

TEST(compressString, basic){
    string res;

    res = compressString("");
    EXPECT_EQ(res, "");

    res = compressString("a");
    EXPECT_EQ(res, "a");

    res = compressString("aa");
    EXPECT_EQ(res, "aa");

    res = compressString("aaa");
    EXPECT_EQ(res, "a3");

    res = compressString("aaab");
    EXPECT_EQ(res, "aaab");

    res = compressString("aaabb");
    EXPECT_EQ(res, "a3b2");

    res = compressString("aaaebbccc");
    EXPECT_EQ(res, "a3e1b2c3");

    res = compressString("aaaaaaaaaaaa");
    EXPECT_EQ(res, "a12");
}

TEST(reverseOnlyLetters, basic){
    string sResult;

    sResult = reverseOnlyLetters("abcd");
    EXPECT_EQ(sResult, "dcba");

    sResult = reverseOnlyLetters("abc");
    EXPECT_EQ(sResult, "cba");

    sResult = reverseOnlyLetters("abc----d");
    EXPECT_EQ(sResult, "dcb----a");

    sResult = reverseOnlyLetters("ab-cd");
    EXPECT_EQ(sResult, "dc-ba");

    sResult = reverseOnlyLetters("a-bC-dEf-ghIj");
    EXPECT_EQ(sResult, "j-Ih-gfE-dCba");

    sResult = reverseOnlyLetters("Test1ng-Leet=code-Q!");
    EXPECT_EQ(sResult, "Qedo1ct-eeLg=ntse-T!");

}

TEST(sortedSquares, basic){
    vector<int> nums, out, ret;
    {
        nums = {1, 2, 3};
        out = sortedSquares(nums);
        ret = {1, 4, 9};
        EXPECT_EQ(out, ret);
    }

    {
        nums = {-3, -2, -1};
        out = sortedSquares(nums);
        ret = {1, 4, 9};
        EXPECT_EQ(out, ret);
    }

    {
        nums = {-2, 0, 1};
        out = sortedSquares(nums);
        ret = {0, 1, 4};
        EXPECT_EQ(out, ret);
    }

    {
        nums = {-5, -2, 0, 1, 3};
        out = sortedSquares(nums);
        ret = {0, 1, 4, 9, 25};
        EXPECT_EQ(out, ret);
    }
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

    {
        nums = {-2, 1, 0, 1, 2};
        vector<vector<int>> tmp = {{-2, 0, 2}, {-2, 1, 1}};
        EXPECT_EQ(threeSum(nums), tmp);
    }
}

TEST(mergeSortArr, basic){
    vector<int> nums1, nums2, vec;
    {
        nums1 = {1, 3, 5, 0, 0, 0};
        nums2 = {2, 2, 6};
        mergeSortArr(nums1, 3, nums2, 3);
        vec = {1, 2, 2, 3, 5, 6};
        EXPECT_EQ(nums1, vec);
    }

    {
        nums1 = {1, 3, 5, 0, 0, 0};
        nums2 = {2, 4, 6};
        mergeSortArr(nums1, 3, nums2, 3);
        vec = {1, 2, 3, 4, 5, 6};
        EXPECT_EQ(nums1, vec);
    }

    {
        nums1 = {1, 1, 0, 0};
        nums2 = {2, 2};
        mergeSortArr(nums1, 2, nums2, 2);
        vec = {1, 1, 2, 2};
        EXPECT_EQ(nums1, vec);
    }

    {
        nums1 = {1, 0};
        nums2 = {2};
        mergeSortArr(nums1, 1, nums2, 1);
        vec = {1, 2};
        EXPECT_EQ(nums1, vec);
    }

    {
        nums1 = {2, 0};
        nums2 = {1};
        mergeSortArr(nums1, 1, nums2, 1);
        vec = {1, 2};
        EXPECT_EQ(nums1, vec);
    }

    {
        nums1 = {1, 0};
        nums2 = {1};
        mergeSortArr(nums1, 1, nums2, 1);
        vec = {1, 1};
        EXPECT_EQ(nums1, vec);
    }
}