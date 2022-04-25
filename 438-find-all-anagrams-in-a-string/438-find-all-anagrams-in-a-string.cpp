class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        map<char, int> m;
        for(char c: p){
            m[c]++;
        }
        int count = m.size();
        int i = 0, j = 0;
        int n = s.size();
        int k = p.size();
        while(j<n) {
            char c = s[j];
            if(j<k){
                if(m.find(c)!=m.end()){
                    m[c]--;
                    if(m[c]==0){
                        count--;
                    }
                    if(count==0){
                        ans.push_back(i);
                    }
                }
            }
            else {
                if(m.find(s[i])!=m.end()){
                    m[s[i]]++;
                    if(m[s[i]]==1){
                        count++;
                    }
                }
                i++;
                if(m.find(c)!=m.end()){
                    m[c]--;
                    if(m[c]==0){
                        count--;
                    }
                }
                if(count==0){
                    ans.push_back(i);
                }
            }
            j++;
        }
        return ans;
    }
};