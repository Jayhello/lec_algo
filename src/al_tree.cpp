//
// Created by wenwen on 2023/2/13.
//

#include "al_tree.h"

vector<vector<int>> levelOrder(TreeNode* root){

}

bool isSameTree(TreeNode* p, TreeNode* q){
    if(!p and !q)return true;
    if(!p or !q)return false;
    if(p->val != q->val)return false;

    return isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
}