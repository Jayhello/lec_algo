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

void preOrder(TreeNode* root);

void midOrder(TreeNode* root);

void postOrder(TreeNode* root);

vector<vector<int>> levelOrder(TreeNode* root);

vector<vector<int>> zigzagLevelOrder(TreeNode* root);

//https://leetcode.cn/problems/binary-tree-right-side-view/description/
vector<int> rightSideView(TreeNode* root);

bool isSameTree(TreeNode* p, TreeNode* q);

//https://leetcode.cn/problems/balanced-binary-tree/description/
bool isBalanced(TreeNode* root);

//https://leetcode.cn/problems/maximum-depth-of-binary-tree/description/
int maxDepth(TreeNode* root);

//https://leetcode.cn/problems/minimum-depth-of-binary-tree/description/
int minDepth(TreeNode* root);

//https://leetcode.cn/problems/validate-binary-search-tree/description/
bool isValidBST(TreeNode* root);

//https://leetcode.cn/problems/invert-binary-tree/
TreeNode* invertTree(TreeNode* root);

//https://leetcode.cn/problems/symmetric-tree/
bool isSymmetric(TreeNode* root);

//https://leetcode.cn/problems/merge-two-binary-trees/description/
TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2);

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

string serialize(TreeNode* root);

TreeNode* deserialize(string data);

struct MultiNode{
    int val;
    vector<MultiNode*> children;
    MultiNode(int _val) {
        val = _val;
    }
    MultiNode(int _val, vector<MultiNode*> _children) {
        val = _val;
        children = _children;
    }
};

//https://leetcode.cn/problems/n-ary-tree-postorder-traversal/description/
vector<int> postorder(MultiNode* root);

vector<vector<int>> verticalOrder(TreeNode* root);

//https://leetcode.cn/problems/shu-de-zi-jie-gou-lcof/
bool isSubStructure(TreeNode* root1, TreeNode* root2);

vector<TreeNode*> findDuplicateSubtrees(TreeNode* root);

//https://leetcode.cn/problems/construct-string-from-binary-tree/description/
string tree2str(TreeNode* root);

//https://leetcode.cn/problems/cousins-in-binary-tree/description/
bool isCousins(TreeNode* root, int x, int y);

//https://leetcode.cn/problems/path-sum/
bool hasPathSum(TreeNode* root, int targetSum);

// https://leetcode.cn/problems/path-sum-ii/
vector<vector<int>> pathSum(TreeNode* root, int targetSum);

//https://leetcode.cn/problems/path-sum-iii/
int pathSum437(TreeNode* root, int targetSum);

//https://leetcode.cn/problems/sum-root-to-leaf-numbers/
int sumNumbers(TreeNode* root);

//https://leetcode.cn/problems/smallest-string-starting-from-leaf/description/
string smallestFromLeaf(TreeNode* root);

//https://leetcode.cn/problems/diameter-of-binary-tree/
int diameterOfBinaryTree(TreeNode* root);

//https://leetcode.cn/problems/binary-tree-paths
vector<string> binaryTreePaths(TreeNode* root);

//https://leetcode.cn/problems/maximum-difference-between-node-and-ancestor
int maxAncestorDiff(TreeNode* root);

//https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);

//https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree
TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q);

//https://leetcode.cn/problems/kth-smallest-element-in-a-bst/
int kthSmallest(TreeNode* root, int k);

//https://leetcode.cn/problems/minimum-distance-between-bst-nodes/
int minDiffInBST(TreeNode* root);

// https://leetcode.cn/problems/validate-binary-search-tree
bool isValidBST1(TreeNode* root);

namespace v2{

string serialize(TreeNode* root);

TreeNode* deserialize(string data);

} // v2
