class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0; int r = nums.size() -1;
        int mid;
        int ans = nums[0];
        while(l<=r){
            if(nums[l] < nums[r]){
                ans = min(ans, nums[l]);
                break;
            }
            mid = l + (r - l)/2;
            ans = min(ans, nums[mid]);
            if(nums[mid] >= nums[l]) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return ans;
    }
};