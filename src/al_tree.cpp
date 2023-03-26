//
// Created by wenwen on 2023/2/13.
//

#include <climits>
#include "al_tree.h"

void preOrder(TreeNode* root){
    if(nullptr == root)return;
//    cout << root->val << endl;

    preOrder(root->left);
    preOrder(root->right);
}

void midOrder(TreeNode* root){
    if(nullptr == root) return;
    midOrder(root->left);
//    cout << root->val;
    midOrder(root->right);
}

void postOrder(TreeNode* root){
    if(nullptr == root) return;
    midOrder(root->left);
    midOrder(root->right);
//    cout << root->val;
}


void preOrder1(TreeNode* p){

}

vector<int> postOrder1(TreeNode* root){
    if(nullptr == root)return {};

    vector<int> res;
    stack<TreeNode*> sta;
    sta.push(root);
    TreeNode* prev = nullptr;
    while(not sta.empty()){
        root = sta.top();
        if((!root->left and !root->right) or
            (prev and (root->left == prev or root->right == prev))){
            res.push_back(root->val);
            prev = root;
            sta.pop();
            continue;
        }

        if(root->right) sta.push(root->right);
        if(root->left) sta.push(root->left);
    }
    return res;
}

bool isChild(MultiNode* root, MultiNode* p){
    auto it = std::find(root->children.begin(), root->children.end(), p);
    return it != root->children.end();
}

vector<int> postorder(MultiNode* root){
    if(nullptr == root) return {};

    vector<int> res;
    MultiNode* prev = nullptr;
    std::stack<MultiNode*> sta;
    sta.push(root);
    while(not sta.empty()){
        auto tmp = sta.top();
        if(tmp->children.empty() or (prev and isChild(tmp, prev))){
            res.push_back(tmp->val);
            sta.pop();
            prev = tmp;
            continue;
        }

        for(auto it = tmp->children.rbegin(); it != tmp->children.rend(); ++it){
            sta.push(*it);
        }
    }
    return res;
}

typedef std::pair<TreeNode*, int> ColumnContext;

vector<vector<int>> verticalOrder(TreeNode* root){
    if(!root) return {};

    std::map<int, vector<int>> m_col_vec;
    vector<vector<int>> vec_vec;

    queue<ColumnContext> que;
    que.push(std::make_pair(root, 0));

    while(not que.empty()){
        const auto& tmp = que.front();
        que.pop();
        m_col_vec[tmp.second].push_back(tmp.first->val);

        if(tmp.first->left){ // 左节点索引  -1
            que.push(std::make_pair(tmp.first->left, tmp.second - 1));
        }

        if(tmp.first->right){  // 右节点索引  +1
            que.push(std::make_pair(tmp.first->right, tmp.second + 1));
        }
    }

    for(auto& item : m_col_vec){
        vec_vec.emplace_back(std::move(item.second));
    }

    return vec_vec;
}

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
        for(int i = 0; i < len; ++i){
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

string serialize(TreeNode* root) {
    if(nullptr == root){
        return "x";
    }

    string sRoot = std::to_string(root->val);
    string sLeft = serialize(root->left);
    string sRight = serialize(root->right);
    return sRoot + " " + sLeft + " " + sRight;
}

void split(const string& str, char ch, vector<string>& vec){
    string tmp;
    for(auto c : str){
        if(c != ch){
            tmp.push_back(c);
        }else{
            vec.push_back(tmp);
            tmp.clear();
        }
    }
    if(not tmp.empty())vec.push_back(tmp);
}

TreeNode* buildTree(const vector<string>& vec, int& idx){
    if("x" == vec[idx]){
        return nullptr;
    }

    auto root = new TreeNode(std::stoi(vec[idx]));
    root->left = buildTree(vec, ++idx);
    root->right = buildTree(vec, ++idx);
    return root;
}
// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    if(data.empty() or data == "x") return nullptr;
    vector<string> vec;
    split(data, ' ', vec);

    int idx = 0;
    return buildTree(vec, idx);
}


bool helper26(TreeNode* root1, TreeNode* root2){
    if(!root2)return true;
    if(!root1)return false;
    if(root1->val != root2->val) return false;
    return helper26(root1->left, root2->left) and
           helper26(root1->right, root2->right);
}
bool isSubStructure(TreeNode* root1, TreeNode* root2) {
    if(!root1 or !root2) return false;
    return helper26(root1, root2) or
           isSubStructure(root1->left, root2) or
           isSubStructure(root1->right, root2);
}

int getTreeHeight(TreeNode* root){
    if(!root) return 0;
    return std::max(getTreeHeight(root->left), getTreeHeight(root->right)) + 1;
}

bool isBalanced(TreeNode* root){
    if(!root) return true;
    int l = getTreeHeight(root->left);
    int r = getTreeHeight(root->right);
    if(std::abs(l - r) > 1) return false;
    return isBalanced(root->left) and isBalanced(root->right);
}

int maxDepth(TreeNode* root){
    if(nullptr == root) return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return std::max(left, right) + 1;
}

int minDepth(TreeNode* root){
    if(nullptr == root) 	return 0;
    std::queue<TreeNode*> que;
    que.push(root);
    int height = 1;
    while(not que.empty()){
        int len = que.size();

        for(int i = 0; i < len; ++i){
            root = que.front();
            que.pop();
            if(!root->left and !root->right)return height;
            if(root->left) que.push(root->left);
            if(root->right) que.push(root->right);
        }
        ++height;
    }

    return height;
}

void helper111(TreeNode* root, int cur, int& res){
    if(!root)return;
    if(!root->left and !root->right){
        res = std::min(res, cur);
        return;
    }
    helper111(root->left, cur + 1, res);
    helper111(root->right, cur + 1, res);
}

int minDepth2(TreeNode* root){
    if(!root) return 0;
    int res = INT_MAX;
    helper111(root, 1, res);
    return res;
}

TreeNode* invertTree(TreeNode* root){
    if(!root) return root;
    invertTree(root->left);
    invertTree(root->right);
    std::swap(root->left, root->right);
    return root;
}

bool helper101(TreeNode* left, TreeNode* right){
    if(!left and !right) return true;
    if(!left or !right or left->val != right->val) return false;
    return helper101(left->left, right->right) and
           helper101(left->right, right->left);
}

bool isSymmetric(TreeNode* root){
    if(!root)return true;
    return helper101(root->left, root->right);
}

bool isSymmetric2(TreeNode* root){
    if(!root) return true;
    std::deque<TreeNode*> que;
    que.push_back(root);

    while(not que.empty()){
        int len = que.size();
        for(int i = 0; i < len; ++i){
            auto tmp = que.front();
            que.pop_front();
            if(!tmp)continue;

            que.push_back(tmp->left);
            que.push_back(tmp->right);
        }

        std::deque<TreeNode*> tmpQue(que.rbegin(), que.rend());
        auto it = que.begin();
        auto it2 = tmpQue.begin();
        for(;it != que.end(); ++it, ++it2){
            if(!(*it) and !(*it2))continue;
            if(!(*it) or !(*it2))return false;
            if((*it)->val != (*it2)->val)return false;
        }
    }

    return true;
}

TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2){
    if(!root1) return root2;
    if(!root2) return root1;

    root1->val += root2->val;;
    root1->left = mergeTrees(root1->left, root2->left);
    root1->right = mergeTrees(root1->right, root2->right);
    return root1;
}

string helper652(TreeNode* root, unordered_map<string, int>& mPathCount, vector<TreeNode*>& res){
    if(!root) return "";
    string str = std::to_string(root->val) + " " + helper652(root->left, mPathCount, res) + " " + helper652(root->right, mPathCount, res);
    ++mPathCount[str];
    if(2 == mPathCount[str]){
        res.push_back(root);
    }
    return str;
}

vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    vector<TreeNode*>res;
    unordered_map<string, int> mPathCount;
    helper652(root, mPathCount, res);
    return res;
}

string tree2str(TreeNode* root){
    if(!root) return "";

    string str = to_string(root->val);
    if(!root->left and !root->right){
        return str;
    }
    else if(root->left and root->right){
        return str + "(" + tree2str(root->left) + ")" + "(" + tree2str(root->right) + ")";
    }else if(!root->right){
        return str + "(" + tree2str(root->left) + ")";
    }else{
        return str + "()(" + tree2str(root->right) + ")";
    }
}

namespace v2{

string serialize(TreeNode* root) {
    if(nullptr == root){
        return "x";
    }

    string res;
    std::queue<TreeNode*> que;
    que.push(root);
    while(not que.empty()){
        auto tmp = que.front();
        que.pop();

        res += (nullptr == tmp ? "x" : std::to_string(tmp->val));
        res += ' ';
        if(nullptr == tmp){
            continue;
        }

        que.push(tmp->left);
        que.push(tmp->right);
    }

    res.erase(res.end() - 1);
    return res;
}

void split(const string& str, char ch, vector<string>& vec){
    string tmp;
    for(auto c : str){
        if(c != ch){
            tmp.push_back(c);
        }else{
            vec.push_back(tmp);
            tmp.clear();
        }
    }
    if(not tmp.empty())vec.push_back(tmp);
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    if(data.empty() or data == "x") return nullptr;

    vector<string> vec;
    split(data, ' ', vec);

    TreeNode* root = new TreeNode(std::stoi(vec[0]));
    std::queue<TreeNode*> que;
    que.push(root);
    int i = 1;

    while(not que.empty()){
        auto tmp = que.front();
        que.pop();
        if(vec[i] != "x"){
            tmp->left = new TreeNode(std::stoi(vec[i]));
            que.push(tmp->left);
        }
        ++i;

        if(vec[i] != "x"){
            tmp->right = new TreeNode(std::stoi(vec[i]));
            que.push(tmp->right);
        }
        ++i;
    }
    return root;
}

} // v2
