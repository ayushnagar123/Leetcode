# define pii pair< int, int >
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pii> q;
        vector<int> ans;
        int i = 0;
        int n = arr.size();
        while(i<n){
            q.push({abs(x - arr[i]), arr[i]});
            if(q.size() > k){
                q.pop();
            }
            i++;
        }
        while(!q.empty()){
            ans.push_back(q.top().second);
            q.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};