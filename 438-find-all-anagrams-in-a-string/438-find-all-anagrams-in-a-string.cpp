class Solution {
public:
    vector<int> findAnagrams(string s, string pat) {
        int i = 0, j = 0;
        vector<int> ans;
        int n = s.size();
        int k = pat.size();
        map<char,int> m;

        for(auto ch: pat) {
            m[ch]++;
        }

        int count = m.size();

        while(j < n) {
            char ch = s[j];
            if(m.find(ch) != m.end()){
                m[ch]--;
                if(m[ch]==0){
                    count--;
                }
            }
            if(j < k){

            }
            else {
                if(m.find(s[i]) != m.end()){
                    if(m[s[i]] == 0){
                        count++;
                    }
                    m[s[i]]++;
                }
                i++;
            }
            if(count == 0){
                ans.push_back(i);
            }
            j++;
        }
        return ans;
    }
};