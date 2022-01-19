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
    int height(TreeNode* root){
        if(!root) {
            return 0;
        }
        return max(height(root->left), height(root->right))+1;
    }
    
    void levelOrderHelper(TreeNode* root, int level, vector<vector<int>> &ans) {
        if(root== NULL) return;
        ans[level].push_back(root->val);
        levelOrderHelper(root->left, level-1, ans);
        levelOrderHelper(root->right, level-1, ans);
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int h = height(root);
        vector<vector<int>> ans(h, vector<int> {});
        levelOrderHelper(root, h-1, ans);
        return ans;
    }
};