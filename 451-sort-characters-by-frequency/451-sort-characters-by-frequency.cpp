# define pii pair< int, char >
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<int, int> m;
        int n = s.size();
        int i = 0;
        while(i<n){
            m[s[i]]++;
            i++;
        }
        priority_queue<pii> q;
        for(auto p: m){
            q.push({p.second, p.first});
        }
        i = 0;
        while(!q.empty()){
            for(int j = i;j< i + q.top().first;j++){
                s[j] = q.top().second;
            }
            i += q.top().first;
            q.pop();
        }
        return s;
    }
};