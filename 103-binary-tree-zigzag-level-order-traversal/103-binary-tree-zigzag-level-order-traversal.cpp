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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        int i=0;
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
            if(i%2!=0){
                stack<int> s;
                for(auto e: row){
                    s.push(e);
                }
                row = {};
                while(!s.empty()){
                    row.push_back(s.top());
                    s.pop();
                }
            }
            ans.push_back(row);
            i++;
        }
        return ans;
    }
};