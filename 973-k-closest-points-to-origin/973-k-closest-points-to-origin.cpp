# define pip pair< int, vector<int> >
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pip> q;
        int i = 0;
        int n = points.size();
        int d;
        while(i<n){
            d = pow(points[i][0], 2) + pow(points[i][1], 2);
            q.push({d, points[i]});
            if(q.size() > k){
                q.pop();
            }
            i++;
        }
        while(!q.empty()){
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};