class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> dp(nums.size(), false);
        dp[0] = true;
        for(int i=0;i<dp.size()-1;i++) {
            if(dp[i]) {
                for(int j=i+1;j<=i+nums[i] && j<dp.size(); j++) {
                    dp[j] = true;
                }
            }
            if(dp[nums.size()-1]){
                return true;
            }
        }
        return dp[nums.size()-1];
    }
};