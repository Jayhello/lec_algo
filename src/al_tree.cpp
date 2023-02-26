//
// Created by wenwen on 2023/2/13.
//

#include "al_tree.h"

vector<vector<int>> levelOrder(TreeNode* root){
    if(!root) return {};

    vector<vector<int>> res;
    std::queue<std::pair<TreeNode*, int>> que;
    que.push({root, 0});
    while(not que.empty()){
        auto tmp = que.front();
        que.pop();
        if(tmp.second >= res.size()){
            res.push_back({tmp.first->val});
        }else{
            res[tmp.second].push_back(tmp.first->val);
        }

        if(tmp.first->left){
            que.push({tmp.first->left, tmp.second + 1});
        }

        if(tmp.first->right){
            que.push({tmp.first->right, tmp.second + 1});
        }
    }
    return res;
}

vector<vector<int>> levelOrder_v2(TreeNode* root){
    if(!root) return {};

    vector<vector<int>> res;
    std::queue<TreeNode*> que;
    que.push(root);
    while(not que.empty()){
        int len = int(que.size());
        vector<int> vec;
        vec.reserve(len);
        for(int i = 0; i < len: ++i){
            auto p = que.front();
            que.pop();
            vec.push_back(p->val);

            if(p->left) que.push(p->left);
            if(p->right) que.push(p->right);
        }
        res.push_back(std::move(vec));
    }

    return res;
}

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if(nullptr == root) return {};

    std::queue<TreeNode*> que;
    que.push(root);
    vector<vector<int>> res;
    int level = 0;
    while(not que.empty()){
        int len = que.size();
        vector<int> vec;
        for(int i = 0; i < len; ++i){
            auto p = que.front();
            que.pop();
            if(p->left) que.push(p->left);
            if(p->right) que.push(p->right);
        }

        if(level % 2) std::reverse(vec.begin(), vec.end());
        res.push_back(std::move(vec));
    }

    return res;
}

vector<int> rightSideView(TreeNode* root){
    if(nullptr == root) return{};
    std::queue<TreeNode*> que;
    que.push(root);
    vector<int> res;
    while(not que.empty()){
        int len = que.size();
        for(int i = 0; i < len; ++i){
            auto p = que.front();
            que.pop();
            if(p->left)que.push(p->left);
            if(p->right)que.push(p->right);
            if(i == len - 1)res.push_back(p->val);
        }
    }
    return res;
}

bool isSameTree(TreeNode* p, TreeNode* q){
    if(!p and !q)return true;
    if(!p or !q)return false;
    if(p->val != q->val)return false;

    return isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
}

void traverse(TreeNode* root) {
    if (root == nullptr)return;   // 判断 base case
    // 访问两个相邻结点：左子结点、右子结点
    traverse(root->left);
    traverse(root->right);
}

Node* connect(Node* root){
    if(nullptr == root) return root;
    std::queue<Node*> que;
    que.push(root);
    while(not que.empty()){
        int len = que.size();
        Node* last = nullptr;
        for(int i = 0; i < len; ++i){
            auto p = que.front();
            que.pop();
            if(last) last->next = p;
            last = p;
            if(p->left) que.push(p->left);
            if(p->right) que.push(p->right);
        }
    }

    return root;
}

void validBSTHelper(TreeNode* root, TreeNode* &prev, bool& invalid){
    if(!root or invalid)return;

    validBSTHelper(root->left, prev, invalid);
    if(prev and prev->val >= root->val){
        invalid = true;
        return;
    }
    prev = root;
    validBSTHelper(root->right, prev, invalid);
}

bool isValidBST(TreeNode* root){
    TreeNode* prev = nullptr;
    bool invalid = false;
    validBSTHelper(root, prev, invalid);
    return invalid;
}

