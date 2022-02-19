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
class Solution {
public:
    int helper(TreeNode* root, int* res){
        if(!root){return 0;}

        int lpathsum = max(helper(root->left, res), 0);
        int rpathsum = max(helper(root->right, res), 0);

        int temp = max({lpathsum, rpathsum, 0});
        *res = max({*res, lpathsum + rpathsum + root->val});
        return temp + root->val;
    }
    
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        helper(root, &res);
        return res;
    }
};