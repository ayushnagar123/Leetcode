class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        vector<int> ans;
        int i = 0;
        for (auto num : nums){
            if(m.find(target - num)!=m.end()){
                ans.push_back(m[target - num]);
                ans.push_back(i);
                break;
            }
            else {
                m[num] = i;
            }
            i++;
        }
        return ans;
    }
};

// Runtime: 12 ms, faster than 77.71% of C++ online submissions for Two Sum.
// Memory Usage: 11.2 MB, less than 22.66% of C++ online submissions for Two Sum.