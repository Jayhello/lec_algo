//
// Created by wenwen on 2022/5/20.
//

#include <iostream>
#include <gtest/gtest.h>
#include "src/al_list.h"
#include "test_comm.h"

int main(int argc, char** argv) {

    ListNode* res = oddEvenList(createList({1, 2, 3}));
    printListFront(res);

    res = oddEvenList(createList({1, 2, 3, 4}));
    printListFront(res);

    res = oddEvenList(createList({1, 2, 3, 4, 5}));
    printListFront(res);

    return 0;
}
