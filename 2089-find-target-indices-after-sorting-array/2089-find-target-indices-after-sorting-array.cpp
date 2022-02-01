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
    
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int first_occurance = firstOccurance(nums, target);
        if(first_occurance==-1) return ans;
        int last_occurance = lastOccurance(nums, target);
        for(int i=first_occurance; i<=last_occurance; i++){
            ans.push_back(i);
        }
        return ans;
    }
};