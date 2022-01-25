class Solution {
public:
    string minWindow(string s, string p) {
        int i = 0, j = 0, mini= -1, minj = -1;
        int n = s.size();
        int min = n+1;
        map<char, int> m;
        for(auto ch: p){
            m[ch]++;
        }
        int count = m.size();
        int window_size;
        while(j<n){
            window_size = j - i + 1;
            if(m.find(s[j]) != m.end()){
                m[s[j]]--;
                if(m[s[j]]==0){
                    count--;
                }
            }
            if(count == 0){
                if(min > window_size) {
                    min = window_size;
                    mini = i;
                    minj = j;
                }
                while(count==0 && i <= j){
                    if(m.find(s[i]) != m.end()){
                        m[s[i]]++;
                        if(m[s[i]]==1){
                            count++;
                        }
                    }
                    if(min > (j - i + 1)) {
                        min = j - i +1;
                        mini = i;
                        minj = j;
                    }
                    i++;
                }
            }
            j++;
        }
        string ans="";
        if(mini !=-1){
            for(int k = mini;k<=minj;k++){
                ans+=s[k];
            }
        }
        return ans;
    }
};