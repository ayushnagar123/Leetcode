class Solution {
public:
    map<char, char> m = {
        {')','('},
        {'}','{'},
        {']','['},
    };
    bool isValid(string s) {
        int n = s.size();
        int i = 0;
        stack<char> st;
        while(i<n) {
            auto ch = s[i];
            if(m.find(ch)!=m.end()){
                if(st.empty() || st.top()!=m[ch]){
                    return false;
                }
                st.pop();
            } else if(ch=='(' || ch=='[' || ch=='{'){
                st.push(ch);
            }
            i++;
        }
        if(!st.empty()){
            return false;
        }
        return true;
    }
};