# define pii pair< int, int >
class Solution {
public:
    vector<int> topKFrequent(vector<int>& arr, int k) {
        unordered_map<int, int> m;
        int n = arr.size();
        int i = 0;
        while(i<n){
            m[arr[i]]++;
            i++;
        }
        vector<int> ans;
        priority_queue<pii, vector<pii>, greater<pii>> q;
        for(auto p: m){
            q.push({p.second, p.first});
            if(q.size() > k){
                q.pop();
            }
        }
        while(!q.empty()){
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};