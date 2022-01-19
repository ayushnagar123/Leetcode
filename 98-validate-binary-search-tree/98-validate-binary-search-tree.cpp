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
    TreeNode* minValueNode(TreeNode* root){
        if(root==NULL){
            return NULL;
        }
        if(root->left!= NULL){
            return minValueNode(root->left);
        }
        return root;
    }

    TreeNode* maxValueNode(TreeNode* root){
        if(root==NULL){
            return NULL;
        }
        if(root->right!= NULL){
            return maxValueNode(root->right);
        }
        return root;
    }
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        bool leftValid = isValidBST(root->left);
        bool rightValid = isValidBST(root->right);
        if(!leftValid || !rightValid) return false;
        TreeNode* min = maxValueNode(root->left);
        TreeNode* max = minValueNode(root->right);
        if(min!=NULL && root->val <= min->val) return false;
        if(max!=NULL && root->val >= max->val) return false;
        return true;
    }
};