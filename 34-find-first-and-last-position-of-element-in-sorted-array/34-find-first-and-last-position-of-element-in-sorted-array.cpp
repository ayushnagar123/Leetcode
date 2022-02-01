class Solution {
public:
    int firstOccurance(vector<int> &arr, int val){
        int result = -1;
        if(arr.size()==0){
            return result;
        }
        int start = 0;
        int end = arr.size() - 1;
        int mid;
        while(start<=end){
            mid = start + (end- start)/2;
            if(arr[mid]==val){
                result = mid;
                end = mid - 1;
            }
            else if(arr[mid] <  val){
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return result;
    }

    int lastOccurance(vector<int> &arr, int val){
        int result = -1;
        if(arr.size()==0){
            return result;
        }
        int start = 0;
        int end = arr.size() - 1;
        int mid;
        while(start<=end){
            mid = start + (end- start)/2;
            if(arr[mid]==val){
                result = mid;
                start = mid + 1;
            }
            else if(arr[mid] <  val){
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return result;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int fo = firstOccurance(nums, target);
        int lo = lastOccurance(nums, target);
        vector<int> ans;
        ans.push_back(fo);
        ans.push_back(lo);
        return ans;
    }
};