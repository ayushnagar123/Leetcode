class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        map<char, int> m;
        int n = s.size();
        int ans = 0, ws = 0;
        while(j<n){
            m[s[j]]++;
            ws = j - i + 1;
            if(m.size() == ws){
                if(ans<ws){
                    ans = m.size();
                }
            }
            else if(m.size() < ws) {
                while(m.size() < ws and i!=j) {
                    m[s[i]]--;
                    if(m[s[i]]==0){
                        m.erase(s[i]);
                    }
                    i++;
                    ws = j - i + 1;
                }
                
            }
            j++;
        }
        if(ans < m.size()){
            ans = m.size();
        }
        return ans;
    }
};