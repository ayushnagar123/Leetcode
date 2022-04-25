class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        int i = 0, j = 0;
        int n = nums.size();
        vector<int> ans;
        ans.push_back(nums[0]);
        
        while(j<n){
            if(j<k){
                while(!q.empty() && q.back() < nums[j]){
                    q.pop_back();
                }
                q.push_back(nums[j]);
                ans[0] = q.front();
            }
            else{
                while(!q.empty() && q.back() < nums[j]){
                    q.pop_back();
                }
                q.push_back(nums[j]);
                if(q.front() == nums[i]){
                    q.pop_front();
                }
                ans.push_back(q.front());
                i++;
            }
            j++;
        }
        return ans;
    }
};