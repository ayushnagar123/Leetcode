class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> m;
        for(char c: t){
            m[c]++;
        }
        int count = m.size();
        int n = s.size();
        
        int i = 0, j = 0;
        int min = n+1;
        int ws;
        int s_ans = min;
        
        while(j<n){
            char c = s[j];
            ws = j-i+1;
            
            if(m.find(c)!=m.end()){
                m[c]--;
                if(m[c]==0){count--;}
                if(count==0 and min > ws){min = ws;s_ans = i;}
                while(count==0 and i<=j){
                    if(m.find(s[i])!=m.end()){
                        m[s[i]]++;
                        if(m[s[i]]==1){
                            count++;
                            i++;
                            break;
                        }
                    }
                    i++;
                    if(count==0){
                        ws = j - i + 1;
                        if(min > ws){
                            min = ws;
                            s_ans = i;
                        }
                    }
                }
            }
            j++;
        }
        string a = "";
        if(s_ans == (n+1)){
            return a;
        }
        for(int i = s_ans;i<s_ans+min;i++){
            a+=s[i];
        }
        return a;
    }
};