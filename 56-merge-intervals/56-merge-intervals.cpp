class Solution {
public:
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(long long i=1;i<intervals.size();i++) {
            cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
            if(ans[ans.size() - 1][1] >= intervals[i][0]) {
                ans[ans.size() - 1][1] = max(intervals[i][1], ans[ans.size() - 1][1]);
            } else {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};