class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int maxDepth = 0;
        for(auto ch: s){
            if(ch=='('){
                st.push(ch);
            }
            else if(ch==')'){
                maxDepth = st.size() > maxDepth ? st.size() : maxDepth;
                st.pop();
            }
        }
        return maxDepth;
    }
};