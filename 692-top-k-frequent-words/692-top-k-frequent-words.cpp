# define pii pair< int, string >

class Compare {
    public:
    bool operator()(pii p1, pii p2){
        return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        int n = words.size();
        int i = 0;
        while(i<n){
            m[words[i]]++;
            i++;
        }
        vector<string> ans;
        priority_queue<pii, vector<pii>, Compare> q;
        for(auto p: m){
            q.push({p.second, p.first});
            if(q.size() > k){
                q.pop();
            }
        }
        while(!q.empty()){
            ans.insert(ans.begin(), q.top().second);
            q.pop();
        }
        
        return ans;
    }
};