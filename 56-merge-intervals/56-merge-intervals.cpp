class Solution {
public:
    static bool compare(const vector<int> &v1, const vector<int> &v2){
        if(v1[0] < v2[0]){
            return true;
        }
        if(v1[0] > v2[0]){
            return false;
        }
        if(v1[1] < v2[1]){
            return true;
        }
        return false;
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int ans_index = 0;
        sort(intervals.begin(), intervals.end(), compare);
        ans.push_back(intervals[0]);
        for(auto interval: intervals){
            if(ans[ans_index][1] >= interval[0]){
                ans[ans_index][1] = max(interval[1], ans[ans_index][1]);
            }
            else{
                ans_index++;
                ans.push_back(interval);
            }
        }
        return ans;
    }
};