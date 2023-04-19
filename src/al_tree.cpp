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

bool isCousins(TreeNode* root, int x, int y){
    if(!root)return false;

    std::queue<TreeNode*> que;
    que.push(root);
    int ix = -1, iy = -1;
    while(not que.empty()){
        int len = que.size();
        for(int i = 0; i < len; ++i){
            root = que.front();
            que.pop();
            if(!root)continue;
            if(root->val == x)ix = i;
            if(root->val == y)iy = i;

            que.push(root->left);
            que.push(root->right);
        }

        if(-1 == ix and -1 == iy)continue;
        if(-1 == ix or -1 == iy)return false;

        return ix / 2 != iy / 2;
    }

    return false;
}

void helper993(TreeNode* root, TreeNode* parent, int depth, int x, int y, int& xDepth, int& yDepth,
               TreeNode*& xParent, TreeNode*& yParent){
    if(!root or (xDepth >=0 and yDepth >= 0))return;
    if(root->val == x){
        xParent = parent;
        xDepth = depth;
    }
    if(root->val == y){
        yParent = parent;
        yDepth = depth;
    }
    helper993(root->left, root, depth + 1, x, y, xDepth, yDepth, xParent, yParent);
    helper993(root->right, root, depth + 1, x, y, xDepth, yDepth, xParent, yParent);
}

bool isCousins2(TreeNode* root, int x, int y){
    TreeNode* parent = nullptr, *xParent = nullptr, *yParent = nullptr;
    int depth = 0, xDepth = -1, yDepth = -1;
    helper993(root, parent, depth, x, y, xDepth, yDepth, xParent, yParent);

    return xDepth == yDepth and xParent != yParent;
}

class CBTInserter {
public:
    CBTInserter(TreeNode* root):root_(root) {
        init(root_);
    }

    int insert(int val) {
        int depth = vLevel_.size();

        int num = vLevel_[depth - 1].size();
        int iMax = std::pow(2, depth - 1);
        TreeNode* parent = nullptr;
        bool isLeft = true;
        if(num >= iMax){
            parent = vLevel_[depth - 1][0];
            parent->left = new TreeNode(val);
            vLevel_.push_back({parent->left});
            return parent->val;
        }

        parent = vLevel_[depth - 2][num / 2];
        isLeft = not (num % 2);

        if(isLeft){
            parent->left = new TreeNode(val);
            vLevel_[depth - 1].push_back(parent->left);
        }else{
            parent->right = new TreeNode(val);
            vLevel_[depth - 1].push_back(parent->right);
        }

        return parent->val;
    }

    TreeNode* get_root() {
        return root_;
    }

    void init(TreeNode* root){
        if(!root)return;
        vLevel_.push_back({root});

        while(true){
            auto& level = vLevel_.back();
            int len = level.size();
            vector<TreeNode*> tmpLevel;
            for(int i = 0; i < len; ++i){
                if(level[i]->left)tmpLevel.push_back(level[i]->left);
                if(level[i]->right)tmpLevel.push_back(level[i]->right);
                if(!level[i]->left or !level[i]->right) break;
            }

            if(tmpLevel.empty())return;
            vLevel_.push_back(std::move(tmpLevel));
        }
    }

    TreeNode*              	  root_;
    vector<vector<TreeNode*>> vLevel_;
};

void helper112(TreeNode* root, int targetSum, int curSum, bool& found){
    if(!root or found){
        return;
    }

    curSum += root->val;
    if(!root->left and !root->right and curSum == targetSum){
        found = true;
        return;
    }

    helper112(root->left, targetSum, curSum, found);
    helper112(root->right, targetSum, curSum, found);
}


bool hasPathSum(TreeNode* root, int targetSum){
    if(!root) return false;
    bool found = false;
    helper112(root, targetSum, 0, found);
    return found;
}

void helper113(TreeNode* root, int targetSum, int curSum, vector<int>& path, vector<vector<int>>& res){
    if(!root)return;

    curSum += root->val;
    path.push_back(root->val);
    if(curSum == targetSum and !root->left and !root->right){
        res.push_back(path);
    }

    helper113(root->left, targetSum, curSum, path, res);
    helper113(root->right, targetSum, curSum, path, res);
    path.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum){
    vector<vector<int>> res;
    vector<int> path;
    helper113(root, targetSum, 0, path, res);
    return res;
}

int helper437(TreeNode* root, int targetSum, int curSum){
    if(!root) return 0;
    curSum += root->val;
    int ret = (curSum == targetSum ? 1 : 0);
    return ret + helper437(root->left, targetSum, curSum)
           + helper437(root->right, targetSum, curSum);
}

int pathSum437(TreeNode* root, int targetSum){
    if(!root) return 0;
    return helper437(root, targetSum, 0)
           + pathSum437(root->left, targetSum)
           + pathSum437(root->right, targetSum);
}

void helper129(TreeNode* root, int cur, int& sum){
    if(!root)return;
    cur = 10 * cur + root->val;
    if(!root->left and !root->right){
        sum += cur;
        return;
    }

    helper129(root->left, cur, sum);
    helper129(root->right, cur, sum);
}

int sumNumbers(TreeNode* root){
    int sum = 0;
    helper129(root, 0, sum);
    return sum;
}

void helper988(TreeNode* root, string& path, string& res){
    if(!root)return;
    path.push_back(root->val + 'a');
    if(!root->left and !root->right){
        string tmp(path.rbegin(), path.rend());
        if(res.empty()){
            res = tmp;
        }else{
            if(res > tmp){
                res = tmp;
            }
        }
    }

    helper988(root->left, path, res);
    helper988(root->right, path, res);
    path.pop_back();
}

string smallestFromLeaf(TreeNode* root){
    string path, res;
    helper988(root, path, res);
    return res;
}

namespace r543{

int helper543(TreeNode* root){
    if(!root) return 0;
    return 1 + std::max(helper543(root->left), helper543(root->right));
}
int diameterOfBinaryTree(TreeNode* root){
    return helper543(root->left) + helper543(root->right);
}

int helper5431(TreeNode* root){
    if(!root) return 0;
    return 1 + std::max(helper543(root->left), helper543(root->right));
}
int diameterOfBinaryTree1(TreeNode* root){
    if(!root)return 0;
    int rootDia = helper543(root->left) + helper543(root->right);
    int leftDia = diameterOfBinaryTree1(root->left);
    int rightDia = diameterOfBinaryTree1(root->right);
    return std::max(rootDia, std::max(leftDia, rightDia));
}

} // r543


class R543{
public:
int max_ = 0;
int helper543(TreeNode* root){
    if(!root) return 0;
    int lh = helper543(root->left);
    int rh = helper543(root->right);
    max_ = std::max(max_, lh + rh);

    return 1 + std::max(lh, rh);
}

int diameterOfBinaryTree(TreeNode* root){
    if(!root)return 0;

    int left = helper543(root->left);
    int right = helper543(root->right);
    max_ = std::max(max_, left + right);
    return max_;
}
};

class Solution124 {
public:
    int res_ = INT_MIN;
    int helper124(TreeNode* root, int sum){
        if(!root)return 0;
        if(sum < 0){
            res_ = std::max(res_, sum);
            return sum;
        }

        sum += root->val;
        int left = helper124(root->left, sum);
        int right = helper124(root->right, sum);

        res_ = std::max(res_, left + right);
        return left + right;
    }
    int maxPathSum(TreeNode* root) {
        if(!root) return res_;
        helper124(root, 0);
        maxPathSum(root->left);
        maxPathSum(root->right);
        return res_;
    }
};

void helper257(TreeNode* root, string path, vector<string>& res){
    if(!root)return;

    path += std::to_string(root->val);
    if(root->left or root->right){
        path += "->";
    }

    if(!root->left and !root->right){
        res.push_back(path);
    }

    helper257(root->left, path, res);
    helper257(root->right, path, res);
}

vector<string> binaryTreePaths(TreeNode* root){
    vector<string> res;
    helper257(root, "", res);
    return res;
}

class Solution1026 {
public:
int res_ = 0;
void helper1026(TreeNode* root, int val){
    if(!root) return;
    res_ = std::max(std::abs(root->val - val), res_);
    helper1026(root->left, val);
    helper1026(root->right, val);
}
int maxAncestorDiff(TreeNode* root) {
    if(!root) return res_;
    helper1026(root, root->val);
    maxAncestorDiff(root->left);
    maxAncestorDiff(root->right);
    return res_;
}

void helper1026(TreeNode* root, int iMin, int iMax){
    if(!root) return;
    int tmp = std::max(std::abs(iMin - root->val), std::abs(iMax - root->val));
    res_ = std::max(res_, tmp);
    iMin = std::min(iMin, root->val);
    iMax = std::max(iMax, root->val);
    helper1026(root->left, iMin, iMax);
    helper1026(root->right, iMin, iMax);
}

int maxAncestorDiff1(TreeNode* root){
    if(!root) return res_;
    helper1026(root, root->val, root->val);
    return res_;
}
};

bool helper235(TreeNode* root, TreeNode* p){
    if(!root) return false;
    if(root->val == p->val){
        return true;
    }else if(root->val > p->val){
        return helper235(root->left, p);
    }else{
        return helper235(root->right, p);
    }
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    if(p->val == root->val)return p;
    if(q->val == root->val)return q;

    bool pLeft = helper235(root->left, p);
    bool qRight = helper235(root->right, q);
    if(pLeft and qRight){
        return root;
    }

    bool pRight = helper235(root->right, p);
    bool qLeft = helper235(root->left, q);
    if(pRight and qLeft){
        return root;
    }

    if(pLeft and qLeft){
        return lowestCommonAncestor(root->left, p, q);
    }

    if(pRight and qRight){
        return lowestCommonAncestor(root->right, p, q);
    }
}

bool helper236(TreeNode* root, TreeNode* p){
    if(!root) return false;
    if(root->val == p->val){
        return true;
    }

    return helper236(root->left, p) or helper236(root->right, p);
}

TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q){
    if(p->val == root->val)return p;
    if(q->val == root->val)return q;

    bool pLeft = helper236(root->left, p);
    bool qRight = helper236(root->right, q);
    if(pLeft and qRight){
        return root;
    }

    bool pRight = helper236(root->right, p);
    bool qLeft = helper236(root->left, q);
    if(pRight and qLeft){
        return root;
    }

    if(pLeft and qLeft){
        return lowestCommonAncestor(root->left, p, q);
    }

    if(pRight and qRight){
        return lowestCommonAncestor(root->right, p, q);
    }
    return nullptr;
}

void helper236_2(TreeNode* root, TreeNode* p, bool& found, vector<TreeNode*>& path){
    if(!root) return;

    path.push_back(root);
    if(root == p){
        found = true;
        return;
    }

    if(not found) helper236_2(root->left, p, found, path);
    if(not found) helper236_2(root->right, p, found, path);
    if(not found) path.pop_back();
}

TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q){
    if(!root or !p or !q) return nullptr;
    bool foundP = false, foundQ = false;
    vector<TreeNode*> pathP, pathQ;
    helper236_2(root, p, foundP, pathP);
    if(not foundP) return nullptr;
    helper236_2(root, q, foundQ, pathQ);
    if(not foundQ) return nullptr;

    int i = 0;
    int len = std::min(pathP.size(), pathQ.size());
    for(; i < len; ++i){
        if(pathP[i] != pathQ[i]) break;
    }

    return pathP[i - 1];
}

void helper230(TreeNode* root, int& k, TreeNode*& p){
    if(!root or k <= 0)return;

    helper230(root->left, k, p);
    if(k <= 0) return;

    if(--k == 0){
        p = root;
        return;
    }

    helper230(root->right, k, p);
}

int kthSmallest(TreeNode* root, int k){
    TreeNode* p = nullptr;
    helper230(root, k, p);
    return p->val;
}

void helper783(TreeNode* root, TreeNode*& prev, int& iMin){
    if(!root)return;

    helper783(root->left, prev, iMin);
    if(!prev){
        prev = root;
    }else{
        iMin = std::min(iMin, std::abs(root->val - prev->val));
        prev = root;
    }
    helper783(root->right, prev, iMin);
}

int minDiffInBST(TreeNode* root){
    int iMin = INT_MAX;
    TreeNode* prev = nullptr;
    helper783(root, prev, iMin);
    return iMin;
}

void helper98(TreeNode* root, TreeNode*& prev, bool& bValid){
    if(!root or not bValid) return;
    helper98(root->left, prev, bValid);
    if(prev){
        if(prev->val > root->val){
            bValid = false;
            return;
        }
    }

    prev = root;
    helper98(root->right, prev, bValid);
}

bool isValidBST1(TreeNode* root){
    TreeNode* prev = nullptr;
    bool bValid = true;
    helper98(root, prev, bValid);
    return bValid;
}

void helper99(TreeNode* root, vector<TreeNode*>& path){
    if(!root) return;
    helper99(root->left, path);
    path.push_back(root);
    helper99(root->right, path);
}

void recoverTree(TreeNode* root){
    vector<TreeNode*> path;
    helper99(root, path);

    TreeNode* x = nullptr, *y = nullptr;
    int len = path.size();
    for(int i = 0; i < len - 1; ++i){
        if(path[i]->val > path[i + 1]->val){
            if(!x) x = path[i];
            y = path[i + 1];
        }
    }

    std::swap(x->val, y ->val);
}


void helper501(TreeNode* root, int& iMaxCnt, int& iCnt, TreeNode*& prev, vector<int>& res){
    if(!root) return;
    helper501(root->left, iMaxCnt, iCnt, prev, res);
    if(prev){
        if(root->val == prev->val){
            ++iCnt;
            if(iCnt > iMaxCnt)res.clear();
        }else{
            if(iCnt == iMaxCnt){
                res.push_back(prev->val);
            }else if(iCnt > iMaxCnt){
                res.clear();
                res.push_back(prev->val);
                iMaxCnt = iCnt;
            }
            iCnt = 1;
        }
    }

    prev = root;
    helper501(root->right, iMaxCnt, iCnt, prev, res);
}

vector<int> findMode(TreeNode* root){
    int iMaxCnt = 1, iCnt = 1;
    vector<int> res;
    TreeNode* prev = nullptr;
    helper501(root, iMaxCnt, iCnt, prev, res);
    if(iMaxCnt == iCnt){
        res.push_back(prev->val);
    }else if(iMaxCnt < iCnt){
        res.clear();
        res.push_back(prev->val);
    }

    return res;
}

void helper501(TreeNode* root, vector<TreeNode*>& path){
    if(!root) return;
    helper501(root->left, path);
    path.push_back(root);
    helper501(root->right, path);
}

vector<int> findMode1(TreeNode* root){
    vector<TreeNode*> path;
    helper501(root, path);

    if(1 == path.size()) return {path[0]->val};

    vector<int> res;
    int iMaxCnt = 1, iCnt = 1;
    int i = 1, len = path.size();
    TreeNode* prev = path[0];
    while(i < len){
        while(i < len and prev->val == path[i]->val){
            ++i;
            ++iCnt;
        }

        if(iCnt > iMaxCnt){
            res.clear();
            res.push_back(prev->val);
            iMaxCnt = iCnt;
        }else if(iCnt == iMaxCnt){
            res.push_back(prev->val);
        }

        if(i < len){
            prev = path[i];
            iCnt = 1;
            ++i;
        }
    }

    if(1 == iMaxCnt)res.push_back(path[len - 1]->val);

    return res;
}

TreeNode* insertIntoBST(TreeNode* root, int val){
    if(!root) return new TreeNode(val);

    if(root->val > val){
        root->left = insertIntoBST(root->left, val);
    }else{
        root->right = insertIntoBST(root->right, val);
    }

    return root;
}

bool helperO33(const vector<int>& nums, int left, int right){
    if(right - left <= 2) return true;

    int mid = left;
    while(mid < right and nums[mid] < nums[right]){
        ++mid;
    }

    for(int i = mid; i < right; ++i){
        if(nums[i] < nums[right]) return false;
    }

    bool res = helperO33(nums, left, mid - 1);
    if(not res) return false;

    res = helperO33(nums, mid, right - 1);
    if(not res) return false;

    return true;
}

bool verifyPostorder(vector<int>& postorder){
    int len = postorder.size();
    return helperO33(postorder, 0, len - 1);
}

TreeNode* helper105(const vector<int>& preorder, int preBeg, int preEnd,
                    const vector<int>& inorder, int inBeg, int inEnd){
    if(preEnd < preBeg or inBeg > inEnd or preEnd >= preorder.size()) return nullptr;
    TreeNode* root = new TreeNode(preorder[preBeg]);
    int cnt = 0;
    for(int i = inBeg; i <= inEnd; ++i){
        if(inorder[i] == preorder[preBeg])break;
        ++cnt;
    }

    root->left = helper105(preorder, preBeg + 1, preBeg + cnt, inorder, inBeg, inBeg + cnt - 1);
    root->right = helper105(preorder, preBeg + cnt + 1, preEnd, inorder, inBeg + cnt + 1, inEnd);
    return root;
}

TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder){
    int len = preorder.size();
    return helper105(preorder, 0, len - 1, inorder, 0, len - 1);
}

TreeNode* helper106(const vector<int>& inorder, int inBeg, int inEnd,
                    const vector<int>& postorder, int postBeg, int postEnd){
    if(inBeg > inEnd or postBeg > postEnd or inEnd >= inorder.size()) return nullptr;
    TreeNode* root = new TreeNode(postorder[postEnd]);
    int cnt = 0;
    for(int i = inBeg; i <= inEnd; ++i){
        if(inorder[i] == postorder[postEnd])break;
        ++cnt;
    }

    root->left = helper106(inorder, inBeg, inBeg + cnt - 1, postorder, postBeg, postBeg + cnt - 1);
    root->right = helper106(inorder, inBeg + cnt + 1, inEnd, postorder, postBeg + cnt , postEnd - 1);
    return root;
}

TreeNode* buildTree2(vector<int>& inorder, vector<int>& postorder){
    int len = inorder.size();
    return helper106(inorder, 0, len - 1, postorder, 0, len - 1);
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
