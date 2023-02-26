//
// Created by wenwen on 2023/2/13.
//
#pragma once
#include "al_comm.h"

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> levelOrder(TreeNode* root);

vector<vector<int>> zigzagLevelOrder(TreeNode* root);

//https://leetcode.cn/problems/binary-tree-right-side-view/description/
vector<int> rightSideView(TreeNode* root);

bool isSameTree(TreeNode* p, TreeNode* q);

//https://leetcode.cn/problems/validate-binary-search-tree/description/
bool isValidBST(TreeNode* root);

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

//https://leetcode.cn/problems/populating-next-right-pointers-in-each-node/description/
// todo 常量的解法 https://leetcode.cn/problems/populating-next-right-pointers-in-each-node-ii/solutions/429992/bfsjie-jue-zui-hao-de-ji-bai-liao-100de-yong-hu-by/?orderBy=most_votes
Node* connect(Node* root);
