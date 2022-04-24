class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() <=2){return {};}
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int a, b, c;
        for(int i=0;i<nums.size();i++){
            if((i > 0) && (nums[i]== nums[i-1])){
                continue;
            }
            b = i+1;
            c = nums.size() - 1;
            while(b < c) {
                int s = nums[i] + nums[b] + nums[c];
                if(s > 0){
                    c--;
                } else if(s < 0){
                    b++;
                } else {
                    ans.push_back({nums[i], nums[b], nums[c]});
                    while(b<c and nums[b] == nums[b+1]) {b++;}
                    while(b<c and nums[c] == nums[c-1]) {c--;}
                    b++;
                    c--;
                }
            }
        }
        return ans;
    }
};