class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        for(int i= 0 ;i<nums.size();i++){
            if(ans < nums[i]) {
                ans = nums[i];
            }
        }
        int currMax =1, currMin = 1;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                currMin = 1;
                currMax = 1;
            }
            int tmp = currMax * nums[i];
            currMax = max({nums[i]*currMax, nums[i] *currMin, nums[i]});
            currMin = min({tmp, nums[i]* currMin, nums[i]});
            ans = max(ans, currMax);
        }
        return ans;
    }
};