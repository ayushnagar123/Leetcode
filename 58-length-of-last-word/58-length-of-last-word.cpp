class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size()-1;
        int j = s.size()-1;
        while(s[i]==' '){
            i--;
            j--;
        }
        while(s[i]!=' ' && i>0){
            i--;
        }
        if(s[i]!=' ' && i == 0){
            return j - i + 1;
        }
        return j - i;
    }
};