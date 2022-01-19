/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct hdpair {
    int h,d;
    
    hdpair(int h, int d){
        this->h = h;
        this->d = d;
    }
};

class Solution {
public:
    pair<int, bool> balance_helper(TreeNode* root) {
        pair<int, bool> p;
        if(!root) {
            p.first = 0;
            p.second = true;
            return p;
        }

        pair<int, bool> lp = balance_helper(root->left);
        pair<int, bool> rp = balance_helper(root->right);

        if(lp.second && rp.second && abs(lp.first - rp.first) <=1){
            return {max(lp.first, rp.first)+1, true};
        }
        return {max(lp.first, rp.first)+1, false};
    }
    
    bool isBalanced(TreeNode* root) {
        return balance_helper(root).second;
    }
};