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
    vector<vector<int>> levelOrderTraversal(TreeNode* root){
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            vector<int> row;
            int n = q.size();
            for(int i=0;i<n;i++){
                row.push_back(q.front()->val);
                if(q.front()->left){
                    q.push(q.front()->left);
                }
                if(q.front()->right){
                    q.push(q.front()->right);
                }
                q.pop();
            }
            ans.push_back(row);
        }
        return ans;
    }
    
    int maxLevelSum(TreeNode* root) {
        auto rows = levelOrderTraversal(root);
        int max = INT_MIN;
        int i = 1;
        int ans;
        for(auto row: rows){
            int sum = 0;
            for(auto node: row){
                sum+=node;
            }
            if(max < sum){
                max = sum;
                ans = i;
            }
            i++;
        }
        return ans;
    }
};