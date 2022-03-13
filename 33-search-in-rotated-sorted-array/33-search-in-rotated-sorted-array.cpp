class Solution {
public:
    int countNumberOfRightRotations(vector<int>& arr) {
        int start = 0;
        int n = arr.size();
        int end = n - 1;
        int mid;
        while(start <= end){
            mid = start + (end - start)/2;
            if(arr[mid] < arr[(mid + n - 1)%n] && arr[mid] < arr[(mid+1)%n]){
                return mid;
            }
            if(arr[mid] > arr[end]){
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return 0;
    }
    
    int search(vector<int>& nums, int target) {
        int minValueIndex = countNumberOfRightRotations(nums);
        if(target == nums[minValueIndex]){
            return minValueIndex;
        }
        int start, end, mid;
        start = (target <= nums[nums.size() - 1]) ? minValueIndex : 0;
        end = (target > nums[nums.size() - 1]) ? minValueIndex : nums.size() - 1;
        while(start<=end){
            mid = start + (end - start)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[mid] >= target) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        return -1;
    }
};